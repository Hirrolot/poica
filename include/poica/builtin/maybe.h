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

#ifndef POICA_BUILTIN_MAYBE_H
#define POICA_BUILTIN_MAYBE_H

#include <poica/private/form_type_name.h>

#include <poica/choice.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define PoicaDefMaybe POICA_P_MAYBE_DEF
#define PoicaMaybe    POICA_P_MAYBE
#define PoicaJust     POICA_P_MAYBE_JUST
#define PoicaNothing  POICA_P_MAYBE_NOTHING

#else

#define DefMaybe POICA_P_MAYBE_DEF
#define Maybe    POICA_P_MAYBE
#define Just     POICA_P_MAYBE_JUST
#define Nothing  POICA_P_MAYBE_NOTHING

#endif

#define POICA_P_MAYBE_DEF(type)                                                \
    choice(POICA_P_MAYBE(type),                                                \
           variant(POICA_P_MAYBE_JUST(type), type)                             \
               variant(POICA_P_MAYBE_NOTHING(type)))

#define POICA_P_MAYBE(type)      POICA_P_FORM_TYPE_NAME(Maybe, ok_type)
#define POICA_P_MAYBE_JUST(type) POICA_P_FORM_TYPE_NAME(MaybeJust, ok_type)
#define POICA_P_MAYBE_NOTHING(type)                                            \
    POICA_P_FORM_TYPE_NAME(MaybeNothing, ok_type)

#endif // POICA_BUILTIN_MAYBE_H
