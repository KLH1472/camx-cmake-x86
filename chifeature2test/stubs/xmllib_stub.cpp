#include "xmllib_parser.h"
#include <cstdlib>

extern "C" {

int32 xmllib_parser_parse(
    xmllib_encoding_e_type              encoding,
    xmllib_metainfo_s_type*             pMetaInfo,
    xmllib_parsetree_node_s_type**      ppParseTree,
    xmllib_error_e_type*                pError)
{
    (void)encoding;
    (void)pMetaInfo;
    // Stub: no XML parsing on Linux, return empty parse tree
    *ppParseTree = nullptr;
    *pError = XMLLIB_ERROR_MAX;
    return XMLLIB_ERROR;
}

void xmllib_parser_free(
    xmllib_memfree_f_type               memfree,
    xmllib_parsetree_node_s_type*       pParseTree)
{
    if (pParseTree && memfree) {
        memfree(pParseTree);
    }
}

}
