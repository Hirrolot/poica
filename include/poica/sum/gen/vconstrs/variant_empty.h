#ifndef POICA_SUM_GEN_VCONSTRS_VARIANT_EMPTY_H
#define POICA_SUM_GEN_VCONSTRS_VARIANT_EMPTY_H

#include <poica/sum/gen/tags.h>
#include <poica/sum/unused_field_type.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTR_VARIANT_EMPTY(sum_name, variant_name)          \
    inline static sum_name variant_name(void) {                                \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = POICA_P_SUM_UNUSED_VALUE,                     \
        };                                                                     \
    }

#endif // POICA_SUM_GEN_VCONSTRS_VARIANT_EMPTY_H
