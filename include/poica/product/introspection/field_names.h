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

#ifndef POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H
#define POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H

#include <poica/product/introspection/aux.h>

#include <boost/preprocessor.hpp>

#define FIELD_NAME(field) BOOST_PP_SEQ_ELEM(0, field)

#define PRODUCT_FIELD_NAMES_SEQ(fields)                                        \
    POICA_P_PRODUCT_FIELD_X_SEQ(POICA_P_PRODUCT_GEN_FIELD_NAME_SEQ, fields)
#define POICA_P_PRODUCT_GEN_FIELD_NAME_SEQ(_r, _data, field) (FIELD_NAME(field))

#define PRODUCT_FIELD_NAMES_TUPLE(fields)                                      \
    POICA_P_PRODUCT_FIELD_X_TUPLE(POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE,        \
                                  POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE_LAST,   \
                                  fields)

#define POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE(_r, _data, field)                 \
    FIELD_NAME(field),
#define POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE_LAST(field) FIELD_NAME(field)

#endif // POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H
