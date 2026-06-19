#ifndef STUB_UTILS_LOG_H
#define STUB_UTILS_LOG_H
#include <stdio.h>
#define ALOGD(...) do { fprintf(stderr, "D: " __VA_ARGS__); fprintf(stderr, "\n"); } while(0)
#define ALOGI(...) do { fprintf(stderr, "I: " __VA_ARGS__); fprintf(stderr, "\n"); } while(0)
#define ALOGW(...) do { fprintf(stderr, "W: " __VA_ARGS__); fprintf(stderr, "\n"); } while(0)
#define ALOGE(...) do { fprintf(stderr, "E: " __VA_ARGS__); fprintf(stderr, "\n"); } while(0)
#define ALOGV(...)
#define LOG_ALWAYS_FATAL_IF(cond, ...) do { if(cond) { fprintf(stderr, "FATAL: " __VA_ARGS__); abort(); } } while(0)
#endif
