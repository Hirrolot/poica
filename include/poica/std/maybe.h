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

#ifndef POICA_STD_MAYBE_H
#define POICA_STD_MAYBE_H

#include <poica/lang/force_semicolon.h>
#include <poica/lang/p.h>

#include <poica/lang/choice.h>

#include <stdbool.h>

#ifndef POICA_USE_PREFIX

#define DefMaybe PoicaDefMaybe

#endif

#define PoicaDefMaybe(type)                                                                        \
    poicaChoice(PoicaP(Maybe, type),                                                               \
                poicaVariant(PoicaP(Just, type), type) poicaVariant(PoicaP(Nothing, type)));       \
                                                                                                   \
    inline static bool PoicaP(isJust, type)(PoicaP(Maybe, type) maybe) {                           \
        return poicaMatches(maybe, PoicaP(Just, type));                                            \
    }                                                                                              \
                                                                                                   \
    inline static bool PoicaP(isNothing, type)(PoicaP(Maybe, type) maybe) {                        \
        return poicaMatches(maybe, PoicaP(Nothing, type));                                         \
    }                                                                                              \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#endif // POICA_STD_MAYBE_H
