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

#ifdef POICA_USE_PREFIX
#define PoicaDefRes POICA_P_LANG_RES_DEF
#else
#define DefRes POICA_P_LANG_RES_DEF
#endif

#define POICA_P_LANG_RES_DEF(ok_type, err_type)                                \
    POICA_P_LANG_CHOICE(                                                       \
        POICA_P_LANG_P(Res, ok_type, err_type),                                \
        POICA_P_LANG_VARIANT(POICA_P_LANG_P(Ok, ok_type, err_type), ok_type)   \
            POICA_P_LANG_VARIANT(POICA_P_LANG_P(Err, ok_type, err_type),       \
                                 err_type));                                   \
                                                                               \
    inline static bool POICA_P_LANG_P(isOk, ok_type, err_type)(                \
        POICA_P_LANG_P(Res, ok_type, err_type) res) {                          \
        return POICA_P_LANG_MATCHES(res,                                       \
                                    POICA_P_LANG_P(Ok, ok_type, err_type));    \
    }                                                                          \
                                                                               \
    inline static bool POICA_P_LANG_P(isErr, ok_type, err_type)(               \
        POICA_P_LANG_P(Res, ok_type, err_type) res) {                          \
        return POICA_P_LANG_MATCHES(res,                                       \
                                    POICA_P_LANG_P(Err, ok_type, err_type));   \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

#endif // POICA_STD_RES_H