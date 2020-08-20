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

#ifndef POICA_STDLIB_MAYBE_H
#define POICA_STDLIB_MAYBE_H

#include <poica/lang/force_semicolon.h>
#include <poica/lang/p.h>

#include <poica/lang/choice.h>

#include <stdbool.h>

#ifdef POICA_USE_PREFIX
#define PoicaDefMaybe POICA_P_STDLIB_MAYBE_DEF
#else
#define DefMaybe POICA_P_STDLIB_MAYBE_DEF
#endif

#define POICA_P_STDLIB_MAYBE_DEF(type)                                         \
    POICA_P_LANG_CHOICE(                                                       \
        POICA_P_LANG_P(Maybe, type),                                           \
        POICA_P_LANG_VARIANT(POICA_P_LANG_P(Just, type), type)                 \
            POICA_P_LANG_VARIANT(POICA_P_LANG_P(Nothing, type)));              \
                                                                               \
    inline static bool POICA_P_LANG_P(isJust, type)(                           \
        POICA_P_LANG_P(Maybe, type) maybe) {                                   \
        return POICA_P_LANG_MATCHES(maybe, POICA_P_LANG_P(Just, type));        \
    }                                                                          \
                                                                               \
    inline static bool POICA_P_LANG_P(isNothing, type)(                        \
        POICA_P_LANG_P(Maybe, type) maybe) {                                   \
        return POICA_P_LANG_MATCHES(maybe, POICA_P_LANG_P(Nothing, type));     \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

#endif // POICA_STDLIB_MAYBE_H
