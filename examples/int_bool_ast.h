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
