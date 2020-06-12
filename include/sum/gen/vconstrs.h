#ifndef POICA_SUM_GEN_VCONSTRS_H
#define POICA_SUM_GEN_VCONSTRS_H

#include "../../private/defer.h"
#include "../../product.h"
#include "../introspection.h"
#include "../unused_field_type.h"
#include "tags.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTRS(sum_name, variants)                           \
    POICA_P_EXPAND(                                                            \
        BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_VCONSTR, sum_name, variants))

#define POICA_P_SUM_GEN_VCONSTR(_r, sum_name, variant)                         \
    OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_VCONSTR_, sum_name, variant)

#define POICA_P_SUM_GEN_VCONSTR_VARIANT_EMPTY(sum_name, variant_name)          \
    inline static sum_name variant_name(void) {                                \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = POICA_P_SUM_UNUSED_VALUE,                     \
        };                                                                     \
    }

#define POICA_P_SUM_GEN_VCONSTR_VARIANT_SINGLE(                                \
    sum_name, variant_name, variant_type)                                      \
    inline static sum_name variant_name(variant_type arg) {                    \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = arg,                                          \
        };                                                                     \
    }

#define POICA_P_SUM_GEN_VCONSTR_VARIANT_MANY(sum_name, variant_name, fields)   \
    inline static sum_name variant_name(                                       \
        POICA_P_DEFER(POICA_P_SUM_GEN_VCONSTR_ARGS_FOR_MANY)(fields)) {        \
        return (sum_name){                                                     \
            .tag = POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name),              \
            .data.variant_name = {POICA_P_DEFER(                               \
                POICA_P_SUM_VCONSTR_EXTRACT_ARG_NAMES_FOR_MANY)(fields)},      \
        };                                                                     \
    }

#define POICA_P_SUM_GEN_VCONSTR_ARGS_FOR_MANY(fields)                          \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_SUM_VCONSTR_GEN_ARG, _data, BOOST_PP_SEQ_POP_BACK(fields))     \
                                                                               \
    POICA_P_SUM_VCONSTR_GEN_ARG_LAST_FOR_MANY(                                 \
        BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(fields)), fields))

#define POICA_P_SUM_VCONSTR_GEN_ARG(_r, _data, field)                          \
    FIELD_TYPE(field) FIELD_NAME(field),

#define POICA_P_SUM_VCONSTR_GEN_ARG_LAST_FOR_MANY(field)                       \
    FIELD_TYPE(field) FIELD_NAME(field)

#define POICA_P_SUM_VCONSTR_EXTRACT_ARG_NAMES_FOR_MANY(fields)                 \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_SUM_VCONSTR_EXTRACT_ARG_NAME_FOR_MANY, _data, fields)

#define POICA_P_SUM_VCONSTR_EXTRACT_ARG_NAME_FOR_MANY(_r, _data, field)        \
    FIELD_NAME(field),

#endif // POICA_SUM_GEN_VCONSTRS_H
