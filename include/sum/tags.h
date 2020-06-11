#ifndef POICA_SUM_TAGS_H
#define POICA_SUM_TAGS_H

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_TAGS(variants)                                         \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_TAG, _data, variants)

#define POICA_P_SUM_GEN_TAG(_r, _data, variant)                                \
    POICA_P_SUM_VARIANT_NAME_AS_TAG(POICA_P_SUM_VARIANT_NAME(variant)),

#endif // POICA_SUM_TAGS_H
