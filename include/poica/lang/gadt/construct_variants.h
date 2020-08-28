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
#ifndef POICA_LANG_GADT_CONSTRUCT_VARIANTS_H

#define POICA_LANG_GADT_CONSTRUCT_VARIANTS_H

#include <poica/lang/gadt/variant.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define BOOST_VMD_REGISTER_of   (of)
#define BOOST_VMD_REGISTER_self (self)

#define BOOST_VMD_DETECT_of_of
#define BOOST_VMD_DETECT_self_self

#define POICA_P_LANG_GADT_CONSTRUCT_VARIANTS(variants)                                             \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_GADT_CONSTRUCT_VARIANTS_VISIT, BOOST_PP_EMPTY(), variants)

#define POICA_P_LANG_GADT_CONSTRUCT_VARIANTS_VISIT(_r, _data, gadt_variant)                        \
    POICA_P_LANG_GADT_VARIANT(BOOST_VMD_ELEM(0, gadt_variant), BOOST_VMD_ELEM(3, gadt_variant))

#endif // POICA_LANG_GADT_CONSTRUCT_VARIANTS_H
