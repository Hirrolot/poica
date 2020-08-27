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

#include <poica.h>

#ifndef EXPR_PAIR_DEFINED
#define EXPR_PAIR_DEFINED

#define ExprPair(expr_t)                                                       \
    field(left, const struct P(Expr, expr_t) *)                                \
        field(right, const struct P(Expr, expr_t) *)

#endif

// clang-format off
gadt(
    Expr,

#ifndef EXPR_INT_BOOL_DEFINED
#define EXPR_INT_BOOL_DEFINED
    variant(I, int) of self(int),
    variant(B, _Bool) of self(_Bool),
    variantMany(Add, ExprPair(int)) of self(int),
    variantMany(Mul, ExprPair(int)) of self(int),
#endif

variantMany(Eq, ExprPair(T)) of self(T, _Bool)
);
// clang-format on

T P(eval, T)(const P(Expr, T) * expr) {
    matchGadt(
        *expr,
        gadtOf(I, number) of self(int) do(return *number;),
        gadtOf(B, boolean) of self(_Bool) do(return *boolean;),
        gadtOfMany(Add, (left, right))
            of self(int) do(return P(eval, T)(*left) + P(eval, T)(*right);),
        gadtOfMany(Mul, (left, right))
            of self(int) do(return P(eval, T)(*left) * P(eval, T)(*right);),
        gadtOfMany(Eq, (left, right)) of self(T, _Bool) do(
            return P(eval, T)(*left) == P(eval, T)(*right);))
}
