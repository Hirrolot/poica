#ifndef POICA_LANG_CHOICE_IS_EMPTY_STRUCT_H
#define POICA_LANG_CHOICE_IS_EMPTY_STRUCT_H

#include <poica/lang/choice/introspection/overload_on_variant.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

// Empty structures are forbidden in the standard C11, so we need to detect
// whether a sum type has or has not data.
#define POICA_P_LANG_IS_EMPTY_STRUCT(variants)                                 \
    BOOST_VMD_IS_EMPTY(                                                        \
        BOOST_PP_EMPTY() BOOST_PP_SEQ_SIZE(BOOST_PP_SEQ_FOR_EACH(              \
            POICA_P_LANG_IS_EMPTY_STRUCT_VISIT, BOOST_PP_EMPTY(), variants)))

#define POICA_P_LANG_IS_EMPTY_STRUCT_VISIT(_r, _data, variant)                 \
    POICA_OVERLOAD_ON_VARIANT(                                                 \
        POICA_P_LANG_REPLACE_VARIANT_WITH_ITEM_, BOOST_PP_EMPTY(), (variant))

#define POICA_P_LANG_REPLACE_VARIANT_WITH_ITEM_VARIANT_KIND_EMPTY(             \
    _data, _variant_name)                                                      \
    BOOST_PP_EMPTY()

#define POICA_P_LANG_REPLACE_VARIANT_WITH_ITEM_VARIANT_KIND_SINGLE(            \
    _data, _variant_name, _variant_type)                                       \
    (_)

#define POICA_P_LANG_REPLACE_VARIANT_WITH_ITEM_VARIANT_KIND_MANY(              \
    _data, _variant_name, _fields)                                             \
    (_)

#endif // POICA_LANG_CHOICE_IS_EMPTY_STRUCT_H
