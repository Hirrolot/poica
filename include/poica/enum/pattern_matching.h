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

#ifndef POICA_ENUM_PATTERN_MATCHING_H
#define POICA_ENUM_PATTERN_MATCHING_H

#include <poica/enum/gen/tags.h>

#include <poica/enum/pattern_matching/aux.h>
#include <poica/enum/pattern_matching/immut.h>
#include <poica/enum/pattern_matching/mut.h>

#ifdef POICA_USE_PREFIX

#define poicaMatches   POICA_P_MATCHES
#define poicaDefault() POICA_P_DEFAULT()

#else

#define matches POICA_P_MATCHES
#define default() POICA_P_DEFAULT()

#endif

#define POICA_P_MATCHES(enum_ptr, variant_name)                                \
    ((enum_ptr)->tag == POICA_P_ENUM_VARIANT_NAME_AS_TAG(variant_name))

#define POICA_P_DEFAULT                                                        \
    /* FALLTHRU */                                                             \
    default:                                                                   \
        POICA_P_ENUM_BREAK_IF_NEEDED

#endif // POICA_ENUM_PATTERN_MATCHING_H
