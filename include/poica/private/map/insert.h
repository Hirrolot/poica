#ifndef POICA_PRIVATE_MAP_INSERT_H
#define POICA_PRIVATE_MAP_INSERT_H

#include <poica/private/map/is_empty.h>
#include <poica/private/map/item.h>
#include <poica/private/map/map_item.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define POICA_P_MAP_INSERT(map, key, value)                                    \
    BOOST_PP_IF(POICA_P_MAP_IS_EMPTY(map),                                     \
                POICA_P_MAP_INSERT_EMPTY,                                      \
                POICA_P_MAP_INSERT_NON_EMPTY)                                  \
    (map, key, value)

#define POICA_P_MAP_INSERT_EMPTY(_map, key, value) POICA_P_MAP_ITEM(key, value)
#define POICA_P_MAP_INSERT_NON_EMPTY(map, key, value)                          \
    BOOST_PP_IF(POICA_P_MAP_EXISTS(map, key),                                  \
                POICA_P_MAP_INSERT_NON_EMPTY_EXISTS,                           \
                POICA_P_MAP_INSERT_NON_EMPTY_DOES_NOT_EXIST)                   \
    (map, key, value)

#define POICA_P_MAP_INSERT_NON_EMPTY_EXISTS(map, key, value)                   \
    POICA_P_MAP_MAP_ITEM(                                                      \
        POICA_P_MAP_INSERT_MAP_ITEM, POICA_P_MAP_ITEM(key, value), map, key)

#define POICA_P_MAP_INSERT_NON_EMPTY_DOES_NOT_EXIST(map, key, value)           \
    POICA_P_MAP_APPEND(map, key, value)

#define POICA_P_MAP_INSERT_MAP_ITEM(new_item, _old_item) new_item

#endif // POICA_PRIVATE_MAP_INSERT_H
