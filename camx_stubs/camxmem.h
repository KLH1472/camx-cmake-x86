#ifndef CAMXMEM_H
#define CAMXMEM_H

#include "camxdefs.h"
#include <stdlib.h>
#include <string.h>
#include <new>

CAMX_NAMESPACE_BEGIN

struct ImageDimensions { UINT32 widthPixels; UINT32 heightLines; };

CAMX_INLINE VOID* CamxCalloc(SIZE_T numBytes) { return calloc(1, numBytes); }
CAMX_INLINE VOID  CamxFree(VOID* pMem) { free(pMem); }

#define CAMX_CALLOC     CamX::CamxCalloc
#define CAMX_CALLOC_ALIGNED(sz, align)  CamX::CamxCalloc(sz)
#define CAMX_FREE(p)    do { CamX::CamxFree(const_cast<VOID*>(static_cast<const VOID*>(p))); } while(0)
#define CAMX_NEW         new
#define CAMX_DELETE       delete
#define CAMX_DELETE_ARRAY delete[]

#define CAMX_CALLOC_NO_SPY  CamX::CamxCalloc
#define CAMX_FREE_NO_SPY(p) do { CamX::CamxFree(const_cast<VOID*>(static_cast<const VOID*>(p))); } while(0)
#define CAMX_NEW_NO_SPY      new
#define CAMX_DELETE_NO_SPY   delete

CAMX_NAMESPACE_END

#endif
