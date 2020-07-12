// GADTs imitation.

#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

// Because BOOST_PP_CAT becomes blueprinted.
#define MY_CAT(a, b)     MY_CAT_AUX(a, b)
#define MY_CAT_AUX(a, b) a##b

#define ExprPair(t1, t2)                                                       \
    field(left, const struct P(Expr, t1, t2) *)                                \
        field(right, const struct P(Expr, t1, t2) *)

#define IExprBody(type)                                                        \
    P(Expr, int, type),                                                        \
        variant(P(IConst, type), int)                                          \
            variantMany(P(Add, type), ExprPair(int, type))                     \
                variantMany(P(Sub, type), ExprPair(int, int))                  \
                    variantMany(P(Mul, type), ExprPair(int, int))

#define BExprBody(type)                                                        \
    P(Expr, _Bool, type),                                                      \
        variant(P(BConst, type), _Bool)                                        \
            variantMany(P(And, type), ExprPair(_Bool, type))                   \
                variantMany(P(Or, type), ExprPair(_Bool, type))                \
                    variantMany(P(Xor, type), ExprPair(_Bool, type))           \
                        variantMany(P(Eq, type), ExprPair(type, type))

choice(IExprBody(int));
choice(IExprBody(_Bool));

#define Exprintint_INTROSPECT   POICA_CHOICE_INTROSPECT(IExprBody(int))
#define Exprint_Bool_INTROSPECT POICA_CHOICE_INTROSPECT(IExprBody(_Bool))

choice(BExprBody(int));
choice(BExprBody(_Bool));

#define Expr_Boolint_INTROSPECT   POICA_CHOICE_INTROSPECT(BExprBody(int))
#define Expr_Bool_Bool_INTROSPECT POICA_CHOICE_INTROSPECT(BExprBody(_Bool))

#define declEval(t1, t2) t1 P(eval, t1, t2)(const P(Expr, t1, t2) * expr)

#define defEval(t1, t2)                                                        \
    POICA_P_EXPAND(declEval(t1, t2){match(*expr){BOOST_PP_SEQ_FOR_EACH(        \
        GEN_CASE, (t1, t2), MY_CAT(P(Expr, t1, t2), _INTROSPECT))}})           \
                                                                               \
    POICA_FORCE_SEMICOLON

#define GEN_CASE(_r, t1t2, variant)                                            \
    BOOST_PP_CAT(GEN_CASE_, POICA_VARIANT_NAME(variant)) t1t2

#define GEN_CASE_Add_Bool(t1, t2) GEN_CASE_AUX(P(Add, t1), +, int, int)
#define GEN_CASE_Sub_Bool(t1, t2) GEN_CASE_AUX(P(Sub, t1), -, int, int)
#define GEN_CASE_Mul_Bool(t1, t2) GEN_CASE_AUX(P(Mul, t2), *, int, int)

#define GEN_CASE_Addint(t1, t2) GEN_CASE_Add_Bool(t1, t2)
#define GEN_CASE_Subint(t1, t2) GEN_CASE_Sub_Bool(t1, t2)
#define GEN_CASE_Mulint(t1, t2) GEN_CASE_Mul_Bool(t1, t2)

#define GEN_CASE_And_Bool(t1, t2) GEN_CASE_AUX(P(And, t1), &&, _Bool, _Bool)
#define GEN_CASE_Or_Bool(t1, t2)  GEN_CASE_AUX(P(Or, t1), ||, _Bool, _Bool)
#define GEN_CASE_Xor_Bool(t1, t2) GEN_CASE_AUX(P(Xor, t1), ^, _Bool, _Bool)
#define GEN_CASE_Eq_Bool(t1, t2)  GEN_CASE_AUX(P(Eq, t2), ==, t2, t2)

#define GEN_CASE_Andint(t1, t2) GEN_CASE_And_Bool(t1, t2)
#define GEN_CASE_Orint(t1, t2)  GEN_CASE_Or_Bool(t1, t2)
#define GEN_CASE_Xorint(t1, t2) GEN_CASE_Xor_Bool(t1, t2)
#define GEN_CASE_Eqint(t1, t2)  GEN_CASE_AUX(P(Eq, t2), ==, t2, t2)

#define GEN_CASE_IConstint(t1, t2)                                             \
    of(IConstint, val) {                                                       \
        return *val;                                                           \
    }
#define GEN_CASE_IConst_Bool(t1, t2)                                           \
    of(IConst_Bool, val) {                                                     \
        return *val;                                                           \
    }

#define GEN_CASE_BConstint(t1, t2)                                             \
    of(BConstint, val) {                                                       \
        return *val;                                                           \
    }
#define GEN_CASE_BConst_Bool(t1, t2)                                           \
    of(BConst_Bool, val) {                                                     \
        return *val;                                                           \
    }

#define GEN_CASE_AUX(variant_name, op, t1, t2)                                 \
    POICA_P_DEFER(ofMany)(variant_name, (left, right)) {                       \
        return P(eval, t1, t2)(*left) op P(eval, t1, t2)(*right);              \
    }

declEval(int, _Bool);
declEval(int, int);
declEval(_Bool, _Bool);
declEval(_Bool, int);

defEval(int, _Bool);
defEval(int, int);
defEval(_Bool, _Bool);
defEval(_Bool, int);

int main(void) {
    const P(Expr, _Bool, _Bool) true_node = P(BConst, _Bool)(true);
    const P(Expr, _Bool, int) false_node = P(BConst, int)(false);

    const P(Expr, int, int) _12_node = P(IConst, int)(12);

    // 12 == 12 == true
    const P(Expr, _Bool, int) eq_node = P(Eq, int)(&_12_node, &_12_node);

    // true && false == false
    P(Expr, _Bool, int) expr = P(And, int)(&eq_node, &false_node);

    _Bool res = P(eval, _Bool, int)(&expr);

    /*
     * Output:
     * 0
     */
    printf("%d\n", (int)res);
}
