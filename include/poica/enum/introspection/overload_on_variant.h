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

#ifndef POICA_ENUM_INTROSPECTION_OVERLOAD_ON_VARIANT_H
#define POICA_ENUM_INTROSPECTION_OVERLOAD_ON_VARIANT_H

#include <poica/enum/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_OVERLOAD_ON_VARIANT(macro, data, variant)                        \
    POICA_P_ENUM_OVERLOAD_ON_VARIANT_AUX(                                      \
        BOOST_PP_CAT(macro,                                                    \
                     BOOST_PP_CAT(POICA_P_ENUM_RENAME_VARIANT_KIND_,           \
                                  POICA_VARIANT_KIND(variant))),               \
        data,                                                                  \
        BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_FRONT(variant)))

#define POICA_P_ENUM_OVERLOAD_ON_VARIANT_AUX(macro, ...) macro(__VA_ARGS__)

#define POICA_P_ENUM_RENAME_VARIANT_KIND_POICA_VARIANT_EMPTY  VARIANT_EMPTY
#define POICA_P_ENUM_RENAME_VARIANT_KIND_POICA_VARIANT_SINGLE VARIANT_SINGLE
#define POICA_P_ENUM_RENAME_VARIANT_KIND_POICA_VARIANT_MANY   VARIANT_MANY

#endif // POICA_ENUM_INTROSPECTION_OVERLOAD_ON_VARIANT_H
