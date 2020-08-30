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

#ifndef POICA_LANG_PRIVATE_VARIADIC_TO_SEQ
#define POICA_LANG_PRIVATE_VARIADIC_TO_SEQ

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

// Like BOOST_PP_VARIADIC_TO_SEQ, but takes care about a trailing comma.
// Requires at least 1 passed arguments.
#define POICA_P_LANG_VARIADIC_TO_SEQ(...)                                                          \
    POICA_P_LANG_VARIADIC_TO_SEQ_AUX(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define POICA_P_LANG_VARIADIC_TO_SEQ_AUX(seq)                                                      \
    BOOST_PP_IF(BOOST_VMD_IS_EMPTY(BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(seq)), seq)),  \
                BOOST_PP_SEQ_POP_BACK,                                                             \
                BOOST_PP_IDENTITY)                                                                 \
    (seq)

#endif // POICA_LANG_PRIVATE_VARIADIC_TO_SEQ
