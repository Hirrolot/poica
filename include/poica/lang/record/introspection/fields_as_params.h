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

#ifndef POICA_LANG_RECORD_INTROSPECTION_FIELDS_AS_PARAMS_H
#define POICA_LANG_RECORD_INTROSPECTION_FIELDS_AS_PARAMS_H

#include <poica/lang/assertions/fields.h>

#include <boost/preprocessor.hpp>

#define POICA_RECORD_FIELDS_AS_PARAMS(fields)                                                      \
    POICA_ASSERT_ARE_FIELDS(fields)                                                                \
                                                                                                   \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_RECORD_GEN_FIELDS_AS_PARAMS_VISIT,                          \
                          BOOST_PP_EMPTY(),                                                        \
                          BOOST_PP_SEQ_POP_BACK(fields))                                           \
                                                                                                   \
    POICA_P_LANG_RECORD_GEN_FIELDS_AS_PARAMS_VISIT_LAST(                                           \
        BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(fields)), fields))

#define POICA_P_LANG_RECORD_GEN_FIELDS_AS_PARAMS_VISIT(_r, _data, field)                           \
    POICA_FIELD_TYPE((field)) POICA_FIELD_NAME((field)),

#define POICA_P_LANG_RECORD_GEN_FIELDS_AS_PARAMS_VISIT_LAST(field)                                 \
    POICA_FIELD_TYPE((field)) POICA_FIELD_NAME((field))

#endif // POICA_LANG_RECORD_INTROSPECTION_FIELDS_AS_PARAMS_H
