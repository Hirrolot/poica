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

#ifndef POICA_LANG_CHOICE_GEN_VARIANT_KIND_MANY
#define POICA_LANG_CHOICE_GEN_VARIANT_KIND_MANY

#include <poica/lang/private/defer.h>

#include <poica/lang/choice/gen/records_for_many/redirects.h>
#include <poica/lang/choice/gen/redirects/to_inner_type.h>
#include <poica/lang/choice/introspection.h>

#include <poica/lang/record.h>

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY(variants)                     \
    POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_EXPAND(BOOST_PP_SEQ_FOR_EACH(     \
        POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_VISIT, _data, variants))

#define POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_EXPAND(...) __VA_ARGS__

#define POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_VISIT(_r, data, variant)      \
    POICA_OVERLOAD_ON_VARIANT(POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_VISIT_, \
                              BOOST_PP_EMPTY(),                                \
                              (variant))

#define POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_VISIT_VARIANT_KIND_EMPTY(     \
    _data, _variant_name)                                                      \
    BOOST_PP_EMPTY()

#define POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_VISIT_VARIANT_KIND_SINGLE(    \
    _data, _variant_name, _variant_type)                                       \
    BOOST_PP_EMPTY()

#define POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY_VISIT_VARIANT_KIND_MANY(      \
    _data, variant_name, fields)                                               \
    POICA_P_LANG_DEFER(POICA_P_LANG_RECORD)                                    \
    (POICA_P_LANG_CHOICE_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name),         \
     fields);                                                                  \
                                                                               \
    POICA_P_LANG_DEFER(                                                        \
        POICA_P_LANG_CHOICE_RECORD_FOR_MANY_GEN_REDIRECTS_TO_FIELD_TYPE)       \
    (POICA_P_LANG_CHOICE_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name), fields)

#endif // POICA_LANG_CHOICE_GEN_VARIANT_KIND_MANY
