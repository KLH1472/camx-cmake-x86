#ifndef _STUB_STRING_UTILS_H
#define _STUB_STRING_UTILS_H

#include <string.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline size_t g_strlcpy(char* dst, const char* src, size_t size) {
    if (size == 0) return strlen(src);
    size_t srclen = strlen(src);
    size_t copylen = srclen < size - 1 ? srclen : size - 1;
    memcpy(dst, src, copylen);
    dst[copylen] = '\0';
    return srclen;
}

static inline size_t g_strlcat(char* dst, const char* src, size_t size) {
    size_t dstlen = strnlen(dst, size);
    if (dstlen == size) return size + strlen(src);
    return dstlen + g_strlcpy(dst + dstlen, src, size - dstlen);
}

#ifdef __cplusplus
}
#endif

#endif // _STUB_STRING_UTILS_H
