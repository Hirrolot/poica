#ifndef POICA_SUM_PATTERN_MATCHING_H
#define POICA_SUM_PATTERN_MATCHING_H

#include "../../keywords.h"
#include "../../poly.h"

#include "tags.h"

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
        POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) *var_name =   \
            (POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)          \
                 *)(&((POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(         \
                          variant_name) *)poica_p_sum_ptr)                     \
                         ->data.variant_name);

#define POICA_P_SUM_CASE_3(variant_name, _many, var_names)                     \
    case POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name):                        \
        POICA_P_SUM_BREAK_IF_NEEDED                                            \
                                                                               \
        POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(                            \
            variant_name) *poica_p_var_name =                                  \
            (POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)          \
                 *)(&((POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(         \
                          variant_name) *)poica_p_sum_ptr)                     \
                         ->data.variant_name);                                 \
                                                                               \
        EXTRACT(var_names FROM(                                                \
            poica_p_var_name OF POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(    \
                variant_name)));

#define POICA_P_SUM_BREAK_IF_NEEDED                                            \
    if (poica_p_break_is_needed) {                                             \
        break;                                                                 \
    } else {                                                                   \
        poica_p_break_is_needed = true;                                        \
    }

#endif // POICA_SUM_PATTERN_MATCHING_H
