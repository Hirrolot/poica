#ifndef POICA_SUM_GEN_VCONSTRS_VARIANT_MANY_H
#define POICA_SUM_GEN_VCONSTRS_VARIANT_MANY_H

#include <poica/private/defer.h>

#include <poica/product/introspection.h>

#include <poica/sum/gen/tags.h>
#include <poica/sum/unused_field_type.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTR_VARIANT_MANY(sum_name, variant_name, fields)   \
    inline static sum_name variant_name(                                       \
        POICA_P_DEFER(PRODUCT_FIELDS_AS_PARAMS)(fields)) {                     \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = {POICA_P_DEFER(PRODUCT_FIELD_NAMES)(fields)}, \
        };                                                                     \
    }

#endif // POICA_SUM_GEN_VCONSTRS_VARIANT_MANY_H
