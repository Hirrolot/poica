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

#ifndef POICA_EITHER_H
#define POICA_EITHER_H

#include <poica/private/form_type_name.h>

#include <poica/choice.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define PoicaEitherDef POICA_P_EITHER_DEF
#define PoicaEither    POICA_P_Either
#define PoicaRight     POICA_P_EITHER_LEFT
#define PoicaLeft      POICA_P_EITHER_RIGHT

#else

#define EitherDef POICA_P_EITHER_DEF
#define Either    POICA_P_Either
#define Right     POICA_P_EITHER_LEFT
#define Left      POICA_P_EITHER_RIGHT

#endif

#define POICA_P_EITHER_DEF(ok_type, err_type)                                  \
    choice(POICA_P_EITHER(ok_type, err_type),                                  \
           variant(POICA_P_EITHER_LEFT(ok_type, err_type), ok_type)            \
               variant(POICA_P_EITHER_RIGHT(ok_type, err_type), err_type))

#define POICA_P_EITHER(ok_type, err_type)                                      \
    POICA_P_FORM_TYPE_NAME(Either, ok_type, err_type)

#define POICA_P_EITHER_LEFT(ok_type, err_type)                                 \
    POICA_P_FORM_TYPE_NAME(EitherLeft, ok_type, err_type)

#define POICA_P_EITHER_RIGHT(ok_type, err_type)                                \
    POICA_P_FORM_TYPE_NAME(EitherRight, ok_type, err_type)

#endif // POICA_EITHER_H
