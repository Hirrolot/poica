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

#ifndef POICA_CHOICE_TRY_H
#define POICA_CHOICE_TRY_H

#include <poica/choice/pattern_matching.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define poicaTry(choice_ptr, case_expr, failure_expr)                          \
    POICA_P_TRY(const, choice_ptr, case_expr, failure_expr)
#define poicaTryMut(choice_ptr, case_expr, failure_expr)                       \
    POICA_P_TRY(, choice_ptr, case_expr, failure_expr)

#else

// clang-format off
#define try(choice_ptr, case_expr, failure_expr)                                \
    POICA_P_TRY(const, choice_ptr, case_expr, failure_expr)
// clang-format on

#define tryMut(choice_ptr, case_expr, failure_expr)                            \
    POICA_P_TRY(, choice_ptr, case_expr, failure_expr)

#endif

#define POICA_P_TRY(qualifier, choice_ptr, case_expr, failure_expr)            \
    POICA_P_MATCH(qualifier, choice_ptr) {                                     \
        case_expr {                                                            \
            return failure_expr;                                               \
        }                                                                      \
        POICA_P_OTHERWISE {}                                                   \
    }

#endif // POICA_CHOICE_TRY_H
