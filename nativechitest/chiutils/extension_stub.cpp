// Stub implementations for ExtensionModule methods used by chiutils
#include "chxextensionmodule.h"
#include "chxusecaseutils.h"
#include "chi.h"

ExtensionModule* ExtensionModule::GetInstance() {
    static ExtensionModule instance;
    return &instance;
}

ExtensionModule::ExtensionModule() {}
ExtensionModule::~ExtensionModule() {}

CDKResult ExtensionModule::GetAvailableRequestKeys(
    UINT32 cameraId, UINT32* pEnabledKeys, UINT32 size, UINT32* pNumFilled) {
    (void)cameraId; (void)pEnabledKeys; (void)size;
    if (pNumFilled) *pNumFilled = 0;
    return CDKResultSuccess;
}

VOID ExtensionModule::GetMetadataOps(CHIMETADATAOPS* pOps) {
    if (pOps) {
        memset(pOps, 0, sizeof(CHIMETADATAOPS));
    }
}

BOOL UsecaseSelector::IsPreviewStream(const camera3_stream_t* pStream) {
    (void)pStream;
    return FALSE;
}

BOOL UsecaseSelector::IsVideoStream(const camera3_stream_t* pStream) {
    (void)pStream;
    return FALSE;
}

BOOL UsecaseSelector::IsYUVSnapshotStream(const camera3_stream_t* pStream) {
    (void)pStream;
    return FALSE;
}

BOOL UsecaseSelector::IsJPEGSnapshotStream(const camera3_stream_t* pStream) {
    (void)pStream;
    return FALSE;
}
