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

#ifndef POICA_STD_RES_H
#define POICA_STD_RES_H

#include <poica/lang/force_semicolon.h>
#include <poica/lang/p.h>

#include <poica/lang/choice.h>

#include <stdbool.h>

#ifndef POICA_USE_PREFIX

#define DefRes PoicaDefRes

#endif

#define PoicaDefRes(ok_type, err_type)                                                             \
    poicaChoice(PoicaP(Res, ok_type, err_type),                                                    \
                poicaVariant(PoicaP(Ok, ok_type, err_type), ok_type)                               \
                    poicaVariant(PoicaP(Err, ok_type, err_type), err_type));                       \
                                                                                                   \
    inline static bool PoicaP(isOk, ok_type, err_type)(PoicaP(Res, ok_type, err_type) res) {       \
        return poicaMatches(res, PoicaP(Ok, ok_type, err_type));                                   \
    }                                                                                              \
                                                                                                   \
    inline static bool PoicaP(isErr, ok_type, err_type)(PoicaP(Res, ok_type, err_type) res) {      \
        return poicaMatches(res, PoicaP(Err, ok_type, err_type));                                  \
    }                                                                                              \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#endif // POICA_STD_RES_H
