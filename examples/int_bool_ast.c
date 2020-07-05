// GADTs imitation.

#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

// Because BOOST_PP_CAT becomes blueprinted.
#define MY_CAT(a, b)     MY_CAT_AUX(a, b)
#define MY_CAT_AUX(a, b) a##b

#define Expr(t1, t2) POICA_MONOMORPHISE(Expr, t1, t2)

#define DefExprPair(t1, t2)                                                    \
    record(ExprPair(t1, t2),                                                   \
           field(left, const struct Expr(t1, t2) *)                            \
               field(right, const struct Expr(t1, t2) *))
#define ExprPair(t1, t2) POICA_MONOMORPHISE(ExprPair, t1, t2)

DefExprPair(int, _Bool);
DefExprPair(int, int);
DefExprPair(_Bool, int);
DefExprPair(_Bool, _Bool);

#define IExprBody(type)                                                        \
    Expr(int, type),                                                           \
        variant(IConst(type), int) variant(Add(type), ExprPair(int, type))     \
            variant(Sub(type), ExprPair(int, int))                             \
                variant(Mul(type), ExprPair(int, int))

#define IConst(type) POICA_MONOMORPHISE(IConst, type)
#define Add(type)    POICA_MONOMORPHISE(Add, type)
#define Sub(type)    POICA_MONOMORPHISE(Sub, type)
#define Mul(type)    POICA_MONOMORPHISE(Mul, type)

#define BExprBody(type)                                                        \
    Expr(_Bool, type),                                                         \
        variant(BConst(type), _Bool) variant(And(type), ExprPair(_Bool, type)) \
            variant(Or(type), ExprPair(_Bool, type))                           \
                variant(Xor(type), ExprPair(_Bool, type))                      \
                    variant(Eq(type), ExprPair(type, type))

#define BConst(type) POICA_MONOMORPHISE(BConst, type)
#define And(type)    POICA_MONOMORPHISE(And, type)
#define Or(type)     POICA_MONOMORPHISE(Or, type)
#define Xor(type)    POICA_MONOMORPHISE(Xor, type)
#define Eq(type)     POICA_MONOMORPHISE(Eq, type)

choice(IExprBody(int));
choice(IExprBody(_Bool));

#define Exprintint_INTROSPECT   POICA_CHOICE_INTROSPECT(IExprBody(int))
#define Exprint_Bool_INTROSPECT POICA_CHOICE_INTROSPECT(IExprBody(_Bool))

choice(BExprBody(int));
choice(BExprBody(_Bool));

#define Expr_Boolint_INTROSPECT   POICA_CHOICE_INTROSPECT(BExprBody(int))
#define Expr_Bool_Bool_INTROSPECT POICA_CHOICE_INTROSPECT(BExprBody(_Bool))

#define declEval(t1, t2) t1 eval(t1, t2)(const Expr(t1, t2) * expr)

#define defEval(t1, t2)                                                        \
    declEval(t1, t2) {                                                         \
        match(*expr) {                                                         \
            BOOST_PP_SEQ_FOR_EACH(                                             \
                GEN_CASE, (t1, t2), MY_CAT(Expr(t1, t2), _INTROSPECT))         \
        }                                                                      \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

#define eval(t1, t2) POICA_MONOMORPHISE(eval, t1, t2)

#define GEN_CASE(_r, t1t2, variant)                                            \
    BOOST_PP_CAT(GEN_CASE_, POICA_VARIANT_NAME(variant)) t1t2

#define GEN_CASE_Add_Bool(t1, t2) GEN_CASE_AUX(Add(t1), +, int, int)
#define GEN_CASE_Sub_Bool(t1, t2) GEN_CASE_AUX(Sub(t1), -, int, int)
#define GEN_CASE_Mul_Bool(t1, t2) GEN_CASE_AUX(Mul(t2), *, int, int)

#define GEN_CASE_Addint(t1, t2) GEN_CASE_Add_Bool(t1, t2)
#define GEN_CASE_Subint(t1, t2) GEN_CASE_Sub_Bool(t1, t2)
#define GEN_CASE_Mulint(t1, t2) GEN_CASE_Mul_Bool(t1, t2)

#define GEN_CASE_And_Bool(t1, t2) GEN_CASE_AUX(And(t1), &&, _Bool, _Bool)
#define GEN_CASE_Or_Bool(t1, t2)  GEN_CASE_AUX(Or(t1), ||, _Bool, _Bool)
#define GEN_CASE_Xor_Bool(t1, t2) GEN_CASE_AUX(Xor(t1), ^, _Bool, _Bool)
#define GEN_CASE_Eq_Bool(t1, t2)  GEN_CASE_AUX(Eq(t2), ==, t2, t2)

#define GEN_CASE_Andint(t1, t2) GEN_CASE_And_Bool(t1, t2)
#define GEN_CASE_Orint(t1, t2)  GEN_CASE_Or_Bool(t1, t2)
#define GEN_CASE_Xorint(t1, t2) GEN_CASE_Xor_Bool(t1, t2)
#define GEN_CASE_Eqint(t1, t2)  GEN_CASE_AUX(Eq(t2), ==, t2, t2)

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
    of(variant_name, pair) {                                                   \
        return eval(t1, t2)(pair->left) op eval(t1, t2)(pair->right);          \
    }

declEval(int, _Bool);
declEval(int, int);
declEval(_Bool, _Bool);
declEval(_Bool, int);

defEval(int, _Bool);
defEval(int, int);
defEval(_Bool, _Bool);
defEval(_Bool, int);

#define EXPR(expr)          obj(expr, Expr)
#define OP(op, left, right) op((ExprPair){EXPR(left), EXPR(right)})

int main(void) {
    const Expr(_Bool, _Bool) true_node = BConst(_Bool)(true);
    const Expr(_Bool, int) false_node = BConst(int)(false);

    const Expr(int, int) _12_node = IConst(int)(12);

    // 12 == 12 == true
    const Expr(_Bool, int) eq_node =
        Eq(int)((ExprPair(int, int)){&_12_node, &_12_node});

    // true && false == false
    Expr(_Bool, int) expr =
        And(int)((ExprPair(_Bool, int)){&eq_node, &false_node});

    _Bool res = eval(_Bool, int)(&expr);

    /*
     * Output:
     * 0
     */
    printf("%d\n", (int)res);
}
