#ifndef POICA_LANG_GADT_VARIANT_H
#define POICA_LANG_GADT_VARIANT_H

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_GADT_VARIANT(variant, types) ((variant)(types))

#define POICA_P_LANG_GADT_VARIANT_BODY(variant)                                \
    BOOST_PP_SEQ_ELEM(0, POICA_P_LANG_GADT_VARIANT_EXPAND variant)

#define POICA_P_LANG_GADT_VARIANT_TYPES(variant)                               \
    BOOST_PP_SEQ_ELEM(1, POICA_P_LANG_GADT_VARIANT_EXPAND variant)

#define POICA_P_LANG_GADT_VARIANT_EXPAND(...) __VA_ARGS__

#endif // POICA_LANG_GADT_VARIANT_H
