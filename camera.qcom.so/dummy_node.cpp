#include "camxnode.h"
#include "camxhwfactory.h"
#include "camxsettingsmanager.h"
#include "camxcsl.h"
#include "camxincs.h"

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
        CAMX_UNREFERENCED_PARAM(pCreateOutputData);
        return CamxResultSuccess;
    }

private:
    DummyNode()  = default;
    virtual ~DummyNode() override = default;
};

class DummySettingsManager final : public SettingsManager
{
public:
    DummySettingsManager() : SettingsManager() {}
    virtual ~DummySettingsManager() override = default;
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
        return CAMX_NEW DummySettingsManager;
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
