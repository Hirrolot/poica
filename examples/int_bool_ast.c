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

// TODO: finish it.
/*
#include <poica.h>

#include <stdio.h>

#define ExprPair(inner_val_ty, reduced_val_ty)                                 \
    field(left, const struct P(Expr, inner_val_ty, reduced_val_ty) *)          \
        field(right, const struct P(Expr, inner_val_ty, reduced_val_ty) *)

#define DefExpr(inner_val_ty, reduced_val_ty)                                  \
    gadt(Expr,                                                                 \
         variant(I, int) of self(inner_val_ty, int),                           \
         variant(B, _Bool) of self(inner_val_ty, _Bool),                       \
         variantMany(Add, ExprPair(inner_val_ty, int))                         \
             of self(inner_val_ty, int),                                       \
         variantMany(Mul, ExprPair(inner_val_ty, int))                         \
             of self(inner_val_ty, int),                                       \
         variantMany(Eq, ExprPair(inner_val_ty, reduced_val_ty))               \
             of self(inner_val_ty, _Bool));                                    \
                                                                               \
    reduced_val_ty P(eval, inner_val_ty, reduced_val_ty)(                      \
        const P(Expr, inner_val_ty, reduced_val_ty) * expr) {                  \
        matchGadt(                                                             \
            *expr,                                                             \
            gadtOf(I, number) of self(inner_val_ty, int) do(return *number;),  \
            gadtOf(B, boolean)                                                 \
                of self(inner_val_ty, _Bool) do(return *boolean;),             \
            gadtOfMany(Add, (left, right)) of self(inner_val_ty, int) do(      \
                return P(eval, inner_val_ty, int)(*left) +                     \
                           P(eval, inner_val_ty, int)(*right);),               \
            gadtOfMany(Mul, (left, right)) of self(inner_val_ty, int) do(      \
                return P(eval, inner_val_ty, int)(*left) *                     \
                           P(eval, inner_val_ty, int)(*right);),               \
            gadtOfMany(Eq, (left, right)) of self(inner_val_ty, _Bool) do(     \
                return P(eval, inner_val_ty, _Bool)(*left) ==                  \
                           P(eval, inner_val_ty, _Bool)(*right);))             \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

#define BOOST_VMD_REGISTER_int   (int)
#define BOOST_VMD_REGISTER__Bool (_Bool)

#define BOOST_VMD_DETECT_int_int
#define BOOST_VMD_DETECT__Bool__Bool

DefExpr(int, int);
DefExpr(int, _Bool);

int main(void) {
    // (12 + 4) == 3, which is false, as expected.
    P(Expr, int, int) _12 = P(I, int, int)(12);
    P(Expr, int, int) _4 = P(I, int, int)(4);
    P(Expr, int, int) _3 = P(I, int, int)(3);
    P(Expr, int, int) _12_add_4 = P(Add, int, int)(&_12, &_4);
    P(Expr, int, _Bool) final = P(Eq, int, _Bool)(&_12_add_4, &_3);

    printf("%d\n", (int)P(eval, int, _Bool)(&final));
}
*/

int main(void) {}
