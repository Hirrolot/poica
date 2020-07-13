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

/* GADTs imitation.
 *
 * Given a simple language, consisting of arithmetical and boolean expressions,
 * and a type-safe evaluator.
 *
 * More information at https://en.wikibooks.org/wiki/Haskell/GADT.
 */

#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define ExprPair(expr_type)                                                    \
    field(left, const struct expr_type *) field(right, const struct expr_type *)

#define IExprPair ExprPair(Expr)

// clang-format off
choice(
    Expr,
    variant(IConst, int)
    variantMany(Add, IExprPair)
    variantMany(Sub, IExprPair)
    variantMany(Mul, IExprPair)
);
// clang-format on

int P(eval, Expr)(const Expr *expr) {
    match(*expr) {
        of(IConst, number) {
            return *number;
        }
        ofMany(Add, (left, right)) {
            return P(eval, Expr)(*left) + P(eval, Expr)(*right);
        }
        ofMany(Sub, (left, right)) {
            return P(eval, Expr)(*left) - P(eval, Expr)(*right);
        }
        ofMany(Mul, (left, right)) {
            return P(eval, Expr)(*left) * P(eval, Expr)(*right);
        }
    }
}

// clang-format off
#define DefBExpr(type)                                                         \
    choice(                                                                    \
        P(Expr, type),                                                         \
        variant(P(BConst, type), _Bool)                                        \
        variantMany(P(And, type), ExprPair(type))                              \
        variantMany(P(Or, type), ExprPair(type))                               \
        variantMany(P(Xor, type), ExprPair(type))                              \
        variantMany(P(Eq, type), ExprPair(type))                               \
    )
// clang-format on

#define declEvalBExpr(type)                                                    \
    _Bool P(eval, P(Expr, type))(const P(Expr, type) * expr)
#define defEvalBExpr(type)                                                     \
    declEvalBExpr(type) {                                                      \
        match(*expr) {                                                         \
            of(P(BConst, type), boolean) {                                     \
                return *boolean;                                               \
            }                                                                  \
            ofMany(P(And, type), (left, right)) {                              \
                return P(eval, type)(*left) && P(eval, type)(*right);          \
            }                                                                  \
            ofMany(P(Or, type), (left, right)) {                               \
                return P(eval, type)(*left) || P(eval, type)(*right);          \
            }                                                                  \
            ofMany(P(Xor, type), (left, right)) {                              \
                return P(eval, type)(*left) ^ P(eval, type)(*right);           \
            }                                                                  \
            ofMany(P(Eq, type), (left, right)) {                               \
                return P(eval, type)(*left) == P(eval, type)(*right);          \
            }                                                                  \
        }                                                                      \
    }

DefBExpr(Expr);
DefBExpr(P(Expr, Expr));

defEvalBExpr(Expr);
defEvalBExpr(P(Expr, Expr));

// (12 == 12) && false
int main(void) {
    const P(Expr, Expr) _false = P(BConst, Expr)(false);
    const Expr _12 = IConst(12);

    const P(Expr, Expr) eq = P(Eq, Expr)(&_12, &_12);
    P(Expr, P(Expr, Expr)) expr = P(And, P(Expr, Expr))(&eq, &_false);

    _Bool res = P(eval, P(Expr, P(Expr, Expr)))(&expr);

    /*
     * Output:
     * 0
     */
    printf("%d\n", (int)res);
}
