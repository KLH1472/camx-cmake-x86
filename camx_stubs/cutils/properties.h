#ifndef STUB_CUTILS_PROPERTIES_H
#define STUB_CUTILS_PROPERTIES_H
#include <string.h>
#define PROPERTY_VALUE_MAX 92
static inline int property_get(const char* key, char* value, const char* def) {
    if (def) { strncpy(value, def, PROPERTY_VALUE_MAX-1); value[PROPERTY_VALUE_MAX-1]=0; return strlen(value); }
    value[0]=0; return 0;
}
static inline int property_set(const char* key, const char* value) { (void)key; (void)value; return 0; }
static inline int property_list(void (*fn)(const char*, const char*, void*), void* cookie) { (void)fn; (void)cookie; return 0; }
#endif
