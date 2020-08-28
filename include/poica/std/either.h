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

#ifndef POICA_STD_EITHER_H
#define POICA_STD_EITHER_H

#include <poica/lang/choice.h>
#include <poica/lang/force_semicolon.h>
#include <poica/lang/p.h>

#include <stdbool.h>

#ifndef POICA_USE_PREFIX

#define DefEither PoicaDefEither

#endif

#define PoicaDefEither(left_type, right_type)                                                      \
    poicaChoice(PoicaP(Either, left_type, right_type),                                             \
                poicaVariant(PoicaP(Left, left_type, right_type), left_type)                       \
                    poicaVariant(PoicaP(Right, left_type, right_type), right_type));               \
                                                                                                   \
    inline static bool PoicaP(isLeft, left_type, right_type)(PoicaP(Either, left_type, right_type) \
                                                                 either) {                         \
        return poicaMatches(either, PoicaP(Left, left_type, right_type));                          \
    }                                                                                              \
                                                                                                   \
    inline static bool PoicaP(isRight, left_type, right_type)(                                     \
        PoicaP(Either, left_type, right_type) either) {                                            \
        return poicaMatches(either, PoicaP(Right, left_type, right_type));                         \
    }                                                                                              \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#endif // POICA_STD_EITHER_H
