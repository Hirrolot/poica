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

#ifndef POICA_PRIVATE_OVERLOAD_ON_KIND_H
#define POICA_PRIVATE_OVERLOAD_ON_KIND_H

#include <boost/preprocessor.hpp>

/*
 * Concatanates `macro` with the first element of `seq` (Boost/PP sequence) and
 * calls `macro` with the rest of comma-separated elements of `seq`.
 *
 * `seq` shall consist of >=2 elements, and all the possible combinations of
 * `macro` + the first element of `seq` shall be defined.
 */
#define POICA_P_OVERLOAD_ON_KIND(macro, seq)                                   \
    POICA_P_OVERLOAD_ON_KIND_AUX(                                              \
        BOOST_PP_CAT(macro, BOOST_PP_SEQ_HEAD(seq)),                           \
        BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_FRONT(seq)))

#define POICA_P_OVERLOAD_ON_KIND_AUX(macro, ...) macro(__VA_ARGS__)

#endif // POICA_PRIVATE_OVERLOAD_ON_KIND_H
