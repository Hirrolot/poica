#ifndef POICA_LANG_PRIVATE_MAP_MAP_ITEM_H
#define POICA_P_LANGRIVATE_MAP_MAP_ITEM_H

#include <poica/lang/private/call_macro.h>
#include <poica/lang/private/map/is_empty.h>
#include <poica/lang/private/map/item.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define POICA_P_LANG_MAP_MAP_ITEM(mapping, aux_data, map, key)                 \
    BOOST_PP_IF(POICA_P_LANG_MAP_IS_EMPTY(map),                                \
                POICA_P_LANG_MAP_MAP_ITEM_EMPTY,                               \
                POICA_P_LANG_MAP_MAP_ITEM_NON_EMPTY)                           \
    (mapping, aux_data, map, key)

#define POICA_P_LANG_MAP_MAP_ITEM_EMPTY(_mapping, _aux_data, _map, _key)       \
    POICA_P_LANG_MAP()
#define POICA_P_LANG_MAP_MAP_ITEM_NON_EMPTY(mapping, aux_data, map, key)       \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_LANG_MAP_MAP_ITEM_VISIT, (mapping)(aux_data)(key), map)

#define POICA_P_LANG_MAP_MAP_ITEM_VISIT(_s, data, item)                        \
    POICA_P_LANG_CALL_MACRO_SEQ_ARGS(POICA_P_LANG_MAP_MAP_ITEM_VISIT_AUX,      \
                                     data((item)))

#define POICA_P_LANG_MAP_MAP_ITEM_VISIT_AUX(mapping, aux_data, key, item)      \
    BOOST_PP_IF(POICA_P_LANG_MAP_IS_KEY_OF_ITEM(key, item),                    \
                POICA_P_LANG_MAP_MAP_ITEM_REPLACE(mapping, aux_data, item),    \
                item)

#define POICA_P_LANG_MAP_MAP_ITEM_REPLACE(mapping, aux_data, item)             \
    POICA_P_LANG_MAP_ITEM(                                                     \
        POICA_P_LANG_MAP_ITEM_KEY(item),                                       \
        mapping(aux_data, POICA_P_LANG_MAP_ITEM_VALUE(item)))

#endif // POICA_LANG_PRIVATE_MAP_MAP_ITEM_H
