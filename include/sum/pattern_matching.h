#ifndef POICA_SUM_PATTERN_MATCHING_H
#define POICA_SUM_PATTERN_MATCHING_H

#include "../keywords.h"
#include "../poly.h"
#include "gen/tags.h"
#include "product/gen/redirects/to_field_type.h"

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define MATCHES(sum_ptr, variant_name)                                         \
    ((sum_ptr)->tag == POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name))

#define MATCH(sum_ptr)                                                         \
    for (poly poica_p_sum_ptr = (poly)(sum_ptr); poica_p_sum_ptr != (poly)0;   \
         poica_p_sum_ptr = (poly)0)                                            \
        for (bool poica_p_break_is_needed = false; !poica_p_break_is_needed;   \
             poica_p_break_is_needed = true)                                   \
            switch ((sum_ptr)->tag)

#define CASE(...) BOOST_PP_OVERLOAD(POICA_P_SUM_CASE_, __VA_ARGS__)(__VA_ARGS__)

#define DEFAULT                                                                \
    default:                                                                   \
        POICA_P_SUM_BREAK_IF_NEEDED

#define POICA_P_SUM_CASE_1(variant_name)                                       \
    case POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name):                        \
        POICA_P_SUM_BREAK_IF_NEEDED

#define POICA_P_SUM_CASE_2(variant_name, var_name)                             \
    case POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name):                        \
        POICA_P_SUM_BREAK_IF_NEEDED                                            \
                                                                               \
        for (POICA_P_SUM_DEDUCE_MATCHED_VAR(var_name, variant_name);           \
             var_name != (void *)0;                                            \
             var_name = (void *)0)

#define POICA_P_SUM_CASE_3(variant_name, _many, var_names)                     \
    case POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name):                        \
        POICA_P_SUM_BREAK_IF_NEEDED                                            \
                                                                               \
        for (POICA_P_SUM_DEDUCE_MATCHED_VAR(poica_p_case_var, variant_name);   \
             poica_p_case_var != (void *)0;                                    \
             poica_p_case_var = (void *)0)                                     \
                                                                               \
        POICA_P_SUM_EXTRACT_MATCHED_VARS(var_names FROM(                       \
            poica_p_case_var OF POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(    \
                variant_name)))

#define POICA_P_SUM_EXTRACT_MATCHED_VARS(...)                                  \
    POICA_P_SUM_EXTRACT_MATCHED_VARS_AUX(__VA_ARGS__)

#define POICA_P_SUM_EXTRACT_MATCHED_VARS_AUX(fields, val)                      \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_EXTRACT_MATCHED_VARS_GEN_ASSIGN_IN_FOR,  \
                          val,                                                 \
                          BOOST_PP_TUPLE_TO_SEQ(fields))

#define POICA_P_SUM_EXTRACT_MATCHED_VARS_GEN_ASSIGN_IN_FOR(                    \
    _r, val, field_name)                                                       \
    for (POICA_P_PRODUCT_REDIRECT_TO_FIELD_TYPE(                               \
             BOOST_PP_TUPLE_ELEM(2, 1, val), field_name) *field_name =         \
             &BOOST_PP_TUPLE_ELEM(2, 0, val)->field_name;                      \
         field_name != (void *)0;                                              \
         field_name = (void *)0)

#define POICA_P_SUM_DEDUCE_MATCHED_VAR(var_name, variant_name)                 \
    POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) *var_name =       \
        (POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)              \
             *)(&((POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(             \
                      variant_name) *)poica_p_sum_ptr)                         \
                     ->data.variant_name)

#define POICA_P_SUM_BREAK_IF_NEEDED                                            \
    if (poica_p_break_is_needed) {                                             \
        break;                                                                 \
    } else {                                                                   \
        poica_p_break_is_needed = true;                                        \
    }

#endif // POICA_SUM_PATTERN_MATCHING_H
