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

#ifndef POICA_BUILTIN_RES_H
#define POICA_BUILTIN_RES_H

#include <poica/private/monomorphize.h>

#include <poica/choice.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define PoicaDefRes POICA_P_RES_DEF
#define PoicaRes    POICA_P_RES
#define PoicaOk     POICA_P_RES_OK
#define PoicaErr    POICA_P_RES_ERR

#else

#define DefRes POICA_P_RES_DEF
#define Res    POICA_P_RES
#define Ok     POICA_P_RES_OK
#define Err    POICA_P_RES_ERR

#endif

#define POICA_P_RES_DEF(ok_type, err_type)                                     \
    choice(POICA_P_RES(ok_type, err_type),                                     \
           variant(POICA_P_RES_OK(ok_type, err_type), ok_type)                 \
               variant(POICA_P_RES_ERR(ok_type, err_type), err_type))

#define POICA_P_RES(ok_type, err_type)                                         \
    POICA_P_MONOMORPHIZE(Res, ok_type, err_type)

#define POICA_P_RES_OK(ok_type, err_type)                                      \
    POICA_P_MONOMORPHIZE(ResOk, ok_type, err_type)

#define POICA_P_RES_ERR(ok_type, err_type)                                     \
    POICA_P_MONOMORPHIZE(ResErr, ok_type, err_type)

#endif // POICA_BUILTIN_RES_H
