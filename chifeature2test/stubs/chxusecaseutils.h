#ifndef CHXUSECASEUTILS_H
#define CHXUSECASEUTILS_H

#include "chiframework_types.h"
#include "chxextensionmodule.h"
#include <hardware/gralloc1.h>

enum class InputOutputType { NO_SPECIAL, YUV_OUT };

// ── LightweightDoublyLinkedList ──
class LightweightDoublyLinkedList
{
public:
    LightweightDoublyLinkedList() : m_pHead(nullptr), m_pTail(nullptr), m_count(0) {}
    VOID InsertToTail(LightweightDoublyLinkedListNode* pNode) {
        if (!pNode) return;
        pNode->pNext = nullptr;
        pNode->pPrev = m_pTail;
        if (m_pTail) m_pTail->pNext = pNode;
        m_pTail = pNode;
        if (!m_pHead) m_pHead = pNode;
        m_count++;
    }
    VOID InsertToHead(LightweightDoublyLinkedListNode* pNode) {
        if (!pNode) return;
        pNode->pPrev = nullptr;
        pNode->pNext = m_pHead;
        if (m_pHead) m_pHead->pPrev = pNode;
        m_pHead = pNode;
        if (!m_pTail) m_pTail = pNode;
        m_count++;
    }
    LightweightDoublyLinkedListNode* RemoveFromHead() {
        if (!m_pHead) return nullptr;
        LightweightDoublyLinkedListNode* pNode = m_pHead;
        RemoveNode(pNode);
        return pNode;
    }
    VOID RemoveNode(LightweightDoublyLinkedListNode* pNode) {
        if (!pNode) return;
        if (pNode->pPrev) pNode->pPrev->pNext = pNode->pNext;
        else m_pHead = pNode->pNext;
        if (pNode->pNext) pNode->pNext->pPrev = pNode->pPrev;
        else m_pTail = pNode->pPrev;
        pNode->pPrev = nullptr;
        pNode->pNext = nullptr;
        m_count--;
    }
    static LightweightDoublyLinkedListNode* NextNode(LightweightDoublyLinkedListNode* pNode) {
        return pNode ? pNode->pNext : nullptr;
    }
    LightweightDoublyLinkedListNode* Head() const { return m_pHead; }
    LightweightDoublyLinkedListNode* Tail() const { return m_pTail; }
    UINT NumNodes() const { return m_count; }
private:
    LightweightDoublyLinkedListNode* m_pHead;
    LightweightDoublyLinkedListNode* m_pTail;
    UINT m_count;
};

// ── ImageBuffer ──
class ImageBuffer
{
protected:
    buffer_handle_t* GetBufferHandle() { return nullptr; }
    CHIBUFFERTYPE GetBufferHandleType() { return HALGralloc; }
};

// ── CHIBufferManager ──
extern CHIBUFFERMANAGEROPS g_chiBufferManagerOps;

class CHIBufferManager
{
public:
    static CHIBufferManager* Create(const CHAR* pBufferManagerName, CHIBufferManagerCreateData* pCreateData) {
        if (!g_chiBufferManagerOps.pCreate) return nullptr;
        CHIBufferManager* pMgr = new CHIBufferManager();
        pMgr->m_hBufMgr = g_chiBufferManagerOps.pCreate(pBufferManagerName, pCreateData);
        if (!pMgr->m_hBufMgr) { delete pMgr; return nullptr; }
        return pMgr;
    }
    static UINT32 GetBufferSize(const CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; return 0; }
    static CDKResult CopyBuffer(const CHIBUFFERINFO* pSrcBufferInfo, CHIBUFFERINFO* pDstBufferInfo) { (void)pSrcBufferInfo; (void)pDstBufferInfo; return CDKResultSuccess; }
    static VOID SetPerfMode(CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; }
    static VOID* GetCPUAddress(const CHIBUFFERINFO* pBufferInfo, INT size) { (void)pBufferInfo; (void)size; return nullptr; }
    static VOID PutCPUAddress(const CHIBUFFERINFO* pBufferInfo, INT size, VOID* pVirtualAddress) { (void)pBufferInfo; (void)size; (void)pVirtualAddress; }
    static INT GetFileDescriptor(const CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; return -1; }
    static buffer_handle_t* GetGrallocHandle(const CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; return nullptr; }
    VOID Destroy() {
        if (m_hBufMgr && g_chiBufferManagerOps.pDestroy) g_chiBufferManagerOps.pDestroy(m_hBufMgr);
        delete this;
    }
    CHIBUFFERINFO GetImageBufferInfo() {
        CHIBUFFERINFO info = {};
        if (m_hBufMgr && g_chiBufferManagerOps.pGetImageBuffer) {
            info.phBuffer = g_chiBufferManagerOps.pGetImageBuffer(m_hBufMgr);
        }
        return info;
    }
    CDKResult AddReference(const CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; return CDKResultSuccess; }
    CDKResult ReleaseReference(const CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; return CDKResultSuccess; }
    UINT GetReference(const CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; return 0; }
    CDKResult Activate() {
        if (m_hBufMgr && g_chiBufferManagerOps.pActivate) return g_chiBufferManagerOps.pActivate(m_hBufMgr);
        return CDKResultSuccess;
    }
    CDKResult Deactivate(BOOL isPartialRelease) {
        if (m_hBufMgr && g_chiBufferManagerOps.pDeactivate) return g_chiBufferManagerOps.pDeactivate(m_hBufMgr, isPartialRelease);
        return CDKResultSuccess;
    }
    CDKResult BindBuffer(const CHIBUFFERINFO* pBufferInfo) { (void)pBufferInfo; return CDKResultSuccess; }
    CDKResult CacheOps(const CHIBUFFERINFO* pBufferInfo, BOOL invalidate, BOOL clean) { (void)pBufferInfo; (void)invalidate; (void)clean; return CDKResultSuccess; }

private:
    CHIBufferManager() : m_hBufMgr(nullptr) {}
    CHIBUFFERMANAGERHANDLE m_hBufMgr;
};

// ── UsecaseSelector ──
class UsecaseSelector
{
public:
    static VOID CalculateFovRectIFE(CHIRECT* fovRectIFE, const CHIRECT frameDimension, const CHIRECT activeArray) {}
    static UsecaseSelector* Create(const ExtensionModule* pExtModule) { return nullptr; }
    static UINT32 FindMaxResolutionCameraID(LogicalCameraInfo* pCameraInfo) { return 0; }
    static VOID getSensorDimension(const UINT32 cameraID, const camera3_stream_configuration_t* pStreamConfig,
        UINT32* sensorw, UINT32* sensorh, UINT32 downscaleFactor, UINT32 activeAspectRatio = 0) {}
    static CHISENSORMODEINFO* GetSensorModeInfo(const UINT32 cameraID,
        const camera3_stream_configuration_t* pStreamConfig, UINT32 downscaleFactor, UINT32 activeAspectRatio = 0) { return nullptr; }
    static ChiUsecase* DefaultMatchingUsecase(camera3_stream_configuration_t* pStreamConfig) { return nullptr; }
    static BOOL MFNRMatchingUsecase(const camera3_stream_configuration_t* pStreamConfig) { return FALSE; }
    static BOOL MFSRMatchingUsecase(const camera3_stream_configuration_t* pStreamConfig) { return FALSE; }
    static BOOL QuadCFAMatchingUsecase(const LogicalCameraInfo* pCamInfo,
        const camera3_stream_configuration_t* pStreamConfig) { return FALSE; }
    static BOOL IsQuadCFASensor(const LogicalCameraInfo* pCamInfo, CHIREMOSAICTYPE* pRemosaicType) { return FALSE; }
    static BOOL IsPreviewStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL IsVideoStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL IsJPEGSnapshotStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL IsYUVSnapshotStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL IsRawStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL IsRawInputStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL IsYUVInStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL IsYUVOutStream(const camera3_stream_t* pStream) { return FALSE; }
    static BOOL HasHeicSnapshotStream(const camera3_stream_configuration_t* pStreamConfig) { return FALSE; }
    static BOOL HasHeicSnapshotStream(const CHISTREAMCONFIGINFO* pStreamConfig) { return FALSE; }
    static CDKResult GetSnapshotStreamConfiguration(UINT numStreams, CHISTREAM** ppChiStreams,
        SnapshotStreamConfig& rSnapshotStreamConfig) { return CDKResultSuccess; }
    static CDKResult PruneUsecaseDescriptor(const ChiUsecase* const pUsecase, const UINT numPruneVariants,
        const PruneVariant* const pPruneVariants, ChiUsecase** ppPrunedUsecase) {
        (void)numPruneVariants; (void)pPruneVariants;
        if (ppPrunedUsecase) *ppPrunedUsecase = const_cast<ChiUsecase*>(pUsecase);
        return CDKResultSuccess;
    }
    static CDKResult PruneUsecaseByStreamConfig(const camera3_stream_configuration_t* pStreamConfig,
        const ChiUsecase* pUsecaseInputDescriptor, ChiUsecase** ppUsecaseOutputDescriptor) { return CDKResultSuccess; }
    static VariantGroup GetVariantGroup(const CHAR* pVariantName) { return 0; }
    static VariantType GetVariantType(const CHAR* pVariantName) { return 0; }
    static CDKResult FreeUsecaseDescriptor(ChiUsecase* pUsecase) { return CDKResultSuccess; }
    static ChiUsecase* CloneUsecase(const ChiUsecase* pSrcUsecase, UINT32 numDesc, UINT32* pDescIndex) {
        if (!pSrcUsecase || numDesc == 0 || !pDescIndex) return nullptr;
        ChiUsecase* pClone = static_cast<ChiUsecase*>(calloc(1, sizeof(ChiUsecase)));
        if (!pClone) return nullptr;
        *pClone = *pSrcUsecase;
        pClone->numPipelines = numDesc;
        pClone->pPipelineTargetCreateDesc = static_cast<ChiPipelineTargetCreateDescriptor*>(
            calloc(numDesc, sizeof(ChiPipelineTargetCreateDescriptor)));
        if (!pClone->pPipelineTargetCreateDesc) { free(pClone); return nullptr; }
        for (UINT32 i = 0; i < numDesc; i++) {
            pClone->pPipelineTargetCreateDesc[i] = pSrcUsecase->pPipelineTargetCreateDesc[pDescIndex[i]];
        }
        return pClone;
    }
    static VOID DestroyUsecase(ChiUsecase* pUsecase) {}
    static ChiStream GetFDOutStream() { return {}; }
    static VOID UpdateFDStream(FLOAT referenceAspectRatio) {}
    VOID Destroy() {}
    UsecaseId GetMatchingUsecase(const LogicalCameraInfo* pCamInfo,
        camera3_stream_configuration_t* pStreamConfig) { return UsecaseId::NoMatch; }
};

// ── UsecaseFactory ──
class UsecaseFactory
{
public:
    static UsecaseFactory* Create(const ExtensionModule* pExtModule) { return nullptr; }
    VOID Destroy() {}
    Usecase* CreateUsecaseObject(LogicalCameraInfo* pLogicalCameraInfo, UsecaseId usecaseId,
        camera3_stream_configuration_t* pStreamConfig) { return nullptr; }
};

#endif // CHXUSECASEUTILS_H
