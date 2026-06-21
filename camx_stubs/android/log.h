#ifndef STUB_ANDROID_LOG_H
#define STUB_ANDROID_LOG_H
#include <stdio.h>
#include <stdarg.h>
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

#endif
