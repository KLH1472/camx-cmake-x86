// Provides definitions for global logging variables and ChiLog::LogSystem
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "chxdebugprint.h"

UINT32 g_enableChxLogs = 11;
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
    char buf[1024];
    int n = snprintf(buf, sizeof(buf), "%s %s:%d %s() ", module, pFileName, lineNum, pFuncName);
    if (n < 0) n = 0;
    if (n >= (int)sizeof(buf)) n = (int)sizeof(buf) - 1;
    va_list args;
    va_start(args, pFormat);
    vsnprintf(buf + n, sizeof(buf) - n, pFormat, args);
    va_end(args);

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    struct tm tm;
    localtime_r(&ts.tv_sec, &tm);
    fprintf(stderr, "%02d-%02d %02d:%02d:%02d.%06ld %5d %5ld %s %-8s: %s\n",
            tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec,
            ts.tv_nsec / 1000,
            getpid(), (long)syscall(SYS_gettid),
            pLoglevelchar, "Chi", buf);
}

CDK_VISIBILITY_PUBLIC VOID ChiLog::SetOfflineLoggerOps(CHIOFFLINELOGOPS* pOfflineLogOps)
{
    (void)pOfflineLogOps;
}
