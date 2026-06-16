#ifndef _STUB_SYNC_SYNC_H
#define _STUB_SYNC_SYNC_H

#include <sys/types.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Minimal sync stub
struct sync_merge_data {
    int fence_fd;
    char name[32];
    int flags;
    int reserved;
};

struct sync_fence_info_data {
    int status;
    int num_active_fences;
    char name[32];
};

static inline int sync_merge(const char* name, int fd1, int fd2) {
    (void)name; (void)fd1; (void)fd2;
    return -1;
}

static inline int sync_wait(int fd, int timeout) {
    (void)fd; (void)timeout;
    return 0;
}

static inline struct sync_fence_info_data* sync_fence_info(int fd) {
    (void)fd;
    return NULL;
}

static inline void sync_fence_info_free(struct sync_fence_info_data* info) {
    (void)info;
}

#ifdef __cplusplus
}
#endif

#endif // _STUB_SYNC_SYNC_H
