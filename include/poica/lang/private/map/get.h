#ifndef POICA_LANG_PRIVATE_MAP_GET_H
#define POICA_LANG_PRIVATE_MAP_GET_H

#include <poica/lang/private/map/item.h>
#include <poica/lang/private/overload_on_kind.h>

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_MAP_GET(map, key)                                         \
    POICA_P_LANG_EXPAND(                                                       \
        BOOST_PP_IF(BOOST_VMD_IS_EMPTY(map),                                   \
                    POICA_P_LANG_MAP_GET_EMPTY_SEQ,                            \
                    POICA_P_LANG_MAP_GET_NON_EMPTY_SEQ)(map, key))

#define POICA_P_LANG_MAP_GET_EMPTY_SEQ(map, key) (NOT_FOUND)
#define POICA_P_LANG_MAP_GET_NON_EMPTY_SEQ(map, key)                           \
    POICA_P_LANG_OVERLOAD_ON_KIND(                                             \
        POICA_P_LANG_MAP_GET_,                                                 \
        BOOST_PP_SEQ_FOLD_LEFT(                                                \
            POICA_P_LANG_MAP_GET_VISIT, (NOT_FOUND_YET)(key), map))

#define POICA_P_LANG_MAP_GET_ALREADY_FOUND(_key, value) (FOUND)(value)
#define POICA_P_LANG_MAP_GET_NOT_FOUND_YET(_key)        (NOT_FOUND)

#define POICA_P_LANG_MAP_GET_VISIT(_d, state, item)                            \
    POICA_P_LANG_OVERLOAD_ON_KIND(POICA_P_LANG_MAP_GET_VISIT_, state((item)))

#define POICA_P_LANG_MAP_GET_VISIT_ALREADY_FOUND(key, value, item)             \
    (ALREADY_FOUND)(key)(value)

#define POICA_P_LANG_MAP_GET_VISIT_NOT_FOUND_YET(key, item)                    \
    BOOST_PP_IF(POICA_P_LANG_MAP_IS_KEY_OF_ITEM(key, item),                    \
                (ALREADY_FOUND)(key)(POICA_P_LANG_MAP_ITEM_VALUE(item)),       \
                (NOT_FOUND_YET)(key))

#endif // POICA_LANG_PRIVATE_MAP_GET_H
