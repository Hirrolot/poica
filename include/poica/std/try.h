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

/*
 * This macro is used to concisely pass an error upwards a program stack, or, if
 * the result is successful, do nothing.
 */

#ifndef POICA_STD_TRY_H
#define POICA_STD_TRY_H

#include <poica/lang/choice/pattern_matching.h>
#include <poica/std/res.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define poicaTry(val, ok_type_1, ok_type_2, err_type)                          \
    POICA_P_STD_TRY(val, ok_type_1, ok_type_2, err_type)

#else

// clang-format off
#define try(val, ok_type_1, ok_type_2, err_type)                               \
    POICA_P_STD_TRY(val, ok_type_1, ok_type_2, err_type)
// clang-format on

#endif

#define POICA_P_STD_TRY(val, ok_type_1, ok_type_2, err_type)                   \
    POICA_P_LANG_MATCH(val) {                                                  \
        POICA_P_LANG_OF(                                                       \
            const, POICA_P_LANG_P(Err, ok_type_1, err_type), err) {            \
            return POICA_P_LANG_P(Err, ok_type_2, err_type)(*err);             \
        }                                                                      \
        POICA_P_LANG_OTHERWISE {}                                              \
    }

#endif // POICA_STD_TRY_H
