#ifndef POICA_SUM_GEN_TAGS_H
#define POICA_SUM_GEN_TAGS_H

#include "../../private/aux.h"

#include "../introspection.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_TAGS(variants)                                         \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_TAG, _data, variants)

#define POICA_P_SUM_GEN_TAG(_r, _data, variant)                                \
    POICA_P_SUM_VARIANT_NAME_AS_TAG(VARIANT_NAME(variant)),

#define POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name)                          \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _Tag))

#endif // POICA_SUM_GEN_TAGS_H
