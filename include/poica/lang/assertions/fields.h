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

#ifndef POICA_LANG_ASSERTIONS_FIELDS_H
#define POICA_LANG_ASSERTIONS_FIELDS_H

#include <poica/lang/private/defer.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#ifdef POICA_ENABLE_ASSERTIONS

#define POICA_P_LANG_OPT_ASSERT_ARE_FIELDS(fields) POICA_ASSERT_ARE_FIELDS(fields)
#define POICA_P_LANG_OPT_ASSERT_IS_FIELD(field)    POICA_ASSERT_IS_FIELD(field)

#else

#define POICA_P_LANG_OPT_ASSERT_ARE_FIELDS(_fields) BOOST_PP_EMPTY()
#define POICA_P_LANG_OPT_ASSERT_IS_FIELD(_field)    BOOST_PP_EMPTY()

#endif

#define POICA_ASSERT_ARE_FIELDS(fields)                                                            \
    BOOST_VMD_ASSERT_IS_SEQ(fields)                                                                \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_ASSERT_IS_FIELDS_VISIT, BOOST_PP_EMPTY(), fields)

#define POICA_P_LANG_ASSERT_IS_FIELDS_VISIT(_r, _data, field) POICA_ASSERT_IS_FIELD((field))

#define POICA_ASSERT_IS_FIELD(field)                                                               \
    BOOST_VMD_ASSERT_IS_SEQ(POICA_P_LANG_EXPAND field)                                             \
    BOOST_VMD_ASSERT(BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(POICA_P_LANG_EXPAND field), 2))

#endif // POICA_LANG_ASSERTIONS_FIELDS_H
