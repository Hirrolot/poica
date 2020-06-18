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

#ifndef POICA_SUM_GEN_REDIRECTS_TO_OUTER_SUM_TYPE_H
#define POICA_SUM_GEN_REDIRECTS_TO_OUTER_SUM_TYPE_H

#include <poica/private/aux.h>

#include <poica/sum/variant.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_OUTER_SUM_TYPE(sum_name,          \
                                                            variants)          \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE,  \
                          sum_name,                                            \
                          variants)

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(                    \
    _r, sum_name, variant)                                                     \
    typedef sum_name POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(           \
        VARIANT_NAME(variant));

#define POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(variant_name)           \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToOuterSumType))

#endif // POICA_SUM_GEN_REDIRECTS_TO_OUTER_SUM_TYPE_H
