#include "camxnode.h"
#include "camxhwfactory.h"
#include "camxsettingsmanager.h"
#include "camxcsl.h"
#include "camxincs.h"
#undef  LOG_TAG
#define LOG_TAG "DummyNode"
#include <android/log.h>

CAMX_NAMESPACE_BEGIN

class DummyHwFactory;
HwFactory* CreateDummyHwFactory();

class DummyNode final : public Node
{
public:
    static Node* CreateDummyNode(
        const NodeCreateInputData* pCreateInputData,
        NodeCreateOutputData*      pCreateOutputData)
    {
        CAMX_UNREFERENCED_PARAM(pCreateInputData);
        CAMX_UNREFERENCED_PARAM(pCreateOutputData);
        return CAMX_NEW DummyNode;
    }

protected:
    virtual CamxResult ExecuteProcessRequest(
        ExecuteProcessRequestData* pExecuteProcessRequestData) override
    {
        XLOGD("ExecuteProcessRequest type=%u inst=%u seq=%d",
                Type(), InstanceID(),
                pExecuteProcessRequestData->pNodeProcessRequestData->processSequenceId);
        PerRequestActivePorts* pPorts = pExecuteProcessRequestData->pEnabledPortsInfo;
        if (pPorts != NULL)
        {
            for (UINT i = 0; i < pPorts->numOutputPorts; i++)
            {
                PerRequestOutputPortInfo& rOut = pPorts->pOutputPorts[i];
                if (rOut.phFence != NULL && *rOut.phFence != CSLInvalidFence)
                {
                    CSLFenceSignal(*rOut.phFence, CSLFenceResultSuccess);
                }
                if (rOut.phDelayedBufferFence != NULL && *rOut.phDelayedBufferFence != CSLInvalidFence)
                {
                    CSLFenceSignal(*rOut.phDelayedBufferFence, CSLFenceResultSuccess);
                }
            }
        }
        return CamxResultSuccess;
    }

    virtual CamxResult ProcessingNodeInitialize(
        const NodeCreateInputData* pCreateInputData,
        NodeCreateOutputData*      pCreateOutputData) override
    {
        CAMX_UNREFERENCED_PARAM(pCreateInputData);
        pCreateOutputData->maxInputPorts  = 16;
        pCreateOutputData->maxOutputPorts = 16;
        return CamxResultSuccess;
    }

    virtual CamxResult ProcessingNodeFinalizeInputRequirement(
        BufferNegotiationData* pBufferNegotiationData) override
    {
        if (NULL == pBufferNegotiationData)
        {
            return CamxResultEInvalidArg;
        }

        UINT32 optimalInputWidth  = 0;
        UINT32 optimalInputHeight = 0;
        UINT32 minInputWidth      = 0;
        UINT32 minInputHeight     = 0;
        UINT32 maxInputWidth      = 0;
        UINT32 maxInputHeight     = 0;

        for (UINT index = 0; index < pBufferNegotiationData->numOutputPortsNotified; index++)
        {
            OutputPortNegotiationData* pOutputPortData = &pBufferNegotiationData->pOutputPortNegotiationData[index];
            BufferRequirement*         pOutOptions     = &pOutputPortData->outputBufferRequirementOptions;

            UINT32 perPortOptW = 0, perPortOptH = 0;
            UINT32 perPortMinW = 0, perPortMinH = 0;
            UINT32 perPortMaxW = 0, perPortMaxH = 0;

            for (UINT childIdx = 0; childIdx < pOutputPortData->numInputPortsNotification; childIdx++)
            {
                BufferRequirement* pChild = &pOutputPortData->inputPortRequirement[childIdx];

                perPortMaxW = (0 == perPortMaxW) ? pChild->maxWidth :
                    Utils::MinUINT32(perPortMaxW, pChild->maxWidth);
                perPortMaxH = (0 == perPortMaxH) ? pChild->maxHeight :
                    Utils::MinUINT32(perPortMaxH, pChild->maxHeight);

                perPortOptW = Utils::MaxUINT32(perPortOptW, pChild->optimalWidth);
                perPortOptH = Utils::MaxUINT32(perPortOptH, pChild->optimalHeight);

                perPortMinW = Utils::MaxUINT32(perPortMinW, pChild->minWidth);
                perPortMinH = Utils::MaxUINT32(perPortMinH, pChild->minHeight);
            }

            if (perPortMaxW > 0 && perPortMaxH > 0)
            {
                perPortOptW = Utils::ClampUINT32(perPortOptW, perPortMinW, perPortMaxW);
                perPortOptH = Utils::ClampUINT32(perPortOptH, perPortMinH, perPortMaxH);
            }

            pOutOptions->optimalWidth  = perPortOptW;
            pOutOptions->optimalHeight = perPortOptH;
            pOutOptions->minWidth      = perPortMinW;
            pOutOptions->minHeight     = perPortMinH;
            pOutOptions->maxWidth      = perPortMaxW;
            pOutOptions->maxHeight     = perPortMaxH;

            maxInputWidth  = (0 == maxInputWidth) ? perPortMaxW :
                Utils::MinUINT32(maxInputWidth, perPortMaxW);
            maxInputHeight = (0 == maxInputHeight) ? perPortMaxH :
                Utils::MinUINT32(maxInputHeight, perPortMaxH);

            optimalInputWidth  = Utils::MaxUINT32(optimalInputWidth, perPortOptW);
            optimalInputHeight = Utils::MaxUINT32(optimalInputHeight, perPortOptH);

            minInputWidth  = Utils::MaxUINT32(minInputWidth, perPortMinW);
            minInputHeight = Utils::MaxUINT32(minInputHeight, perPortMinH);
        }

        if (0 == optimalInputWidth || 0 == optimalInputHeight)
        {
            return CamxResultEFailed;
        }

        optimalInputWidth  = Utils::ClampUINT32(optimalInputWidth, minInputWidth, maxInputWidth);
        optimalInputHeight = Utils::ClampUINT32(optimalInputHeight, minInputHeight, maxInputHeight);

        UINT32 numInputPorts = 0;
        UINT32 inputPortId[32];
        GetAllInputPortIds(&numInputPorts, &inputPortId[0]);

        pBufferNegotiationData->numInputPorts = numInputPorts;

        for (UINT input = 0; input < numInputPorts; input++)
        {
            pBufferNegotiationData->inputBufferOptions[input].nodeId     = Type();
            pBufferNegotiationData->inputBufferOptions[input].instanceId = InstanceID();
            pBufferNegotiationData->inputBufferOptions[input].portId     = inputPortId[input];

            BufferRequirement* pReq = &pBufferNegotiationData->inputBufferOptions[input].bufferRequirement;
            pReq->optimalWidth  = optimalInputWidth;
            pReq->optimalHeight = optimalInputHeight;
            pReq->minWidth      = minInputWidth;
            pReq->minHeight     = minInputHeight;
            pReq->maxWidth      = maxInputWidth;
            pReq->maxHeight     = maxInputHeight;
        }

        return CamxResultSuccess;
    }

    virtual VOID FinalizeBufferProperties(
        BufferNegotiationData* pBufferNegotiationData) override
    {
        if (NULL == pBufferNegotiationData)
        {
            return;
        }

        const ImageFormat* pInputFormat = NULL;
        if (pBufferNegotiationData->numInputPorts > 0 &&
            NULL != pBufferNegotiationData->pInputPortNegotiationData)
        {
            pInputFormat = pBufferNegotiationData->pInputPortNegotiationData[0].pImageFormat;
        }

        for (UINT index = 0; index < pBufferNegotiationData->numOutputPortsNotified; index++)
        {
            OutputPortNegotiationData* pOutputPortData = &pBufferNegotiationData->pOutputPortNegotiationData[index];
            BufferProperties* pFinal = pOutputPortData->pFinalOutputBufferProperties;

            if (IsSinkPortWithBuffer(pOutputPortData->outputPortIndex) ||
                IsNonSinkHALBufferOutput(pOutputPortData->outputPortIndex))
            {
                continue;
            }

            if (NULL != pFinal && NULL != pInputFormat)
            {
                pFinal->imageFormat.width  = pInputFormat->width;
                pFinal->imageFormat.height = pInputFormat->height;
            }
            else if (NULL != pFinal)
            {
                pFinal->imageFormat.width  = pOutputPortData->outputBufferRequirementOptions.optimalWidth;
                pFinal->imageFormat.height = pOutputPortData->outputBufferRequirementOptions.optimalHeight;
            }
        }
    }

private:
    DummyNode()  = default;
    virtual ~DummyNode() override = default;
};

class DummyHwFactory final : public HwFactory
{
public:
    static HwFactory* Create()
    {
        return CAMX_NEW DummyHwFactory;
    }

protected:
    virtual Node* HwCreateNode(
        const NodeCreateInputData* pCreateInputData,
        NodeCreateOutputData*      pCreateOutputData) const override
    {
        return DummyNode::CreateDummyNode(pCreateInputData, pCreateOutputData);
    }

    virtual SettingsManager* HwCreateSettingsManager() const override
    {
        return SettingsManager::Create(NULL);
    }

    virtual ~DummyHwFactory() override = default;

private:
    DummyHwFactory() = default;
};

HwFactory* CreateDummyHwFactory()
{
    return DummyHwFactory::Create();
}

CAMX_NAMESPACE_END
