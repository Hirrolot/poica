#ifndef POICA_CHOICE_IS_EMPTY_STRUCT_H
#define POICA_CHOICE_IS_EMPTY_STRUCT_H

#include <poica/choice/introspection/overload_on_variant.h>

#include <boost/preprocessor.hpp>

// Empty structures are forbidden in the standard C11, so we need to detect
// whether a sum type has or has not data.
#define POICA_P_IS_EMPTY_STRUCT(variants)                                      \
    BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(BOOST_PP_SEQ_FOR_EACH(                    \
                       POICA_P_IS_EMPTY_STRUCT_AUX, _data, variants)),         \
                   0)

#define POICA_P_IS_EMPTY_STRUCT_AUX(_r, _data, variant)                        \
    POICA_OVERLOAD_ON_VARIANT(                                                 \
        POICA_P_REPLACE_VARIANT_WITH_ITEM_, _data, variant)

#define POICA_P_REPLACE_VARIANT_WITH_ITEM_VARIANT_KIND_EMPTY(_data,            \
                                                             _variant_name)
#define POICA_P_REPLACE_VARIANT_WITH_ITEM_VARIANT_KIND_SINGLE(                 \
    _data, _variant_name, _variant_type)                                       \
    (_)
#define POICA_P_REPLACE_VARIANT_WITH_ITEM_VARIANT_KIND_MANY(                   \
    _data, _variant_name, _fields)                                             \
    (_)

#endif // POICA_CHOICE_IS_EMPTY_STRUCT_H
