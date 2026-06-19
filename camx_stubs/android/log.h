#ifndef STUB_ANDROID_LOG_H
#define STUB_ANDROID_LOG_H
#include <stdio.h>
typedef enum { ANDROID_LOG_VERBOSE=2, ANDROID_LOG_DEBUG, ANDROID_LOG_INFO, ANDROID_LOG_WARN, ANDROID_LOG_ERROR, ANDROID_LOG_FATAL } android_LogPriority;
#define __android_log_print(prio, tag, ...) fprintf(stderr, __VA_ARGS__)
#define __android_log_write(prio, tag, msg) fputs(msg, stderr)
#endif
