#include <string.h>
#include <stddef.h>

extern "C" {

size_t g_strlcpy(char* dst, const char* src, size_t size) {
    if (size == 0) return strlen(src);
    size_t srclen = strlen(src);
    size_t copylen = srclen < size - 1 ? srclen : size - 1;
    memcpy(dst, src, copylen);
    dst[copylen] = '\0';
    return srclen;
}

size_t g_strlcat(char* dst, const char* src, size_t size) {
    size_t dstlen = strnlen(dst, size);
    if (dstlen == size) return size + strlen(src);
    return dstlen + g_strlcpy(dst + dstlen, src, size - dstlen);
}

}
