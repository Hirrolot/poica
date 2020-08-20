#ifndef POICA_LANG_GADT_ORDER_ENTITIES_TO_MAP_H
#define POICA_LANG_GADT_ORDER_ENTITIES_TO_MAP_H

#include <poica/lang/private/map.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP(get_body, get_key, entities)   \
    POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_RESULT(                            \
        BOOST_PP_SEQ_FOLD_LEFT(POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT,  \
                               (get_body)(get_key)(POICA_P_LANG_MAP()),        \
                               entities))

#define POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_RESULT(state)                  \
    BOOST_PP_SEQ_ELEM(2, state)

#define POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT(_d, state, item)         \
    POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT_AUX(                         \
        BOOST_PP_SEQ_ELEM(0, state),                                           \
        BOOST_PP_SEQ_ELEM(1, state),                                           \
        BOOST_PP_SEQ_ELEM(2, state),                                           \
        (item))

#define POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT_AUX(                     \
    get_body, get_key, map, item)                                              \
    BOOST_PP_IF(POICA_P_LANG_MAP_EXISTS(map, get_key(item)),                   \
                POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT_EXISTS,          \
                POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT_DOES_NOT_EXIST)  \
    (get_body, get_key, map, item)

#define POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT_EXISTS(                  \
    get_body, get_key, map, item)                                              \
    (get_body)(get_key)(POICA_P_LANG_MAP_MAP_ITEM(                             \
        POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_APPEND_TO_ITEMS,               \
        get_body(item),                                                        \
        map,                                                                   \
        get_key(item)))

#define POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_VISIT_DOES_NOT_EXIST(          \
    get_body, get_key, map, item)                                              \
    (get_body)(get_key)(                                                       \
        POICA_P_LANG_MAP_APPEND(map, get_key(item), get_body(item)))

#define POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP_APPEND_TO_ITEMS(new_item,      \
                                                                items)         \
    items new_item

#endif // POICA_LANG_GADT_ORDER_ENTITIES_TO_MAP_H
