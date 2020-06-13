#include <poica.h>

#include <stdio.h>

// clang-format off
PRODUCT(
    ExprPair,
    FIELD(left OF const struct Expr *)
    FIELD(right OF const struct Expr *)
);

SUM(
    Expr,
    VARIANT(MkConst OF double)
    VARIANT(MkAdd OF ExprPair)
    VARIANT(MkSub OF ExprPair)
    VARIANT(MkMul OF ExprPair)
    VARIANT(MkDiv OF ExprPair)
);
// clang-format on

double eval(const Expr *expr) {
    MATCH(expr) {
        CASE(MkConst, number) {
            return *number;
        }
        CASE(MkAdd, add) {
            return eval(add->left) + eval(add->right);
        }
        CASE(MkSub, sub) {
            return eval(sub->left) - eval(sub->right);
        }
        CASE(MkMul, mul) {
            return eval(mul->left) * eval(mul->right);
        }
        CASE(MkDiv, div) {
            return eval(div->left) / eval(div->right);
        }
    }
}

#define EXPR(expr)          OBJ(expr OF Expr)
#define OP(op, left, right) Mk##op((ExprPair){EXPR(left), EXPR(right)})

int main(void) {
    Expr expr = OP(Add,
                   MkConst(53),
                   OP(Sub, OP(Div, MkConst(155), MkConst(5)), MkConst(113)));

    /*
     * Output:
     * -29.000000
     */
    printf("%f\n", eval(&expr));
}

#undef EXPR
#undef OP
