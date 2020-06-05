#ifndef POICA_SUM_TYPE_H
#define POICA_SUM_TYPE_H

#include "misc.h"
#include "poica_p_aux.h"
#include "poly.h"

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define SUM(name, variants)                                                    \
    typedef struct name {                                                      \
        enum {                                                                 \
            BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_TYPE_GEN_TAG, _data, variants)   \
        } tag;                                                                 \
        struct {                                                               \
            BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_TYPE_GEN_FIELD, _data, variants) \
        } data;                                                                \
    } name;                                                                    \
                                                                               \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_TYPE_GEN_REDIRECT_VARIANT_TO_INNER_TYPE, \
                          _data, variants)                                     \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_SUM_TYPE_GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE, name,         \
        variants)                                                              \
                                                                               \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_TYPE_GEN_VCONSTR, name, variants)        \
                                                                               \
    typedef int POICA_P_PREFIX(BOOST_PP_CAT(name, _UselessTypedef))

#define POICA_P_SUM_TYPE_GEN_REDIRECT_VARIANT_TO_INNER_TYPE(_r, _data,         \
                                                            variant)           \
    typedef POICA_P_SUM_TYPE_VARIANT_TYPE(variant)                             \
        REDIRECT_VARIANT_TO_INNER_TYPE(                                        \
            POICA_P_SUM_TYPE_VARIANT_NAME(variant));
#define REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)                           \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToInnerType))

#define POICA_P_SUM_TYPE_GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(_r, sum_name,  \
                                                                variant)       \
    typedef sum_name REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(                       \
        POICA_P_SUM_TYPE_VARIANT_NAME(variant));
#define REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(variant_name)                       \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToOuterSumType))

#define POICA_P_SUM_TYPE_GEN_TAG(_r, _data, variant)                           \
    POICA_P_SUM_TYPE_VARIANT_NAME_AS_TAG(                                      \
        POICA_P_SUM_TYPE_VARIANT_NAME(variant)),
#define POICA_P_SUM_TYPE_VARIANT_NAME_AS_TAG(variant_name)                     \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _Tag))

#define POICA_P_SUM_TYPE_GEN_FIELD(_r, _data, variant)                         \
    POICA_P_SUM_TYPE_VARIANT_TYPE(variant)                                     \
    POICA_P_SUM_TYPE_VARIANT_NAME(variant);

#define POICA_P_SUM_TYPE_VARIANT_NAME(variant)                                 \
    BOOST_PP_TUPLE_ELEM(2, 0, variant)
#define POICA_P_SUM_TYPE_VARIANT_TYPE(variant)                                 \
    BOOST_PP_TUPLE_ELEM(2, 1, variant)

#define POICA_P_SUM_TYPE_GEN_VCONSTR(_r, sum_name, variant)                    \
    inline static sum_name POICA_P_SUM_TYPE_VARIANT_NAME(variant)(             \
        POICA_P_SUM_TYPE_VARIANT_TYPE(variant) arg) {                          \
        return (sum_name){.tag = POICA_P_SUM_TYPE_VARIANT_NAME_AS_TAG(         \
                              POICA_P_SUM_TYPE_VARIANT_NAME(variant)),         \
                          .data.POICA_P_SUM_TYPE_VARIANT_NAME(variant) = arg}; \
    }

#define VARIANT(...) POICA_P_SUM_TYPE_VARIANT_AUX(__VA_ARGS__)
#define POICA_P_SUM_TYPE_VARIANT_AUX(variant_name, variant_type)               \
    ((variant_name OF variant_type))

#define MATCH(sum_ptr)                                                         \
    for (poly poica_p_inner_sum_ptr = (poly)sum_ptr;                           \
         poica_p_inner_sum_ptr != (poly)0; poica_p_inner_sum_ptr = (poly)0)    \
        for (bool poica_p_break_is_needed = false; !poica_p_break_is_needed;   \
             poica_p_break_is_needed = true)                                   \
            switch (sum_ptr->tag)

#define CASE(variant_name, var_name)                                           \
    case POICA_P_SUM_TYPE_VARIANT_NAME_AS_TAG(variant_name):                   \
        POICA_P_SUM_TYPE_BREAK_IF_NEEDED                                       \
                                                                               \
        REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) *var_name =               \
            (REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)                      \
                 *)(&((REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(                     \
                          variant_name) *)poica_p_inner_sum_ptr)               \
                         ->data.variant_name);

#define DEFAULT                                                                \
    default:                                                                   \
        POICA_P_SUM_TYPE_BREAK_IF_NEEDED

#define POICA_P_SUM_TYPE_BREAK_IF_NEEDED                                       \
    if (poica_p_break_is_needed) {                                             \
        break;                                                                 \
    } else {                                                                   \
        poica_p_break_is_needed = true;                                        \
    }

#endif // POICA_SUM_TYPE_H
