#ifndef POICA_SUM_GEN_VCONSTRS_VARIANT_SINGLE_H
#define POICA_SUM_GEN_VCONSTRS_VARIANT_SINGLE_H

#include "../../unused_field_type.h"
#include "../tags.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTR_VARIANT_SINGLE(                                \
    sum_name, variant_name, variant_type)                                      \
    inline static sum_name variant_name(variant_type arg) {                    \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = arg,                                          \
        };                                                                     \
    }

#endif // POICA_SUM_GEN_VCONSTRS_VARIANT_SINGLE_H
