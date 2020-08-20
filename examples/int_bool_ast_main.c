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

#include <stdbool.h>
#include <stdio.h>

#define BOOST_VMD_REGISTER_int   (int)
#define BOOST_VMD_REGISTER__Bool (_Bool)

#define BOOST_VMD_DETECT_int_int
#define BOOST_VMD_DETECT__Bool__Bool

#define T int
#include "int_bool_ast.h"
#undef T

#define T _Bool
#include "int_bool_ast.h"
#undef T

int main(void) {
    P(Expr, int) _12 = P(I, int)(12);
    P(Expr, int) _4 = P(I, int)(4);
    P(Expr, int) _3 = P(I, int)(3);
    P(Expr, int) _12_add_4 = P(Add, int)(&_12, &_4);
    P(Expr, int, _Bool) final = P(Eq, int, _Bool)(&_12_add_4, &_3);

    printf("%d\n", (int)P(eval, _Bool)(&final));
}
