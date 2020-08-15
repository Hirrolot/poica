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

#ifndef POICA_CHOICE_GEN_RECORDS_FOR_MANY_REDIRECTS_TO_FIELD_TYPE_H
#define POICA_CHOICE_GEN_RECORDS_FOR_MANY_REDIRECTS_TO_FIELD_TYPE_H

#include <poica/record/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_P_CHOICE_RECORD_FOR_MANY_GEN_REDIRECTS_TO_FIELD_TYPE(            \
    record_name, fields)                                                       \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_CHOICE_RECORD_FOR_MANY_GEN_REDIRECTS_TO_FIELD_TYPE_VISIT,      \
        record_name,                                                           \
        fields)

#define POICA_P_CHOICE_RECORD_FOR_MANY_GEN_REDIRECTS_TO_FIELD_TYPE_VISIT(      \
    _r, record_name, field)                                                    \
    typedef POICA_FIELD_TYPE((field))                                          \
        POICA_P_CHOICE_RECORD_FOR_MANY_REDIRECT_TO_FIELD_TYPE(                 \
            record_name, POICA_FIELD_NAME((field)));

#define POICA_P_CHOICE_RECORD_FOR_MANY_REDIRECT_TO_FIELD_TYPE(record_name,     \
                                                              field_name)      \
    BOOST_PP_CAT(                                                              \
        record_name,                                                           \
        BOOST_PP_CAT(_, BOOST_PP_CAT(field_name, _RedirectToFieldType)))

#endif // POICA_CHOICE_GEN_RECORDS_FOR_MANY_REDIRECTS_TO_FIELD_TYPE_H
