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
 * Let us have a simple arithmetical language, consisting of:
 *
 *  1) Constants of double;
 *  2) Expressions: either expr1 (+ | - | * | /) expr2 or a constant.
 *
 *
 * A sum type can be used to represent the hierarchical structure of ASTs, and
 * pattern matching is a technique to evaluate them.
 */

#include <poica.h>

#include <stdio.h>

#define EXPR_PAIR                                                              \
    field(left, const struct Expr *) field(right, const struct Expr *)

// clang-format off
choice(
    Expr,
    variant(Const, double)
    variantMany(Add, EXPR_PAIR)
    variantMany(Sub, EXPR_PAIR)
    variantMany(Mul, EXPR_PAIR)
    variantMany(Div, EXPR_PAIR)
);
// clang-format on

double eval(const Expr *expr) {
    match(*expr) {
        of(Const, number) {
            return *number;
        }
        ofMany(Add, (left, right)) {
            return eval(*left) + eval(*right);
        }
        ofMany(Sub, (left, right)) {
            return eval(*left) - eval(*right);
        }
        ofMany(Mul, (left, right)) {
            return eval(*left) * eval(*right);
        }
        ofMany(Div, (left, right)) {
            return eval(*left) / eval(*right);
        }
    }
}

#define EXPR(expr)          obj(expr, Expr)
#define OP(op, left, right) op(EXPR(left), EXPR(right))

int main(void) {
    Expr expr =
        OP(Add, Const(53), OP(Sub, OP(Div, Const(155), Const(5)), Const(113)));

    /*
     * Output:
     * -29.000000
     */
    printf("%f\n", eval(&expr));
}

#undef EXPR
#undef OP
