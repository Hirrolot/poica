#ifndef POICA_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP_H
#define POICA_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP_H

#include <poica/lang/gadt/order_entities_to_map.h>

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP(...)                    \
    POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP(                                   \
        POICA_P_LANG_MATCH_GADT_GET_ARM_REST,                                  \
        POICA_P_LANG_MATCH_GADT_GET_ARM_TYPES,                                 \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#endif // POICA_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP_H
