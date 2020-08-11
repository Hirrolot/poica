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

#ifndef POICA_INTERFACE_GEN_METHODS_PTRS_H
#define POICA_INTERFACE_GEN_METHODS_PTRS_H

#include <boost/preprocessor.hpp>

#define POICA_P_INTERFACE_GEN_METHODS_PTRS(methods)                            \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_INTERFACE_GEN_METHOD_PTR, _data, methods)

#define POICA_P_INTERFACE_GEN_METHOD_PTR(_r, _data, method)                    \
    POICA_P_INTERFACE_GEN_METHOD_PTR_AUX(BOOST_PP_SEQ_ELEM(0, method),         \
                                         BOOST_PP_SEQ_ELEM(1, method),         \
                                         BOOST_PP_SEQ_ELEM(2, method))

#define POICA_P_INTERFACE_GEN_METHOD_PTR_AUX(return_type, name, params)        \
    return_type(*name) params;

#endif // POICA_INTERFACE_GEN_METHODS_PTRS_H
