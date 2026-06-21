/*
 * Android Log API Stub — x86 Linux 替代实现
 *
 * 1. 源代码中需要 __android_log_print，但 x86 没有 Android 的 liblog.so，
 *    所以本项目实现 stub 版，供源代码预处理时替换
 * 2. XLOGE/XLOGI/... 是本项目专用宏，带 file:line，独立于源代码的日志接口
 *
 * 三层架构:
 *   接口层（互不耦合）:
 *     XLOGE/XLOGI/...  — 本项目专用，带 file:line
 *     ALOGE/ALOGI/...  — Android API，由 stubs/log/log.h、camx_stubs/utils/Log.h 提供
 *     CAMX_LOG_*       — CamX 框架宏，经 Log::LogSystem -> __android_log_write
 *     CHX_LOG_*        — CHI 框架宏，经 ALOGE -> __android_log_print
 *   适配层:
 *     __android_log_print(prio, tag, fmt, ...)  — printf 风格，snprintf + __camx_log_emit
 *     __android_log_write(prio, tag, msg)       — 预格式化字符串，直接 __camx_log_emit
 *   输出层（统一）:
 *     __camx_log_emit(prio, tag, msg)  — 唯一出口，fprintf(stderr)
 *     格式: MM-DD HH:MM:SS.ffffff  PID  TID LEVEL TAG: msg
 *
 * 使用方式:
 *   #undef  LOG_TAG
 *   #define LOG_TAG "MyComponent"
 *   #include <android/log.h>
 *   XLOGI("message %d", 42);
 *   // 输出: 06-21 12:00:00.000000  1234  5678 I MyComponent: myfile.cpp:10 message 42
 */
#ifndef STUB_ANDROID_LOG_H
#define STUB_ANDROID_LOG_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

typedef enum {
    ANDROID_LOG_VERBOSE = 2,
    ANDROID_LOG_DEBUG,
    ANDROID_LOG_INFO,
    ANDROID_LOG_WARN,
    ANDROID_LOG_ERROR,
    ANDROID_LOG_FATAL
} android_LogPriority;

static inline void __camx_log_emit(int prio, const char* tag, const char* msg)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    struct tm tm;
    localtime_r(&ts.tv_sec, &tm);
    const char* lv;
    switch (prio) {
        case ANDROID_LOG_VERBOSE: lv = "V"; break;
        case ANDROID_LOG_DEBUG:   lv = "D"; break;
        case ANDROID_LOG_INFO:    lv = "I"; break;
        case ANDROID_LOG_WARN:    lv = "W"; break;
        case ANDROID_LOG_ERROR:   lv = "E"; break;
        case ANDROID_LOG_FATAL:   lv = "F"; break;
        default:                  lv = "?"; break;
    }
    fprintf(stderr, "%02d-%02d %02d:%02d:%02d.%06ld %5d %5ld %s %-8s: %s\n",
            tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec,
            ts.tv_nsec / 1000,
            getpid(), (long)syscall(SYS_gettid),
            lv, tag, msg);
}

#define __android_log_write(prio, tag, msg) __camx_log_emit(prio, tag, msg)

#define __android_log_print(prio, tag, ...) do {             \
    char _android_log_buf[1024];                            \
    snprintf(_android_log_buf, sizeof(_android_log_buf),    \
             __VA_ARGS__);                                  \
    __camx_log_emit(prio, tag, _android_log_buf);           \
} while (0)

#ifndef LOG_TAG
#define LOG_TAG "CamX"
#endif

#define XLOG_FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define XLOGE(fmt, ...) __android_log_print(ANDROID_LOG_ERROR,   LOG_TAG, "%s:%d %s() " fmt, XLOG_FILENAME, __LINE__, __func__, ##__VA_ARGS__)
#define XLOGW(fmt, ...) __android_log_print(ANDROID_LOG_WARN,    LOG_TAG, "%s:%d %s() " fmt, XLOG_FILENAME, __LINE__, __func__, ##__VA_ARGS__)
#define XLOGI(fmt, ...) __android_log_print(ANDROID_LOG_INFO,    LOG_TAG, "%s:%d %s() " fmt, XLOG_FILENAME, __LINE__, __func__, ##__VA_ARGS__)
#define XLOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG,   LOG_TAG, "%s:%d %s() " fmt, XLOG_FILENAME, __LINE__, __func__, ##__VA_ARGS__)
#define XLOGV(fmt, ...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "%s:%d %s() " fmt, XLOG_FILENAME, __LINE__, __func__, ##__VA_ARGS__)

#endif
