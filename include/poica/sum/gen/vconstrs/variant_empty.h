#ifndef POICA_SUM_GEN_VCONSTRS_VARIANT_EMPTY_H
#define POICA_SUM_GEN_VCONSTRS_VARIANT_EMPTY_H

#include <poica/sum/gen/tags.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTR_VARIANT_EMPTY(sum_name, variant_name)          \
    inline static sum_name variant_name(void) {                                \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
        };                                                                     \
    }

#endif // POICA_SUM_GEN_VCONSTRS_VARIANT_EMPTY_H
