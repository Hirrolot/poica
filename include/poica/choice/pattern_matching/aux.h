
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

#include <poica/choice/gen/records_for_many/redirects.h>
#include <poica/choice/gen/tags.h>

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define POICA_P_MATCH(qualifier, choice_ptr)                                   \
    POICA_P_CHOICE_SCOPE(qualifier void *poica_p_choice_ptr =                  \
                             (qualifier void *)(choice_ptr))                   \
    switch ((choice_ptr)->tag)

#define POICA_P_OF(qualifier, ...)                                             \
    BOOST_PP_OVERLOAD(POICA_P_CHOICE_OF_, qualifier, __VA_ARGS__)              \
    (qualifier, __VA_ARGS__)

#define POICA_P_CHOICE_OF_2(_qualifier, variant_name)                          \
    break;                                                                     \
    case POICA_P_CHOICE_VARIANT_NAME_AS_TAG(variant_name):

#define POICA_P_CHOICE_OF_3(qualifier, variant_name, var_name)                 \
    break;                                                                     \
    case POICA_P_CHOICE_VARIANT_NAME_AS_TAG(variant_name):                     \
        POICA_P_CHOICE_SCOPE(POICA_P_CHOICE_DEDUCE_MATCHED_VAR(                \
            qualifier, var_name, variant_name))

#define POICA_P_OF_MANY(qualifier, variant_name, var_names)                    \
    break;                                                                     \
    case POICA_P_CHOICE_VARIANT_NAME_AS_TAG(variant_name):                     \
                                                                               \
        POICA_P_CHOICE_SCOPE(POICA_P_CHOICE_DEDUCE_MATCHED_VAR(                \
            qualifier, poica_p_case_var, variant_name))                        \
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
    POICA_P_CHOICE_SCOPE(                                                      \
        POICA_P_CHOICE_EXTRACT_QUALIFIER(qualifier_and_val)                    \
            POICA_P_CHOICE_RECORD_FOR_MANY_REDIRECT_TO_FIELD_TYPE(             \
                POICA_P_CHOICE_EXTRACT_VAL_TYPE(qualifier_and_val),            \
                field_name) *field_name =                                      \
                &POICA_P_CHOICE_EXTRACT_VAL_NAME(qualifier_and_val)            \
                     ->field_name)

#define POICA_P_CHOICE_EXTRACT_QUALIFIER(qualifier_and_val)                    \
    BOOST_PP_TUPLE_ELEM(2, 0, qualifier_and_val)
#define POICA_P_CHOICE_EXTRACT_VAL_NAME(qualifier_and_val)                     \
    BOOST_PP_TUPLE_ELEM(2, 0, BOOST_PP_TUPLE_ELEM(2, 1, qualifier_and_val))
#define POICA_P_CHOICE_EXTRACT_VAL_TYPE(qualifier_and_val)                     \
    BOOST_PP_TUPLE_ELEM(2, 1, BOOST_PP_TUPLE_ELEM(2, 1, qualifier_and_val))

#define POICA_P_CHOICE_DEDUCE_MATCHED_VAR(qualifier, var_name, variant_name)   \
    qualifier POICA_P_CHOICE_REDIRECT_VARIANT_TO_INNER_TYPE(                   \
        variant_name) *var_name =                                              \
        (&((qualifier POICA_P_CHOICE_REDIRECT_VARIANT_TO_OUTER_CHOICE_TYPE(    \
               variant_name) *)poica_p_choice_ptr)                             \
              ->data.variant_name)

/*
 * Creates a new block scope with some variables within.
 *
 * It's implemented by a single-iteration for-loop, which is semantically
 * equivalent to the following compound statement:
 *
 * {
 *     vars;
 *     ...
 * }
 *
 * Why don't we use this one? Because such macros as match, of and ofMany have
 * the following form:
 *
 * macro(...) { ... }
 */
#define POICA_P_CHOICE_SCOPE(vars)                                             \
    for (vars, *poica_p_break_for = (void *)1; poica_p_break_for != (void *)2; \
         poica_p_break_for = (void *)2)

#endif // POICA_CHOICE_PATTERN_MATCHING_AUX_H
