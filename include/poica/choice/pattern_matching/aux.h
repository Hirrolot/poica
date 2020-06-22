/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Hirrolot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef POICA_CHOICE_PATTERN_MATCHING_AUX_H
#define POICA_CHOICE_PATTERN_MATCHING_AUX_H

#include <poica/choice/gen/tags.h>
#include <poica/record/gen/redirects/to_field_type.h>

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define POICA_P_MATCH(qualifier, choice_ptr)                                   \
    for (qualifier void *poica_p_choice_ptr = (qualifier void *)(choice_ptr);  \
         poica_p_choice_ptr != (qualifier void *)0;                            \
         poica_p_choice_ptr = (qualifier void *)0)                             \
        for (bool poica_p_break_is_needed = false; !poica_p_break_is_needed;   \
             poica_p_break_is_needed = true)                                   \
            switch ((choice_ptr)->tag)

#define POICA_P_CASE(qualifier, ...)                                           \
    BOOST_PP_OVERLOAD(POICA_P_CHOICE_CASE_, qualifier, __VA_ARGS__)            \
    (qualifier, __VA_ARGS__)

// These FALLTHRU comments are used to suppress the -Wimplicit-fallthrough gcc
// warning, because it's false positive.

#define POICA_P_CHOICE_CASE_2(_qualifier, variant_name)                        \
    /* FALLTHRU */                                                             \
    case POICA_P_CHOICE_VARIANT_NAME_AS_TAG(variant_name):                     \
        POICA_P_CHOICE_BREAK_IF_NEEDED

#define POICA_P_CHOICE_CASE_3(qualifier, variant_name, var_name)               \
    /* FALLTHRU */                                                             \
    case POICA_P_CHOICE_VARIANT_NAME_AS_TAG(variant_name):                     \
        POICA_P_CHOICE_BREAK_IF_NEEDED                                         \
        /* FALLTHRU */                                                         \
        for (POICA_P_CHOICE_DEDUCE_MATCHED_VAR(                                \
                 qualifier, var_name, variant_name);                           \
             var_name != (qualifier void *)0;                                  \
             var_name = (qualifier void *)0)

#define POICA_P_CASE_MANY(qualifier, variant_name, var_names)                  \
    /* FALLTHRU */                                                             \
    case POICA_P_CHOICE_VARIANT_NAME_AS_TAG(variant_name):                     \
        POICA_P_CHOICE_BREAK_IF_NEEDED                                         \
                                                                               \
        for (POICA_P_CHOICE_DEDUCE_MATCHED_VAR(                                \
                 qualifier, poica_p_case_var, variant_name);                   \
             poica_p_case_var != (qualifier void *)0;                          \
             poica_p_case_var = (qualifier void *)0)                           \
                                                                               \
        POICA_P_CHOICE_EXTRACT_MATCHED_VARS(                                   \
            qualifier,                                                         \
            var_names,                                                         \
            (poica_p_case_var,                                                 \
             POICA_P_CHOICE_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)))

#define POICA_P_CHOICE_EXTRACT_MATCHED_VARS(qualifier, fields, val)            \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_CHOICE_EXTRACT_MATCHED_VARS_GEN_ASSIGN_IN_FOR,                 \
        (qualifier, val),                                                      \
        BOOST_PP_TUPLE_TO_SEQ(fields))

#define POICA_P_CHOICE_EXTRACT_MATCHED_VARS_GEN_ASSIGN_IN_FOR(                 \
    _r, qualifier_and_val, field_name)                                         \
    for (BOOST_PP_TUPLE_ELEM(2, 0, qualifier_and_val)                          \
             POICA_P_RECORD_REDIRECT_TO_FIELD_TYPE(                            \
                 BOOST_PP_TUPLE_ELEM(                                          \
                     2, 1, BOOST_PP_TUPLE_ELEM(2, 1, qualifier_and_val)),      \
                 field_name) *field_name =                                     \
                 &BOOST_PP_TUPLE_ELEM(                                         \
                      2, 0, BOOST_PP_TUPLE_ELEM(2, 1, qualifier_and_val))      \
                      ->field_name;                                            \
         field_name != (BOOST_PP_TUPLE_ELEM(2, 0, qualifier_and_val) void *)0; \
         field_name = (BOOST_PP_TUPLE_ELEM(2, 0, qualifier_and_val) void *)0)

#define POICA_P_CHOICE_DEDUCE_MATCHED_VAR(qualifier, var_name, variant_name)   \
    qualifier POICA_P_CHOICE_REDIRECT_VARIANT_TO_INNER_TYPE(                   \
        variant_name) *var_name =                                              \
        (qualifier POICA_P_CHOICE_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) \
             *)(&((qualifier                                                   \
                       POICA_P_CHOICE_REDIRECT_VARIANT_TO_OUTER_CHOICE_TYPE(   \
                           variant_name) *)poica_p_choice_ptr)                 \
                     ->data.variant_name)

#define POICA_P_CHOICE_BREAK_IF_NEEDED                                         \
    if (poica_p_break_is_needed) {                                             \
        break;                                                                 \
    } else {                                                                   \
        poica_p_break_is_needed = true;                                        \
    }

#endif // POICA_CHOICE_PATTERN_MATCHING_AUX_H
