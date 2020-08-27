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

#ifndef POICA_LANG_ASSERTIONS_VARIANTS_H
#define POICA_LANG_ASSERTIONS_VARIANTS_H

#include <poica/lang/private/defer.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#ifdef POICA_ENABLE_ASSERTIONS

#define POICA_P_LANG_OPT_ASSERT_ARE_VARIANTS(variants) POICA_ASSERT_ARE_VARIANTS(variants)
#define POICA_P_LANG_OPT_ASSERT_IS_VARIANT(variant)    POICA_ASSERT_IS_VARIANT(variant)

#else

#define POICA_P_LANG_OPT_ASSERT_ARE_VARIANTS(_variants) BOOST_PP_EMPTY()
#define POICA_P_LANG_OPT_ASSERT_IS_VARIANT(_variant)    BOOST_PP_EMPTY()

#endif

#define POICA_ASSERT_ARE_VARIANTS(variants)                                                        \
    BOOST_VMD_ASSERT_IS_SEQ(variants)                                                              \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_ASSERT_IS_VARIANTS_VISIT, BOOST_PP_EMPTY(), variants)

#define POICA_P_LANG_ASSERT_IS_VARIANTS_VISIT(_r, _data, variant) POICA_ASSERT_IS_VARIANT((variant))

/* TODO: Maybe test each kind of `variant`? BOOST_VMD_EQUAL produces UB if
 * encounters a data type that it cannot parse, so we can't use it to match the
 * first element of `variant`'s sequence, which is its kind.
 */
#define POICA_ASSERT_IS_VARIANT(variant)                                                           \
    BOOST_VMD_ASSERT_IS_SEQ(POICA_P_LANG_EXPAND variant)                                           \
    POICA_ASSERT_IS_VARIANT_CHECK_MIN_VARIANT_SIZE(variant)

// variant(<variant-name>) produces a variant of length 2.
#define POICA_LANG_ASSERT_IS_VARIANT_CHECK_MIN_VARIANT_SIZE(variant)                               \
    BOOST_VMD_ASSERT(BOOST_PP_GREATER_EQUAL(BOOST_PP_SEQ_SIZE(POICA_P_LANG_EXPAND variant), 2))

#endif // POICA_LANG_ASSERTIONS_VARIANTS_H
