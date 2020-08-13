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

#ifndef POICA_CHOICE_GEN_FIELDS_H
#define POICA_CHOICE_GEN_FIELDS_H

#include <poica/choice/gen/redirects/to_inner_type.h>
#include <poica/choice/variant.h>

#include <boost/preprocessor.hpp>

#define POICA_P_CHOICE_GEN_FIELDS(variants)                                    \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_CHOICE_GEN_FIELDS_VISIT, _data, variants)

#define POICA_P_CHOICE_GEN_FIELDS_VISIT(_r, _data, variant)                    \
    POICA_OVERLOAD_ON_VARIANT(POICA_P_CHOICE_GEN_FIELD_, _data, variant)

#define POICA_P_CHOICE_GEN_FIELD_VARIANT_KIND_EMPTY(_data, variant_name)

#define POICA_P_CHOICE_GEN_FIELD_VARIANT_KIND_SINGLE(                          \
    _data, variant_name, variant_type)                                         \
    variant_type variant_name;

#define POICA_P_CHOICE_GEN_FIELD_VARIANT_KIND_MANY(                            \
    _data, variant_name, _fields)                                              \
    POICA_P_CHOICE_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) variant_name;

#endif // POICA_CHOICE_GEN_FIELDS_H
