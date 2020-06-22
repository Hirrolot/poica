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

#ifndef POICA_ENUM_VARIANT_H
#define POICA_ENUM_VARIANT_H

#include <poica/record/field.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX
#define poicaVariant     POICA_P_VARIANT
#define poicaVariantMany POICA_P_VARIANT_KIND_MANY
#else
#define variant     POICA_P_VARIANT
#define variantMany POICA_P_VARIANT_KIND_MANY
#endif

#define POICA_P_VARIANT(...)                                                   \
    BOOST_PP_OVERLOAD(POICA_P_VARIANT_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_VARIANT_KIND_MANY(variant_name, fields)                        \
    ((POICA_VARIANT_KIND_MANY)(variant_name)(fields))

#define POICA_P_VARIANT_1(variant_name)                                        \
    ((POICA_VARIANT_KIND_EMPTY)(variant_name))

#define POICA_P_VARIANT_2(variant_name, variant_type)                          \
    ((POICA_VARIANT_KIND_SINGLE)(variant_name)(variant_type))

#endif // POICA_ENUM_VARIANT_H
