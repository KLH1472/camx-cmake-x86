#ifndef XMLLIB_PARSER_H
#define XMLLIB_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef int32_t int32;
typedef uint64_t UINT64;
typedef uint8_t uint8;

/* --- Constants --- */
#define XMLLIB_SUCCESS  0
#define XMLLIB_ERROR    (-1)

/* --- Encoding enum --- */
typedef enum {
    XMLLIB_ENCODING_UTF8 = 0
} xmllib_encoding_e_type;

/* --- Error enum --- */
typedef enum {
    XMLLIB_ERROR_MAX = 0
} xmllib_error_e_type;

/* --- Parse tree node type enum --- */
typedef enum {
    XMLLIB_PARSETREE_NODE_ELEMENT = 0,
    XMLLIB_PARSETREE_NODE_CONTENT = 1
} xmllib_parsetree_node_type_e_type;

/* --- Callback typedefs --- */
typedef void* (*xmllib_memalloc_f_type)(int32 size);
typedef void  (*xmllib_memfree_f_type)(void* membuffer);
typedef int32 (*xmllib_peekbytes_f_type)(struct xmllib_metainfo_s_type* pMetaInfo,
    int32 offset, int32 byteCount, uint8* pBuffer);
typedef int32 (*xmllib_getbytes_f_type)(struct xmllib_metainfo_s_type* pMetaInfo,
    int32 byteCount, char* pBuffer);

/* --- MetaInfo structure --- */
typedef struct xmllib_metainfo_s_type {
    void*                 xmltext;
    xmllib_memalloc_f_type  memalloc;
    xmllib_memfree_f_type   memfree;
    xmllib_peekbytes_f_type peekbytes;
    xmllib_getbytes_f_type  getbytes;
} xmllib_metainfo_s_type;

/* --- Parse tree node --- */
typedef struct xmllib_parsetree_node_s_type {
    xmllib_parsetree_node_type_e_type nodetype;
    struct xmllib_parsetree_node_s_type* sibling;
    union {
        struct {
            struct { int32 len; char* string; } name;
            struct xmllib_parsetree_node_s_type* child;
        } element;
        struct {
            int32 len;
            char* string;
        } content;
    } payload;
} xmllib_parsetree_node_s_type;

/* --- API functions --- */
int32 xmllib_parser_parse(
    xmllib_encoding_e_type              encoding,
    xmllib_metainfo_s_type*             pMetaInfo,
    xmllib_parsetree_node_s_type**      ppParseTree,
    xmllib_error_e_type*                pError);

void xmllib_parser_free(
    xmllib_memfree_f_type               memfree,
    xmllib_parsetree_node_s_type*       pParseTree);

#ifdef __cplusplus
}
#endif

#endif /* XMLLIB_PARSER_H */
