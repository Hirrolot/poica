# poica

## Algebraic data types

[[`examples/ast_evaluator.c`](https://github.com/Hirrolot/poica/blob/master/examples/ast_evaluator.c)]
```c
#include "../src/obj.h"
#include "../src/sum_type.h"

#include <stdio.h>

typedef struct {
    const struct Expr *left, *right;
} ExprPair;

SUM(
    Expr,
    VARIANT(MkConst OF double)
    VARIANT(MkAdd OF ExprPair)
    VARIANT(MkSub OF ExprPair)
    VARIANT(MkMul OF ExprPair)
    VARIANT(MkDiv OF ExprPair)
);

double eval(const struct Expr *expr) {
    MATCH(expr) {
        CASE(MkConst, number) { return *number; }
        CASE(MkAdd, add) { return eval(add->left) + eval(add->right); }
        CASE(MkSub, sub) { return eval(sub->left) - eval(sub->right); }
        CASE(MkMul, mul) { return eval(mul->left) * eval(mul->right); }
        CASE(MkDiv, div) { return eval(div->left) / eval(div->right); }
    }
}

#define OP(op, left, right)                                                    \
    Mk##op((ExprPair){OBJ(left OF struct Expr), OBJ(right OF struct Expr)})

int main(void) {
    Expr expr = OP(Add, MkConst(53),
                   OP(Sub, OP(Div, MkConst(155), MkConst(5)), MkConst(113)));

    /*
     * Output:
     * -29.000000
     */
    printf("%f\n", eval(&expr));
}
```
