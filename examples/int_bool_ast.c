// GADTs imitation.

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

int evalExpr(const Expr *expr) {
    match(*expr) {
        of(IConst, number) {
            return *number;
        }
        ofMany(Add, (left, right)) {
            return evalExpr(*left) + evalExpr(*right);
        }
        ofMany(Sub, (left, right)) {
            return evalExpr(*left) - evalExpr(*right);
        }
        ofMany(Mul, (left, right)) {
            return evalExpr(*left) * evalExpr(*right);
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

int main(void) {
    const P(Expr, Expr) true_node = P(BConst, Expr)(true);
    const P(Expr, Expr) false_node = P(BConst, Expr)(false);

    const Expr _12_node = IConst(12);

    // 12 == 12 == true
    const P(Expr, Expr) eq_node = P(Eq, Expr)(&_12_node, &_12_node);

    // true && false == false
    P(Expr, P(Expr, Expr)) expr = P(And, P(Expr, Expr))(&eq_node, &false_node);

    _Bool res = P(eval, P(Expr, P(Expr, Expr)))(&expr);

    /*
     * Output:
     * 0
     */
    printf("%d\n", (int)res);
}
