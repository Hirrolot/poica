#ifndef POICA_SUM_VCONSTRS_H
#define POICA_SUM_VCONSTRS_H

#include "aux.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTRS(sum_name, variants)                           \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_VCONSTR, sum_name, variants)

#define POICA_P_SUM_GEN_VCONSTR(_r, sum_name, variant)                         \
    POICA_P_SUM_OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_VCONSTR_, sum_name, variant)

#define POICA_P_SUM_GEN_VCONSTR_EMPTY(sum_name, variant_name)                  \
    inline static sum_name variant_name(void) {                                \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = POICA_P_SUM_UNUSED_VALUE,                     \
        };                                                                     \
    }

#define POICA_P_SUM_GEN_VCONSTR_NONEMPTY(sum_name, variant_name, variant_type) \
    inline static sum_name variant_name(variant_type arg) {                    \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = arg,                                          \
        };                                                                     \
    }

#endif // POICA_SUM_VCONSTRS_H
