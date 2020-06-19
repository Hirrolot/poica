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

#ifndef POICA_RECORD_EXTRACT_EXTRACT_H
#define POICA_RECORD_EXTRACT_EXTRACT_H

#include <poica/record/extract/aux.h>

#include <poica/keywords.h>
#include <poica/record/gen/redirects/to_field_type.h>

#include <boost/preprocessor.hpp>

#define EXTRACT(...) POICA_P_EXTRACT_AUX(__VA_ARGS__)
#define POICA_P_EXTRACT_AUX(fields, val)                                       \
    POICA_P_RECORD_EXTRACT_X(POICA_P_RECORD_EXTRACT_GEN_ASSIGN, fields, val)

#define POICA_P_RECORD_EXTRACT_GEN_ASSIGN(_r, val, field_name)                 \
    POICA_P_RECORD_REDIRECT_TO_FIELD_TYPE(BOOST_PP_TUPLE_ELEM(2, 1, val),      \
                                          field_name)                          \
    field_name = (BOOST_PP_TUPLE_ELEM(2, 0, val))->field_name;

#endif // POICA_RECORD_EXTRACT_EXTRACT_H
