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

#ifndef POICA_ENUM_PATTERN_MATCHING_H
#define POICA_ENUM_PATTERN_MATCHING_H

#include <poica/enum/gen/tags.h>
#include <poica/record/gen/redirects/to_field_type.h>

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define matches POICA_P_MATCHES
#define match   POICA_P_MATCH
#define default() POICA_P_DEFAULT()
#define caseMany POICA_P_CASE_MANY
// clang-format off
#define case(...) POICA_P_CASE(__VA_ARGS__)
// clang-format off

#define POICA_P_MATCHES(enum_ptr, variant_name)                                \
    ((enum_ptr)->tag == POICA_P_ENUM_VARIANT_NAME_AS_TAG(variant_name))

#define POICA_P_MATCH(enum_ptr)                                                \
    for (void *poica_p_enum_ptr = (void *)(enum_ptr);                          \
         poica_p_enum_ptr != (void *)0;                                        \
         poica_p_enum_ptr = (void *)0)                                         \
        for (bool poica_p_break_is_needed = false; !poica_p_break_is_needed;   \
             poica_p_break_is_needed = true)                                   \
            switch ((enum_ptr)->tag)

#define POICA_P_CASE(...)                                                      \
    BOOST_PP_OVERLOAD(POICA_P_ENUM_CASE_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_DEFAULT                                                        \
    default:                                                                   \
        POICA_P_ENUM_BREAK_IF_NEEDED

// These FALLTHRU comments are used to shut down the -Wimplicit-fallthrough gcc
// warning, because it's false positive.

#define POICA_P_ENUM_CASE_1(variant_name)                                      \
    /* FALLTHRU */                                                             \
    case POICA_P_ENUM_VARIANT_NAME_AS_TAG(variant_name):                       \
        POICA_P_ENUM_BREAK_IF_NEEDED

#define POICA_P_ENUM_CASE_2(variant_name, var_name)                            \
    /* FALLTHRU */                                                             \
    case POICA_P_ENUM_VARIANT_NAME_AS_TAG(variant_name):                       \
        POICA_P_ENUM_BREAK_IF_NEEDED                                           \
                                                                               \
        for (POICA_P_ENUM_DEDUCE_MATCHED_VAR(var_name, variant_name);          \
             var_name != (void *)0;                                            \
             var_name = (void *)0)

#define POICA_P_CASE_MANY(variant_name, var_names)                             \
    /* FALLTHRU */                                                             \
    case POICA_P_ENUM_VARIANT_NAME_AS_TAG(variant_name):                       \
        POICA_P_ENUM_BREAK_IF_NEEDED                                           \
                                                                               \
        for (POICA_P_ENUM_DEDUCE_MATCHED_VAR(poica_p_case_var, variant_name);  \
             poica_p_case_var != (void *)0;                                    \
             poica_p_case_var = (void *)0)                                     \
                                                                               \
        POICA_P_ENUM_EXTRACT_MATCHED_VARS(                                     \
            var_names,                                                         \
            (poica_p_case_var,                                                 \
             POICA_P_ENUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)))

#define POICA_P_ENUM_EXTRACT_MATCHED_VARS(fields, val)                         \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_ENUM_EXTRACT_MATCHED_VARS_GEN_ASSIGN_IN_FOR, \
                          val,                                                 \
                          BOOST_PP_TUPLE_TO_SEQ(fields))

#define POICA_P_ENUM_EXTRACT_MATCHED_VARS_GEN_ASSIGN_IN_FOR(                   \
    _r, val, field_name)                                                       \
    for (POICA_P_RECORD_REDIRECT_TO_FIELD_TYPE(BOOST_PP_TUPLE_ELEM(2, 1, val), \
                                               field_name) *field_name =       \
             &BOOST_PP_TUPLE_ELEM(2, 0, val)->field_name;                      \
         field_name != (void *)0;                                              \
         field_name = (void *)0)

#define POICA_P_ENUM_DEDUCE_MATCHED_VAR(var_name, variant_name)                \
    POICA_P_ENUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) *var_name =      \
        (POICA_P_ENUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)             \
             *)(&((POICA_P_ENUM_REDIRECT_VARIANT_TO_OUTER_ENUM_TYPE(           \
                      variant_name) *)poica_p_enum_ptr)                        \
                     ->data.variant_name)

#define POICA_P_ENUM_BREAK_IF_NEEDED                                           \
    if (poica_p_break_is_needed) {                                             \
        break;                                                                 \
    } else {                                                                   \
        poica_p_break_is_needed = true;                                        \
    }

#endif // POICA_ENUM_PATTERN_MATCHING_H
