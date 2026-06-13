// Provides definitions for global logging variables and ChiLog::LogSystem
#include <stdio.h>
#include <stdarg.h>
#include "chxdebugprint.h"

UINT32 g_enableChxLogs = 3;
BOOL   g_enableSystemLog = FALSE;
BOOL   g_logRequestMapping = FALSE;

CDK_VISIBILITY_PUBLIC VOID ChiLog::LogSystem(
    const CHAR*     module,
    const CHAR*     pLoglevelchar,
    const CHAR*     pFileName,
    const CHAR*     pFuncName,
    INT32           lineNum,
    const CHAR*     pFormat,
    ...)
{
    (void)module; (void)pLoglevelchar; (void)pFuncName;
    va_list args;
    va_start(args, pFormat);
    fprintf(stderr, "[%s:%d] ", pFileName, lineNum);
    vfprintf(stderr, pFormat, args);
    fprintf(stderr, "\n");
    va_end(args);
}

CDK_VISIBILITY_PUBLIC VOID ChiLog::SetOfflineLoggerOps(CHIOFFLINELOGOPS* pOfflineLogOps)
{
    (void)pOfflineLogOps;
}
