#ifndef POICA_SUM_GEN_REDIRECTS_TO_OUTER_SUM_TYPE_H
#define POICA_SUM_GEN_REDIRECTS_TO_OUTER_SUM_TYPE_H

#include "../../../private/aux.h"

#include "../../variant.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_OUTER_SUM_TYPE(sum_name,          \
                                                            variants)          \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE,  \
                          sum_name,                                            \
                          variants)

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(                    \
    _r, sum_name, variant)                                                     \
    typedef sum_name POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(           \
        VARIANT_NAME(variant));

#define POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(variant_name)           \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToOuterSumType))

#endif // POICA_SUM_GEN_REDIRECTS_TO_OUTER_SUM_TYPE_H
