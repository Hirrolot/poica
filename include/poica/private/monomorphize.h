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

#ifndef POICA_PRIVATE_MONOMORPHIZE_H
#define POICA_PRIVATE_MONOMORPHIZE_H

#include <poica/private/prefix.h>

#include <boost/preprocessor.hpp>

#define POICA_P_MONOMORPHIZE(...)                                              \
    POICA_P_PREFIX(BOOST_PP_SEQ_CAT(                                           \
        BOOST_PP_SEQ_TRANSFORM(POICA_P_MONOMORPHIZE_AUX,                       \
                               _data,                                          \
                               BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))))

#define POICA_P_MONOMORPHIZE_AUX(_r, _data, type_name)                         \
    BOOST_PP_CAT(BOOST_PP_CAT(POICA_P_FormTypeNameStart, type_name),           \
                 POICA_P_FormTypeNameEnd)

#endif // POICA_PRIVATE_MONOMORPHIZE_H
