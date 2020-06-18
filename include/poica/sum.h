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

#ifndef POICA_SUM_H
#define POICA_SUM_H

#include <poica/private/aux.h>

#include <poica/keywords.h>
#include <poica/product/field.h>

#include <poica/sum/gen/fields.h>
#include <poica/sum/gen/redirects.h>
#include <poica/sum/gen/tags.h>
#include <poica/sum/gen/variant_many.h>
#include <poica/sum/gen/vconstrs.h>
#include <poica/sum/pattern_matching.h>
#include <poica/sum/try.h>
#include <poica/sum/variant.h>

#include <boost/preprocessor.hpp>

#define SUM(...) POICA_P_SUM_AUX(__VA_ARGS__)

#define POICA_P_SUM_AUX(name, variants)                                        \
    POICA_P_SUM_GEN_VARIANT_MANY_PRODUCTS(variants)                            \
                                                                               \
    typedef struct name {                                                      \
        enum { POICA_P_SUM_GEN_TAGS(variants) } tag;                           \
        struct {                                                               \
            POICA_P_SUM_GEN_FIELDS(variants)                                   \
        } data;                                                                \
    } name;                                                                    \
                                                                               \
    POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_INNER_TYPE(variants)                  \
    POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_OUTER_SUM_TYPE(name, variants)        \
    POICA_P_SUM_GEN_VCONSTRS(name, variants)                                   \
                                                                               \
    POICA_P_USELESS_TYPEDEF(name)

#endif // POICA_SUM_H
