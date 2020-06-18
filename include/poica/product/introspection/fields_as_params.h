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

#ifndef POICA_PRODUCT_INTROSPECTION_FIELDS_AS_PARAMS_H
#define POICA_PRODUCT_INTROSPECTION_FIELDS_AS_PARAMS_H

#include <boost/preprocessor.hpp>

#define PRODUCT_FIELDS_AS_PARAMS(fields)                                       \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_PRODUCT_GEN_FIELD_AS_PARAM,                  \
                          _data,                                               \
                          BOOST_PP_SEQ_POP_BACK(fields))                       \
                                                                               \
    POICA_P_PRODUCT_GEN_FIELD_AS_PARAM_LAST(                                   \
        BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(fields)), fields))

#define POICA_P_PRODUCT_GEN_FIELD_AS_PARAM(_r, _data, field)                   \
    FIELD_TYPE(field) FIELD_NAME(field),

#define POICA_P_PRODUCT_GEN_FIELD_AS_PARAM_LAST(field)                         \
    FIELD_TYPE(field) FIELD_NAME(field)

#endif // POICA_PRODUCT_INTROSPECTION_FIELDS_AS_PARAMS_H
