#ifndef _STUB_LOG_H
#define _STUB_LOG_H

#include <stdio.h>

#ifndef ALOGE
#define ALOGE(fmt, ...) fprintf(stderr, "E [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif
#ifndef ALOGW
#define ALOGW(fmt, ...) fprintf(stderr, "W [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif
#ifndef ALOGI
#define ALOGI(fmt, ...) fprintf(stdout, "I [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif
#ifndef ALOGD
#define ALOGD(fmt, ...) fprintf(stdout, "D [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif
#ifndef ALOGV
#define ALOGV(fmt, ...) fprintf(stdout, "V [%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#endif // _STUB_LOG_H
