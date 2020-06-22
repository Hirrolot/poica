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

#ifndef POICA_CHOICE_PATTERN_MATCHING_IMMUT_H
#define POICA_CHOICE_PATTERN_MATCHING_IMMUT_H

#include <poica/choice/pattern_matching/aux.h>

#ifdef POICA_USE_PREFIX

#define poicaMatch(choice_ptr) POICA_P_MATCH(const, choice_ptr)
#define poicaOfMany(variant_name, var_names)                                   \
    POICA_P_OF_MANY(const, variant_name, var_names)
#define poicaOf(...) POICA_P_OF(const, __VA_ARGS__)

#else

#define match(choice_ptr) POICA_P_MATCH(const, choice_ptr)
#define ofMany(variant_name, var_names)                                        \
    POICA_P_OF_MANY(const, variant_name, var_names)
#define of(...) POICA_P_OF(const, __VA_ARGS__)

#endif

#endif // POICA_CHOICE_PATTERN_MATCHING_IMMUT_H