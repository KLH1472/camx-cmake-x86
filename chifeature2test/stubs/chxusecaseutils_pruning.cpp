#include "chxusecaseutils.h"
#include "chxutils.h"

#include <stdlib.h>
#include <string.h>

static CDKResult StringMapToIndex(const CHAR** const ppStringMap,
                                  const UINT         stringMapLength,
                                  const CHAR*  const pString,
                                  UINT&              rIndex)
{
    auto cmp = [](const VOID* p1, const VOID* p2) -> INT
    {
        return strcmp(static_cast<const CHAR*>(p1), *static_cast<const CHAR* const *>(p2));
    };
    CDKResult result = CDKResultSuccess;

    if (NULL == ppStringMap || NULL == pString)
    {
        result = CDKResultEInvalidArg;
    }
    else
    {
        VOID* pSearchResult = bsearch(pString, ppStringMap, stringMapLength, sizeof(CHAR*), cmp);
        if (NULL == pSearchResult)
        {
            result = CDKResultENoSuch;
        }
        else
        {
            rIndex = (static_cast<const CHAR * const *>(pSearchResult) - ppStringMap) + 1;
        }
    }
    return result;
}

static BOOL ShouldPrune(const PruneSettings* pPruneSettings,
                        const PruneSettings* pPruneProperties)
{
    BOOL shouldPrune = FALSE;

    if ((NULL == pPruneProperties) || (NULL == pPruneProperties->pVariants) ||
        (NULL == pPruneSettings)   || (NULL == pPruneSettings->pVariants))
    {
        shouldPrune = FALSE;
    }
    else
    {
        VariantGroup        currGroup         = EVariantGroup::InvalidVariantGroup;
        BOOL                hasFoundMatch     = TRUE;
        const PruneVariant* pPrunableElements = pPruneProperties->pVariants;
        for (UINT i = 0; i < pPruneProperties->numSettings; i++)
        {
            const PruneVariant* const pPruneableElement = &pPrunableElements[i];
            if (pPruneableElement->group != currGroup)
            {
                if (FALSE == hasFoundMatch)
                {
                    break;
                }
                else
                {
                    currGroup     = pPruneableElement->group;
                    hasFoundMatch = FALSE;
                }
            }
            else if (TRUE == hasFoundMatch)
            {
                continue;
            }

            for (UINT j = 0; j < pPruneSettings->numSettings; j++)
            {
                const PruneVariant* const pPruneSetting = &pPruneSettings->pVariants[j];
                if (pPruneSetting->group != pPruneableElement->group)
                {
                    continue;
                }
                else if (pPruneSetting->type == pPruneableElement->type)
                {
                    hasFoundMatch = TRUE;
                    break;
                }
            }
        }
        if (FALSE == hasFoundMatch)
        {
            shouldPrune = TRUE;
        }

    }
    return shouldPrune;
}

VariantGroup UsecaseSelector::GetVariantGroup(const CHAR* pVariantName)
{
    CDKResult    result;
    VariantGroup group;

    result = StringMapToIndex(g_stringMapVariantGroup, CHX_ARRAY_SIZE(g_stringMapVariantGroup), pVariantName, group);
    if (CDKResultSuccess != result)
    {
        CHX_LOG_ERROR("No VariantGroup %s exists [Error Code: %u]",
                      ((NULL == pVariantName) ? "NULL" : pVariantName),
                      result);
        group = EVariantGroup::InvalidVariantGroup;
    }
    return group;
}

VariantType UsecaseSelector::GetVariantType(const CHAR* pVariantName)
{
    CDKResult   result;
    VariantType type;

    result = StringMapToIndex(g_stringMapVariantType, CHX_ARRAY_SIZE(g_stringMapVariantType), pVariantName, type);
    if (CDKResultSuccess != result)
    {
        CHX_LOG_ERROR("No VariantType %s exists [Error Code: %u]",
                      ((NULL == pVariantName) ? "NULL" : pVariantName),
                      result);
        type = EVariantType::InvalidVariantType;
    }
    return type;
}

CDKResult UsecaseSelector::FreeUsecaseDescriptor(
    ChiUsecase* pUsecase)
{
    CDKResult result = CDKResultSuccess;
    if (NULL == pUsecase)
    {
        result = CDKResultEInvalidArg;
    }
    else if(FALSE == pUsecase->isOriginalDescriptor)
    {
        for (UINT j = 0; j < pUsecase->numPipelines; j++)
        {
            ChiPipelineTargetCreateDescriptor* pPipelineTargetDesc = &pUsecase->pPipelineTargetCreateDesc[j];
            ChiPipelineCreateDescriptor&       rPipelineCreateDesc = pPipelineTargetDesc->pipelineCreateDesc;
            for (UINT nodeIdx = 0; nodeIdx < rPipelineCreateDesc.numNodes; nodeIdx++)
            {
                CHINODE& rNode = rPipelineCreateDesc.pNodes[nodeIdx];
                CHX_FREE(rNode.nodeAllPorts.pInputPorts);
                CHX_FREE(rNode.nodeAllPorts.pOutputPorts);
            }
            for (UINT linkIdx = 0; linkIdx < rPipelineCreateDesc.numLinks; linkIdx++)
            {
                CHX_FREE(rPipelineCreateDesc.pLinks[linkIdx].pDestNodes);
            }
            CHX_FREE(rPipelineCreateDesc.pNodes);
            CHX_FREE(rPipelineCreateDesc.pLinks);
            CHX_FREE(pPipelineTargetDesc->sinkTarget.pTargetPortDesc);
            CHX_FREE(pPipelineTargetDesc->sourceTarget.pTargetPortDesc);
        }
        CHX_FREE(pUsecase->ppChiTargets);
        CHX_FREE(pUsecase->pPipelineTargetCreateDesc);
        CHX_FREE(pUsecase);
    }
    return result;
}

CDKResult UsecaseSelector::PruneUsecaseDescriptor(const ChiUsecase* const   pUsecase,
                                                  const UINT                numPruneVariants,
                                                  const PruneVariant* const pPruneVariants,
                                                  ChiUsecase**              ppPrunedUsecase)
{
    PruneSettings pruneSettings;
    pruneSettings.numSettings    = numPruneVariants;
    pruneSettings.pVariants      = pPruneVariants;
    CDKResult     result         = CDKResultSuccess;
    ChiUsecase*   pPrunedUsecase = NULL;

    auto AddTargetInfo = [&pPrunedUsecase](const ChiTargetPortDescriptor* pTargetCreateDesc,
                                           ChiTargetPortDescriptorInfo&   rTargetPrunedInfo)
    {
        BOOL                     isTargetInList    = FALSE;
        ChiTargetPortDescriptor& rTargetPrunedDesc = rTargetPrunedInfo.pTargetPortDesc[rTargetPrunedInfo.numTargets++];
        rTargetPrunedDesc                          = *pTargetCreateDesc;
        CHX_LOG_VERBOSE("Adding target info: %s [%u] <- %u:%u:%u",
                        rTargetPrunedDesc.pTargetName,
                        rTargetPrunedInfo.numTargets - 1,
                        pTargetCreateDesc->pNodePort[0].nodeId,
                        pTargetCreateDesc->pNodePort[0].nodeInstanceId,
                        pTargetCreateDesc->pNodePort[0].nodePortId);

        for (UINT targetListIdx = 0; targetListIdx < pPrunedUsecase->numTargets; targetListIdx++)
        {
            if (pPrunedUsecase->ppChiTargets[targetListIdx] == rTargetPrunedDesc.pTarget)
            {
                isTargetInList = TRUE;
                break;
            }
        }
        if (FALSE == isTargetInList)
        {
            pPrunedUsecase->ppChiTargets[pPrunedUsecase->numTargets++] = rTargetPrunedDesc.pTarget;
        }
    };

    auto UpdateTargetInfo = [&AddTargetInfo, &pUsecase, &result, &pruneSettings] (
        const ChiLinkNodeDescriptor&       rLinkNodeDesc,
        const ChiTargetPortDescriptorInfo& rTargetCreateInfo,
        ChiTargetPortDescriptorInfo&       rTargetPrunedInfo,
        const PruneSettings*               pPruneProperties)
    {
        if (CDKResultSuccess != result)
        {
            return;
        }
        auto IsSameDescriptor = [](const ChiLinkNodeDescriptor& rDescA,
                                   const ChiLinkNodeDescriptor& rDescB)
        {
            return ((rDescA.nodeId         == rDescB.nodeId) &&
                    (rDescA.nodeInstanceId == rDescB.nodeInstanceId) &&
                    (rDescA.nodePortId     == rDescB.nodePortId));
        };
        const ChiTargetPortDescriptor* pTargetCreateDesc = NULL;
        for (UINT i = 0; i < rTargetCreateInfo.numTargets; i++)
        {
            const ChiTargetPortDescriptor& rTargetCreateDesc = rTargetCreateInfo.pTargetPortDesc[i];
            if (TRUE == IsSameDescriptor(rTargetCreateDesc.pNodePort[0], rLinkNodeDesc))
            {
                BOOL acceptTarget = TRUE;
                if (NULL == pPruneProperties->pVariants)
                {
                    CHX_LOG_VERBOSE("%s no target prune properties found on link - Accept: %s",
                                    pUsecase->pUsecaseName,
                                    rTargetCreateDesc.pTargetName);
                }
                else if (NULL == pUsecase->pTargetPruneSettings)
                {
                    CHX_LOG_VERBOSE("%s has no target prune settings - Accept: %s",
                                    pUsecase->pUsecaseName,
                                    rTargetCreateDesc.pTargetName);
                }
                else
                {
                    acceptTarget = FALSE;
                    for (UINT j = 0; j < pUsecase->numTargets; j++)
                    {
                        if (rTargetCreateDesc.pTarget == pUsecase->ppChiTargets[j])
                        {
                            if (FALSE == ShouldPrune(&pruneSettings, &pUsecase->pTargetPruneSettings[j]))
                            {
                                acceptTarget = TRUE;
                                CHX_LOG_VERBOSE("Accepting target %u - %s", j, rTargetCreateDesc.pTargetName);
                            }
                            else
                            {
                                CHX_LOG_INFO("Rejecting target %u - %s", j, rTargetCreateDesc.pTargetName);
                            }
                            break;
                        }
                    }
                }
                if (TRUE == acceptTarget)
                {
                    pTargetCreateDesc = &rTargetCreateDesc;
                    break;
                }
            }
            else
            {
                CHX_LOG_VERBOSE("%s - %u:%u:%u does not match CreateDesc %u:%u:%u",
                                rTargetCreateDesc.pTargetName,
                                rTargetCreateDesc.pNodePort[0].nodeId,
                                rTargetCreateDesc.pNodePort[0].nodeInstanceId,
                                rTargetCreateDesc.pNodePort[0].nodePortId,
                                rLinkNodeDesc.nodeId,
                                rLinkNodeDesc.nodeInstanceId,
                                rLinkNodeDesc.nodePortId);
            }
        }

        if (NULL == pTargetCreateDesc)
        {
            result = CDKResultEInvalidState;
            CHX_LOG_ERROR("pTargetCreateDesc is null for link connecting to: %u:%u:%u",
                          rLinkNodeDesc.nodeId,
                          rLinkNodeDesc.nodeInstanceId,
                          rLinkNodeDesc.nodePortId);
        }
        else
        {
            AddTargetInfo(pTargetCreateDesc, rTargetPrunedInfo);
        }
    };

    if ((NULL == pUsecase) || ((NULL == pPruneVariants) && (numPruneVariants > 0)) || (NULL == ppPrunedUsecase))
    {
        result = CDKResultEInvalidArg;
        CHX_LOG_ERROR("Invalid arguments: pUsecase: %p pPruneVariants: %p ppPrunedUsecase: %p",
                      pUsecase, pPruneVariants, ppPrunedUsecase);
    }
    else
    {
        ChiPipelineTargetCreateDescriptor* pPrunedTargetCreateDesc;
        ChiTarget**                        ppPrunedChiTargets;
        pPrunedUsecase          = static_cast<ChiUsecase*>(CHX_CALLOC(1 * sizeof(ChiUsecase)));
        pPrunedTargetCreateDesc = static_cast<ChiPipelineTargetCreateDescriptor*>(
            CHX_CALLOC(pUsecase->numPipelines * sizeof(ChiPipelineTargetCreateDescriptor)));
        ppPrunedChiTargets      = static_cast<ChiTarget**>(CHX_CALLOC(pUsecase->numTargets * sizeof(ChiTarget*)));
        if ((NULL != pPrunedUsecase) && (NULL != pPrunedTargetCreateDesc) && (NULL != ppPrunedChiTargets))
        {
            pPrunedUsecase->pUsecaseName              = pUsecase->pUsecaseName;
            pPrunedUsecase->streamConfigMode          = pUsecase->streamConfigMode;
            pPrunedUsecase->numPipelines              = pUsecase->numPipelines;
            pPrunedUsecase->pPipelineTargetCreateDesc = pPrunedTargetCreateDesc;
            pPrunedUsecase->ppChiTargets              = ppPrunedChiTargets;
            *ppPrunedUsecase                          = pPrunedUsecase;
        }
        else
        {
            CHX_LOG_ERROR("Out of memory");
            result = CDKResultENoMemory;
        }
    }

    if (NULL != pUsecase)
    {
        for (UINT j = 0; j < pUsecase->numPipelines; j++)
        {
            if (CDKResultSuccess != result)
            {
                break;
            }

            constexpr UINT NODE_ID_SOURCE_BUFFER  = 4;
            constexpr UINT NODE_ID_SINK_BUFFER    = 2;
            constexpr UINT NODE_ID_SINK_NO_BUFFER = 3;

            const ChiPipelineTargetCreateDescriptor& rTargetCreateDesc = pUsecase->pPipelineTargetCreateDesc[j];
            if (NULL == pPrunedUsecase)
            {
                CHX_LOG("ERROR: no memory!");
                return  CDKResultEInvalidPointer;
            }

            ChiPipelineTargetCreateDescriptor&       rTargetPrunedDesc = pPrunedUsecase->pPipelineTargetCreateDesc[j];
            const ChiPipelineCreateDescriptor&       rCreateDesc       = rTargetCreateDesc.pipelineCreateDesc;
            ChiPipelineCreateDescriptor&             rPrunedDesc       = rTargetPrunedDesc.pipelineCreateDesc;

            auto GetNodeDesc = [](const ChiLinkNodeDescriptor& rCreateDesc, const ChiPipelineCreateDescriptor& rDesc) -> ChiNode*
            {
                ChiNode* pChiNode = NULL;
                for (UINT nodeIdx = 0; nodeIdx < rDesc.numNodes; nodeIdx++)
                {
                    ChiNode& rNodeDesc = rDesc.pNodes[nodeIdx];
                    if ((rCreateDesc.nodeId == rNodeDesc.nodeId) && (rCreateDesc.nodeInstanceId == rNodeDesc.nodeInstanceId))
                    {
                        pChiNode = &rNodeDesc;
                        break;
                    }
                }
                return pChiNode;
            };

            auto AddInputPortInfo = [] (CHINODEPORTS&                rDestPortInfo,
                                        const ChiLinkNodeDescriptor& rLinkDesc,
                                        const BOOL                   isInputStream) -> VOID
            {
                CHIINPUTPORTDESCRIPTOR& inputPortInfo = rDestPortInfo.pInputPorts[rDestPortInfo.numInputPorts++];
                inputPortInfo.portId                  = rLinkDesc.nodePortId;
                inputPortInfo.isInputStreamBuffer     = isInputStream;
                inputPortInfo.portSourceTypeId        = rLinkDesc.portSourceTypeId;
            };

            rPrunedDesc.isRealTime = rCreateDesc.isRealTime;
            if ((rCreateDesc.numNodes < 0) || (rCreateDesc.numLinks < 0))
            {
                CHX_LOG_ERROR("ERROR: numNodes or numLinks are less than zero");
                return CDKResultEInvalidArg;
            }
            rPrunedDesc.pNodes     = static_cast<CHINODE*>(CHX_CALLOC(rCreateDesc.numNodes * sizeof(CHINODE)));
            rPrunedDesc.pLinks     = static_cast<CHINODELINK*>(CHX_CALLOC(rCreateDesc.numLinks * sizeof(CHINODELINK)));

            rTargetPrunedDesc.pPipelineName              = rTargetCreateDesc.pPipelineName;
            rTargetPrunedDesc.sinkTarget.pTargetPortDesc = static_cast<ChiTargetPortDescriptor*>(
                CHX_CALLOC(rTargetCreateDesc.sinkTarget.numTargets * sizeof(ChiTargetPortDescriptor)));
            rTargetPrunedDesc.sourceTarget.pTargetPortDesc = static_cast<ChiTargetPortDescriptor*>(
                CHX_CALLOC(rTargetCreateDesc.sourceTarget.numTargets * sizeof(ChiTargetPortDescriptor)));

            if ((NULL == rPrunedDesc.pNodes) ||
                (NULL == rPrunedDesc.pLinks) ||
                (NULL == rTargetPrunedDesc.sinkTarget.pTargetPortDesc) ||
                (NULL == rTargetPrunedDesc.sourceTarget.pTargetPortDesc))
            {
                CHX_LOG_ERROR("Out of memory");
                result = CDKResultENoMemory;
                break;
            }
            for (UINT nodeIdx = 0; nodeIdx < rCreateDesc.numNodes; nodeIdx++)
            {
                const CHINODE& rNode = rCreateDesc.pNodes[nodeIdx];
                if (TRUE == ShouldPrune(&pruneSettings, &rNode.pruneProperties))
                {
                    CHX_LOG_INFO("%s - Pruning Node: %u:%u", rTargetCreateDesc.pPipelineName, rNode.nodeId, rNode.nodeInstanceId);
                    continue;
                }
                CHINODE&      rNewNode  = rPrunedDesc.pNodes[rPrunedDesc.numNodes++];
                CHINODEPORTS& rNewPorts = rNewNode.nodeAllPorts;

                rNewNode.nodeId          = rNode.nodeId;
                rNewNode.nodeInstanceId  = rNode.nodeInstanceId;
                rNewNode.pNodeProperties = rNode.pNodeProperties;
                rNewNode.numProperties   = rNode.numProperties;

                rNewPorts.pInputPorts  = static_cast<ChiInputPortDescriptor*>(
                    CHX_CALLOC(rNode.nodeAllPorts.numInputPorts * sizeof(ChiInputPortDescriptor)));
                rNewPorts.pOutputPorts = static_cast<ChiOutputPortDescriptor*>(
                    CHX_CALLOC(rNode.nodeAllPorts.numOutputPorts * sizeof(ChiOutputPortDescriptor)));
                if ((NULL == rNewPorts.pInputPorts) || (NULL == rNewPorts.pOutputPorts))
                {
                    CHX_LOG_ERROR("Out of memory");
                    result = CDKResultENoMemory;
                    break;
                }
            }
            if (CDKResultSuccess != result)
            {
                break;
            }
            for (UINT linkIdx = 0; linkIdx < rCreateDesc.numLinks; linkIdx++)
            {
                const CHINODELINK&           rLinkCreateDesc    = rCreateDesc.pLinks[linkIdx];
                CHINODELINK&                 rLinkPrunedDesc    = rPrunedDesc.pLinks[rPrunedDesc.numLinks];
                const ChiLinkNodeDescriptor& rSrcNodeCreateDesc = rLinkCreateDesc.srcNode;
                ChiNode*                     pSrcNode           = NULL;
                CHIOUTPUTPORTDESCRIPTOR*     pSrcOutputDesc     = NULL;
                if (NODE_ID_SOURCE_BUFFER != rSrcNodeCreateDesc.nodeId)
                {
                    pSrcNode = GetNodeDesc(rSrcNodeCreateDesc, rPrunedDesc);
                    if (NULL == pSrcNode)
                    {
                        CHX_LOG_VERBOSE("%s - Source Has been pruned: Src[%u:%u:%u]",
                                        rTargetCreateDesc.pPipelineName,
                                        rSrcNodeCreateDesc.nodeId,
                                        rSrcNodeCreateDesc.nodeInstanceId,
                                        rSrcNodeCreateDesc.nodePortId);
                        continue;
                    }
                    pSrcOutputDesc                   = &pSrcNode->nodeAllPorts.pOutputPorts[pSrcNode->nodeAllPorts.numOutputPorts];
                    pSrcOutputDesc->portId           = rSrcNodeCreateDesc.nodePortId;
                    pSrcOutputDesc->portSourceTypeId = rSrcNodeCreateDesc.portSourceTypeId;
                }
                for (UINT destIdx = 0; destIdx < rLinkCreateDesc.numDestNodes; destIdx++)
                {
                    const ChiLinkNodeDescriptor& rDestNodeCreateDesc = rLinkCreateDesc.pDestNodes[destIdx];
                    ChiNode*                     pDestNode           = NULL;

                    if (TRUE == ShouldPrune(&pruneSettings, &rDestNodeCreateDesc.pruneProperties))
                    {
                        CHX_LOG_INFO("%s - Pruning Dst Port: Src[%u:%u:%u] -> Dst[%u:%u:%u]",
                                    rTargetCreateDesc.pPipelineName,
                                    rSrcNodeCreateDesc.nodeId,
                                    rSrcNodeCreateDesc.nodeInstanceId,
                                    rSrcNodeCreateDesc.nodePortId,
                                    rDestNodeCreateDesc.nodeId,
                                    rDestNodeCreateDesc.nodeInstanceId,
                                    rDestNodeCreateDesc.nodePortId);
                        continue;
                    }
                    else
                    {
                        switch (rDestNodeCreateDesc.nodeId)
                        {
                            case NODE_ID_SINK_BUFFER:
                            case NODE_ID_SINK_NO_BUFFER:
                                break;
                            default:
                                pDestNode = GetNodeDesc(rDestNodeCreateDesc, rPrunedDesc);
                                if (NULL == pDestNode)
                                {
                                    CHX_LOG_VERBOSE("%s - Cannot Link: %u:%u:%u -> %u:%u:%u (DstNode was pruned)",
                                                    rTargetCreateDesc.pPipelineName,
                                                    rSrcNodeCreateDesc.nodeId,
                                                    rSrcNodeCreateDesc.nodeInstanceId,
                                                    rSrcNodeCreateDesc.nodePortId,
                                                    rDestNodeCreateDesc.nodeId,
                                                    rDestNodeCreateDesc.nodeInstanceId,
                                                    rDestNodeCreateDesc.nodePortId);
                                    continue;
                                }
                                break;
                        }
                    }

                    if (0 == rLinkPrunedDesc.numDestNodes)
                    {
                        rLinkPrunedDesc.pDestNodes = static_cast<ChiLinkNodeDescriptor*>(
                            CHX_CALLOC(rLinkCreateDesc.numDestNodes * sizeof(ChiLinkNodeDescriptor)));
                        if (NULL == rLinkPrunedDesc.pDestNodes)
                        {
                            CHX_LOG_ERROR("Out of memory");
                            result = CDKResultENoMemory;
                            break;
                        }
                    }

                    rLinkPrunedDesc.pDestNodes[rLinkPrunedDesc.numDestNodes++] = rDestNodeCreateDesc;

                    switch (rDestNodeCreateDesc.nodeId)
                    {
                        case NODE_ID_SINK_BUFFER:
                            UpdateTargetInfo(rSrcNodeCreateDesc,
                                            rTargetCreateDesc.sinkTarget,
                                            rTargetPrunedDesc.sinkTarget,
                                            &rDestNodeCreateDesc.pruneProperties);
                            break;
                        case NODE_ID_SINK_NO_BUFFER:
                            break;
                        default:
                            AddInputPortInfo(pDestNode->nodeAllPorts, rDestNodeCreateDesc, FALSE);
                            break;
                    }
                    if (NULL != pSrcOutputDesc)
                    {
                        switch (rDestNodeCreateDesc.nodeId)
                        {
                            case NODE_ID_SINK_BUFFER:
                                pSrcOutputDesc->isOutputStreamBuffer = TRUE;
                                pSrcOutputDesc->isSinkPort           = TRUE;
                                break;
                            case NODE_ID_SINK_NO_BUFFER:
                                pSrcOutputDesc->isSinkPort = TRUE;
                                break;
                            default:
                                break;
                        }
                    }
                }

                if ((CDKResultSuccess == result) && (rLinkPrunedDesc.numDestNodes > 0))
                {
                    rLinkPrunedDesc.srcNode          = rSrcNodeCreateDesc;
                    rLinkPrunedDesc.bufferProperties = rLinkCreateDesc.bufferProperties;
                    rLinkPrunedDesc.linkProperties   = rLinkCreateDesc.linkProperties;
                    rPrunedDesc.numLinks++;
                    if (NULL != pSrcNode)
                    {
                        for (UINT i = 0; i < pSrcNode->numProperties; i++)
                        {
                            const CHINODEPROPERTY& rProp = pSrcNode->pNodeProperties[i];
                            if ((11 == rProp.id) && ('1' == *(static_cast<const CHAR*>(rProp.pValue))))
                            {
                                const CHINODEPORTS& rCreatePorts = GetNodeDesc(rSrcNodeCreateDesc, rCreateDesc)->nodeAllPorts;

                                if (NULL == pSrcOutputDesc)
                                {
                                    CHX_LOG_ERROR("ERROR: no memory!");
                                    return CDKResultEInvalidPointer;
                                }

                                for (UINT portIdx = 0; portIdx < rCreatePorts.numOutputPorts; portIdx++)
                                {
                                    const CHIOUTPUTPORTDESCRIPTOR& rOutputPortDesc = rCreatePorts.pOutputPorts[portIdx];
                                    if (rOutputPortDesc.portId == pSrcOutputDesc->portId)
                                    {
                                        pSrcOutputDesc->numSourceIdsMapped = rOutputPortDesc.numSourceIdsMapped;
                                        pSrcOutputDesc->pMappedSourceIds   = rOutputPortDesc.pMappedSourceIds;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        pSrcNode->nodeAllPorts.numOutputPorts++;
                    }
                }
            }

            for (UINT sourceIdx = 0; sourceIdx < rTargetCreateDesc.sourceTarget.numTargets; sourceIdx++)
            {
                const ChiTargetPortDescriptor& rSrcBufferDesc = rTargetCreateDesc.sourceTarget.pTargetPortDesc[sourceIdx];
                ChiNode* const                 pDestNode      = GetNodeDesc(rSrcBufferDesc.pNodePort[0], rPrunedDesc);

                if (NULL != pDestNode)
                {
                    AddTargetInfo(&rSrcBufferDesc, rTargetPrunedDesc.sourceTarget);
                    AddInputPortInfo(pDestNode->nodeAllPorts, rSrcBufferDesc.pNodePort[0], TRUE);
                }
                else
                {
                    result = CDKResultEInvalidState;
                }
            }
            CHX_LOG_VERBOSE("%s - Create [Src: %u Sink: %u] Pruned [Src: %u Sink: %u]",
                            rTargetCreateDesc.pPipelineName,
                            rTargetCreateDesc.sourceTarget.numTargets,
                            rTargetCreateDesc.sinkTarget.numTargets,
                            rTargetPrunedDesc.sourceTarget.numTargets,
                            rTargetPrunedDesc.sinkTarget.numTargets);
        }
    }
    else
    {
        result = CDKResultEInvalidArg;
        CHX_LOG_ERROR("Invalid arguments: pUsecase: %p", pUsecase);
    }

    if (CDKResultSuccess != result)
    {
        CHX_LOG_ERROR("Error: %u", result);
    }

    return result;
}

ChiTarget* UsecaseSelector::ClonePipelineDesc(
    const ChiTarget *pSrcTarget)
{
    ChiTarget* pDstTarget = NULL;

    if (NULL != pSrcTarget)
    {
        pDstTarget = static_cast<ChiTarget*>(ChxUtils::Calloc(sizeof(ChiTarget)));
        if (NULL != pDstTarget)
        {
            ChxUtils::Memcpy(pDstTarget, pSrcTarget, sizeof(ChiTarget));

            pDstTarget->pBufferFormats = static_cast<ChiBufferFormat*>(
                ChxUtils::Calloc(sizeof(ChiBufferFormat) * pSrcTarget->numFormats));

            if (NULL != pDstTarget->pBufferFormats)
            {
                ChxUtils::Memcpy(pDstTarget->pBufferFormats, pSrcTarget->pBufferFormats,
                    (sizeof(ChiBufferFormat) * pSrcTarget->numFormats));
            }
            else
            {
                CHX_LOG_ERROR("pDstTarget->pBufferFormats allocation failed!");
                ChxUtils::Free(pDstTarget);
                pDstTarget = NULL;
            }
        }
    }

    return pDstTarget;
}

ChiUsecase* UsecaseSelector::CloneUsecase(
    const ChiUsecase *pSrcUsecase, UINT32 numDesc, UINT32 *pDescIndex)
{
    ChiUsecase* pDstUsecase = NULL;
    INT32      result       = 0;
    CHX_ASSERT(NULL != pSrcUsecase);

    if (NULL != pSrcUsecase)
    {
        pDstUsecase = static_cast<ChiUsecase*>(ChxUtils::Calloc(sizeof(ChiUsecase)));

        if (NULL != pDstUsecase)
        {
            pDstUsecase->pUsecaseName      = pSrcUsecase->pUsecaseName;
            pDstUsecase->streamConfigMode  = pSrcUsecase->streamConfigMode;
            pDstUsecase->numPipelines      = 0;
            pDstUsecase->numTargets        = 0;

            if ((0 != numDesc) && (NULL != pDescIndex))
            {
                pDstUsecase->pPipelineTargetCreateDesc = static_cast<ChiPipelineTargetCreateDescriptor*>(ChxUtils::Calloc(
                    sizeof(ChiPipelineTargetCreateDescriptor) * numDesc));

                if (NULL != pDstUsecase->pPipelineTargetCreateDesc)
                {
                    const ChiPipelineTargetCreateDescriptor* pSrcDesc = pSrcUsecase->pPipelineTargetCreateDesc;
                    ChiPipelineTargetCreateDescriptor*       pDstDesc = pDstUsecase->pPipelineTargetCreateDesc;

                    if (NULL != pDstDesc)
                    {
                        UINT32 numTargets = 0;

                        for (UINT32 descIndex = 0; descIndex < numDesc; descIndex++)
                        {
                            UINT32 currentIndex = pDescIndex[descIndex];
                            if (currentIndex < pSrcUsecase->numPipelines)
                            {
                                result = ClonePipelineDesc(&pSrcDesc[currentIndex],
                                                           &pDstDesc[pDstUsecase->numPipelines]);

                                if (CDKResultSuccess != result)
                                {
                                    CHX_LOG_ERROR("Pipeline descriptor clone failed, descIndex=%d, currentIndex=%d",
                                        descIndex, currentIndex);
                                    break;
                                }

                                numTargets += pDstDesc[pDstUsecase->numPipelines].sinkTarget.numTargets;
                                numTargets += pDstDesc[pDstUsecase->numPipelines].sourceTarget.numTargets;
                                pDstUsecase->numPipelines++;
                            }
                        }

                        if (CDKResultSuccess == result)
                        {
                            if (NULL != pSrcUsecase->pTargetPruneSettings)
                            {
                                pDstUsecase->pTargetPruneSettings = static_cast<const PruneSettings*>(ChxUtils::Calloc(
                                    numTargets * sizeof(PruneSettings)));
                                if (NULL == pDstUsecase->pTargetPruneSettings)
                                {
                                    CHX_LOG_ERROR("Out of memory!");
                                    result = CDKResultENoMemory;
                                }
                            }
                        }
                        if (CDKResultSuccess == result)
                        {
                            pDstUsecase->numTargets   = 0;
                            pDstUsecase->ppChiTargets = static_cast<ChiTarget**>(ChxUtils::Calloc(
                                sizeof(ChiTarget*) * numTargets));

                            if (NULL != pDstUsecase->ppChiTargets)
                            {
                                for (UINT32 descIndex = 0; descIndex < pDstUsecase->numPipelines; descIndex++)
                                {
                                    const ChiTargetPortDescriptorInfo* pSrcInfo  = &pSrcDesc[pDescIndex[descIndex]].sinkTarget;
                                    ChiTargetPortDescriptorInfo*       pDescInfo = &pDstDesc[descIndex].sinkTarget;
                                    for (UINT32 i = 0; i < pDescInfo->numTargets; i++)
                                    {
                                        if (NULL != pDescInfo->pTargetPortDesc[i].pTarget)
                                        {
                                            if ((NULL != pSrcUsecase->pTargetPruneSettings) &&
                                                (NULL != pDstUsecase->pTargetPruneSettings))
                                            {
                                                PruneSettings* pDstSettings = const_cast<PruneSettings*>(
                                                    &pDstUsecase->pTargetPruneSettings[pDstUsecase->numTargets]);
                                                for (UINT j = 0; j < pSrcUsecase->numTargets; j++)
                                                {
                                                    if (pSrcInfo->pTargetPortDesc[i].pTarget == pSrcUsecase->ppChiTargets[j])
                                                    {
                                                        *pDstSettings = pSrcUsecase->pTargetPruneSettings[j];
                                                        break;
                                                    }
                                                }
                                            }
                                            pDstUsecase->ppChiTargets[pDstUsecase->numTargets++] =
                                                pDescInfo->pTargetPortDesc[i].pTarget;
                                        }
                                    }

                                    pDescInfo = &pDstDesc[descIndex].sourceTarget;
                                    for (UINT32 i = 0; i < pDescInfo->numTargets; i++)
                                    {
                                        if (NULL != pDescInfo->pTargetPortDesc[i].pTarget)
                                        {
                                            pDstUsecase->ppChiTargets[pDstUsecase->numTargets++] =
                                                pDescInfo->pTargetPortDesc[i].pTarget;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                CHX_LOG_ERROR("pDstUsecase->ppChiTargets allocation failed! numTargets=%d", numTargets);
                            }
                        }
                    }
                }
                else
                {
                    CHX_LOG_ERROR("pDstUsecase->pPipelineTargetCreateDesc allocation failed! numDesc=%d", numDesc);
                }
            }
            else
            {
                CHX_LOG_WARN("No pipeline descriptor need to be cloned!");
            }
        }
        else
        {
            CHX_LOG_ERROR("pDstUsecase allocation failed!");
        }
    }
    else
    {
        CHX_LOG_ERROR("Invalid arguments! pSrcUsecase=%p, numDesc=%d, pDescIndex=%p",
            pSrcUsecase, numDesc, pDescIndex);
    }
    return pDstUsecase;
}

CDKResult UsecaseSelector::ClonePipelineDesc(
    const ChiPipelineTargetCreateDescriptor* pSrcDesc,
    ChiPipelineTargetCreateDescriptor*       pDstDesc)
{
    CDKResult result = CDKResultSuccess;

    CHX_ASSERT(NULL != pSrcDesc);
    CHX_ASSERT(NULL != pDstDesc);

    if ((NULL != pDstDesc) && (NULL != pSrcDesc))
    {
        ChxUtils::Memcpy(pDstDesc, pSrcDesc, sizeof(ChiPipelineTargetCreateDescriptor));

        const ChiTargetPortDescriptorInfo* pSrcTargetDescInfo  = &pSrcDesc->sinkTarget;
        ChiTargetPortDescriptorInfo* pDstTargetDescInfo        = &pDstDesc->sinkTarget;

        if ((0 != pSrcTargetDescInfo->numTargets) && (NULL != pSrcTargetDescInfo->pTargetPortDesc))
        {
            pDstTargetDescInfo->pTargetPortDesc = NULL;
            pDstTargetDescInfo->pTargetPortDesc = static_cast<ChiTargetPortDescriptor*>(
                    ChxUtils::Calloc(sizeof(ChiTargetPortDescriptor) * pSrcTargetDescInfo->numTargets));
            if (NULL != pDstTargetDescInfo->pTargetPortDesc)
            {
                ChxUtils::Memcpy(pDstTargetDescInfo->pTargetPortDesc, pSrcTargetDescInfo->pTargetPortDesc,
                        sizeof(ChiTargetPortDescriptor) * pSrcTargetDescInfo->numTargets);
                for(UINT32 i = 0; i < pSrcTargetDescInfo->numTargets; i++)
                {
                    pDstTargetDescInfo->pTargetPortDesc[i].pTarget = ClonePipelineDesc(
                        pSrcTargetDescInfo->pTargetPortDesc[i].pTarget);

                    if (NULL == pDstTargetDescInfo->pTargetPortDesc[i].pTarget)
                    {
                        CHX_LOG_ERROR("Failed to Clone pipeline = %s numSinkTargets = %d sinkTarget = %d",
                                pSrcDesc->pPipelineName, pSrcTargetDescInfo->numTargets, i);
                        result = CDKResultEFailed;
                        break;
                    }
                }
            }
            else
            {
                CHX_LOG_ERROR("Failed to Clone pipeline = %s numSinkTargets = %d",
                                pSrcDesc->pPipelineName, pSrcTargetDescInfo->numTargets);
                result = CDKResultENoMemory;
            }
        }

        if (CDKResultSuccess == result)
        {
            pSrcTargetDescInfo  = &pSrcDesc->sourceTarget;
            pDstTargetDescInfo  = &pDstDesc->sourceTarget;
            if ((pSrcTargetDescInfo->numTargets != 0) && (NULL != pSrcTargetDescInfo->pTargetPortDesc))
            {
                pDstTargetDescInfo->pTargetPortDesc = NULL;
                pDstTargetDescInfo->pTargetPortDesc = static_cast<ChiTargetPortDescriptor*>(
                        ChxUtils::Calloc(sizeof(ChiTargetPortDescriptor) * pSrcTargetDescInfo->numTargets));
                if (NULL != pDstTargetDescInfo->pTargetPortDesc)
                {
                    ChxUtils::Memcpy(pDstTargetDescInfo->pTargetPortDesc, pSrcTargetDescInfo->pTargetPortDesc,
                            sizeof(ChiTargetPortDescriptor) * pSrcTargetDescInfo->numTargets);
                    for(UINT32 i = 0; i < pSrcTargetDescInfo->numTargets; i++)
                    {
                        pDstTargetDescInfo->pTargetPortDesc[i].pTarget = ClonePipelineDesc(
                            pSrcTargetDescInfo->pTargetPortDesc[i].pTarget);
                        if (NULL == pDstTargetDescInfo->pTargetPortDesc[i].pTarget)
                        {
                            CHX_LOG_ERROR("Failed to Clone pipeline = %s numSourceTargets = %d sourceTarget = %d",
                                    pSrcDesc->pPipelineName, pSrcTargetDescInfo->numTargets, i);
                            result = CDKResultEFailed;
                            break;
                        }
                    }
                }
                else
                {
                    CHX_LOG_ERROR("Failed to Clone pipeline = %s numSinkTargets = %d",
                                    pSrcDesc->pPipelineName, pSrcTargetDescInfo->numTargets);
                    result = CDKResultENoMemory;
                }
            }
        }

        if (CDKResultSuccess == result)
        {
            const ChiPipelineCreateDescriptor* pSrcCreateDesc = &pSrcDesc->pipelineCreateDesc;
            ChiPipelineCreateDescriptor* pDstCreateDesc       = &pDstDesc->pipelineCreateDesc;
            CHX_ASSERT(NULL != pSrcCreateDesc->pNodes);
            if ((pSrcCreateDesc->numNodes != 0) && (NULL != pSrcCreateDesc->pNodes))
            {
                pDstCreateDesc->pNodes = NULL;
                pDstCreateDesc->pNodes = static_cast<CHINODE*>(ChxUtils::Calloc(sizeof(CHINODE) *
                    pSrcCreateDesc->numNodes));
                if (NULL != pDstCreateDesc->pNodes)
                {
                    ChxUtils::Memcpy(pDstCreateDesc->pNodes, pSrcCreateDesc->pNodes,
                        sizeof(CHINODE) * pSrcCreateDesc->numNodes);

                    for (UINT32 i = 0; i < pSrcCreateDesc->numNodes; i++)
                    {
                        CHINODEPORTS* pSrcPortDesc = &pSrcCreateDesc->pNodes[i].nodeAllPorts;
                        CHINODEPORTS* pDstPortDesc = &pDstCreateDesc->pNodes[i].nodeAllPorts;
                        if ((pSrcPortDesc->numInputPorts != 0) && (NULL != pSrcPortDesc->pInputPorts))
                        {
                            pDstPortDesc->pInputPorts = NULL;
                            pDstPortDesc->pInputPorts = static_cast<CHIINPUTPORTDESCRIPTOR*>(ChxUtils::Calloc(
                                sizeof(CHIINPUTPORTDESCRIPTOR) * pSrcPortDesc->numInputPorts));

                            if (NULL != pDstPortDesc->pInputPorts)
                            {
                                ChxUtils::Memcpy(pDstPortDesc->pInputPorts, pSrcPortDesc->pInputPorts,
                                    sizeof(CHIINPUTPORTDESCRIPTOR) * pSrcPortDesc->numInputPorts);
                            }
                            else
                            {
                                CHX_LOG_ERROR("Failed to Clone pipeline = %s Node = %d numInputPorts = %d",
                                    pSrcDesc->pPipelineName, i, pSrcPortDesc->numInputPorts);
                                result = CDKResultENoMemory;
                                break;
                            }
                        }

                        if ((pSrcPortDesc->numOutputPorts != 0) && (NULL != pSrcPortDesc->pOutputPorts))
                        {
                            pDstPortDesc->pOutputPorts = NULL;
                            pDstPortDesc->pOutputPorts = static_cast<CHIOUTPUTPORTDESCRIPTOR*>(ChxUtils::Calloc(
                                sizeof(CHIOUTPUTPORTDESCRIPTOR) * pSrcPortDesc->numOutputPorts));
                            if (NULL != pDstPortDesc->pOutputPorts)
                            {
                                ChxUtils::Memcpy(pDstPortDesc->pOutputPorts, pSrcPortDesc->pOutputPorts,
                                    sizeof(CHIOUTPUTPORTDESCRIPTOR) * pSrcPortDesc->numOutputPorts);
                            }
                            else
                            {
                                CHX_LOG_ERROR("Failed to Clone pipeline = %s Node = %d numOutputPorts = %d",
                                    pSrcDesc->pPipelineName, i, pSrcPortDesc->numOutputPorts);
                                result = CDKResultENoMemory;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    CHX_LOG_ERROR("Failed to Clone pipeline = %s numNodes = %d",
                        pSrcDesc->pPipelineName, pSrcCreateDesc->numNodes);
                    result = CDKResultENoMemory;
                }
            }

            if (CDKResultSuccess == result)
            {
                CHX_ASSERT(NULL != pSrcCreateDesc->pLinks);
                if ((pSrcCreateDesc->numLinks != 0) && (NULL != pSrcCreateDesc->pLinks))
                {
                    pDstCreateDesc->pLinks = NULL;
                    pDstCreateDesc->pLinks = static_cast<CHINODELINK*>(ChxUtils::Calloc(sizeof(CHINODELINK) *
                        pSrcCreateDesc->numLinks));
                    if (NULL != pDstCreateDesc->pLinks)
                    {
                        ChxUtils::Memcpy(pDstCreateDesc->pLinks, pSrcCreateDesc->pLinks,
                            sizeof(CHINODELINK) * pDstCreateDesc->numLinks);
                    }
                    else
                    {
                        CHX_LOG_ERROR("Failed to allocate and clone links pipeline = %s numLinks = %d",
                            pSrcDesc->pPipelineName, pSrcCreateDesc->numLinks);
                        result = CDKResultENoMemory;
                    }
                }
            }
        }
    }
    else
    {
        CHX_LOG_ERROR("Failed to Clone PipelineDesc = %p", pSrcDesc);
        result = CDKResultEInvalidArg;
    }

    return result;
}

VOID UsecaseSelector::DestroyPipelineDesc(ChiTarget *pTarget)
{
    if (NULL != pTarget)
    {
        if (NULL != pTarget->pBufferFormats)
        {
            ChxUtils::Free(pTarget->pBufferFormats);
            pTarget->pBufferFormats = NULL;
        }
        ChxUtils::Free(pTarget);
        pTarget = NULL;
    }
}

VOID UsecaseSelector::DestroyPipelineDesc(ChiPipelineTargetCreateDescriptor *pDesc)
{
    CHX_ASSERT(NULL != pDesc);

    if (NULL != pDesc)
    {
        ChiTargetPortDescriptorInfo* pTargetDescInfo  = &pDesc->sinkTarget;

        if ((NULL != pTargetDescInfo) && (NULL != pTargetDescInfo->pTargetPortDesc))
        {
            for(UINT32 i = 0; i < pTargetDescInfo->numTargets; i++)
            {
                DestroyPipelineDesc(pTargetDescInfo->pTargetPortDesc[i].pTarget);
            }

            pTargetDescInfo->numTargets = 0;
            ChxUtils::Free(pTargetDescInfo->pTargetPortDesc);
            pTargetDescInfo->pTargetPortDesc = NULL;
        }

        pTargetDescInfo  = &pDesc->sourceTarget;
        if ((NULL != pTargetDescInfo) && (NULL != pTargetDescInfo->pTargetPortDesc))
        {
            for(UINT32 i = 0; i < pTargetDescInfo->numTargets; i++)
            {
                DestroyPipelineDesc(pTargetDescInfo->pTargetPortDesc[i].pTarget);
            }

            pTargetDescInfo->numTargets = 0;
            ChxUtils::Free(pTargetDescInfo->pTargetPortDesc);
            pTargetDescInfo->pTargetPortDesc = NULL;
        }

        ChiPipelineCreateDescriptor* pCreateDesc = &pDesc->pipelineCreateDesc;
        if ((NULL != pCreateDesc) && (NULL != pCreateDesc->pNodes))
        {
            for (UINT32 i = 0; i < pCreateDesc->numNodes; i++)
            {
                if (NULL != pCreateDesc->pNodes[i].nodeAllPorts.pInputPorts)
                {
                    ChxUtils::Free(pCreateDesc->pNodes[i].nodeAllPorts.pInputPorts);
                    pCreateDesc->pNodes[i].nodeAllPorts.pInputPorts = NULL;
                }

                if (NULL != pCreateDesc->pNodes[i].nodeAllPorts.pOutputPorts)
                {
                    ChxUtils::Free(pCreateDesc->pNodes[i].nodeAllPorts.pOutputPorts);
                    pCreateDesc->pNodes[i].nodeAllPorts.pOutputPorts = NULL;
                }
            }
            ChxUtils::Free(pCreateDesc->pNodes);
            pCreateDesc->pNodes = NULL;
        }

        if (NULL != pCreateDesc->pLinks)
        {
            ChxUtils::Free(pCreateDesc->pLinks);
            pCreateDesc->pLinks = NULL;
        }
    }
}

VOID UsecaseSelector::DestroyUsecase(ChiUsecase *pUsecase)
{
    CHX_ASSERT(NULL != pUsecase);

    if (NULL != pUsecase)
    {
        if (NULL != (pUsecase->ppChiTargets))
        {
            ChxUtils::Free(pUsecase->ppChiTargets);
            pUsecase->ppChiTargets = NULL;
        }
        if (NULL != pUsecase->pTargetPruneSettings)
        {
            ChxUtils::Free(const_cast<PruneSettings*>(pUsecase->pTargetPruneSettings));
            pUsecase->pTargetPruneSettings = NULL;
        }
        if (NULL != pUsecase->pPipelineTargetCreateDesc)
        {
            for (UINT32 descIndex = 0; descIndex < pUsecase->numPipelines; descIndex++)
            {
                DestroyPipelineDesc(&pUsecase->pPipelineTargetCreateDesc[descIndex]);
            }
            ChxUtils::Free(pUsecase->pPipelineTargetCreateDesc);
            pUsecase->pPipelineTargetCreateDesc = NULL;
        }

        ChxUtils::Free(pUsecase);
        pUsecase = NULL;
    }
}
