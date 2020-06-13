# 1 "ast_evaluator.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "ast_evaluator.c"
# 1 "../include/poica.h" 1

# 1 "../include/keywords.h" 1
# 5 "../include/poica.h" 2
# 1 "../include/obj.h" 1
# 6 "../include/poica.h" 2
# 1 "../include/poly.h" 1

typedef void *poly;
# 7 "../include/poica.h" 2
# 1 "../include/product.h" 1

# 1 "../include/product/field.h" 1

# 1 "../include/product/../keywords.h" 1
# 5 "../include/product/field.h" 2
# 6 "../include/product.h" 2

# 1 "../include/private/aux.h" 1

# 1 "/usr/include/boost/preprocessor.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/library.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/library.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/arithmetic.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/arithmetic.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/arithmetic/add.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/arithmetic/add.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/arithmetic/dec.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/arithmetic/dec.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/config/config.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/arithmetic/dec.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/arithmetic/add.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/arithmetic/inc.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/arithmetic/add.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/control/while.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/control/while.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/cat.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/control/while.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/debug/error.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/control/while.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/control/iif.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/control/while.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/fold_left.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/list/fold_left.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/control/while.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/list/fold_left.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/list/fold_left.hpp" 2 3 4
# 41 "/usr/include/boost/preprocessor/list/fold_left.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/list/detail/fold_left.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/list/detail/fold_left.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/control/expr_iif.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/list/detail/fold_left.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/list/adt.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/list/adt.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/is_binary.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/detail/is_binary.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/check.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/detail/is_binary.hpp" 2 3 4
# 19 "/usr/include/boost/preprocessor/list/adt.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/logical/compl.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/list/adt.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/eat.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/list/adt.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/list/detail/fold_left.hpp" 2 3 4
# 42 "/usr/include/boost/preprocessor/list/fold_left.hpp" 2 3 4
# 22 "/usr/include/boost/preprocessor/control/while.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/fold_right.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/list/fold_right.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/list/fold_right.hpp" 2 3 4
# 37 "/usr/include/boost/preprocessor/list/fold_right.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/list/detail/fold_right.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/list/detail/fold_right.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/list/reverse.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/list/detail/fold_right.hpp" 2 3 4
# 38 "/usr/include/boost/preprocessor/list/fold_right.hpp" 2 3 4
# 23 "/usr/include/boost/preprocessor/control/while.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/logical/bitand.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/control/while.hpp" 2 3 4
# 48 "/usr/include/boost/preprocessor/control/while.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/control/detail/while.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/control/detail/while.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/logical/bool.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/control/detail/while.hpp" 2 3 4
# 49 "/usr/include/boost/preprocessor/control/while.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/arithmetic/add.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/elem.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/tuple/elem.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/facilities/expand.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/tuple/elem.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/facilities/overload.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/facilities/overload.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/variadic/size.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/facilities/overload.hpp" 2 3 4
# 22 "/usr/include/boost/preprocessor/tuple/elem.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/rem.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/tuple/rem.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/detail/is_single_return.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/tuple/rem.hpp" 2 3 4
# 23 "/usr/include/boost/preprocessor/tuple/elem.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/variadic/elem.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/tuple/elem.hpp" 2 3 4
# 22 "/usr/include/boost/preprocessor/arithmetic/add.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/arithmetic.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/arithmetic/div.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/arithmetic/div.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/arithmetic/detail/div_base.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/arithmetic/detail/div_base.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/arithmetic/sub.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/arithmetic/detail/div_base.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/comparison/less_equal.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/comparison/less_equal.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/logical/not.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/comparison/less_equal.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/arithmetic/detail/div_base.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/arithmetic/div.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/arithmetic.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/arithmetic/mod.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/arithmetic.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/arithmetic/mul.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/arithmetic.hpp" 2 3 4
# 17 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/array.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/array/data.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/elem.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/array/elem.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/array/size.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/array/elem.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/enum.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/insert.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/array/insert.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/array/push_back.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/array/push_back.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/punctuation/comma_if.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/punctuation/comma_if.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/control/if.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/punctuation/comma_if.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/facilities/empty.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/punctuation/comma_if.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/punctuation/comma.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/punctuation/comma_if.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/array/push_back.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/array/detail/get_data.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/array/detail/get_data.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/facilities/is_1.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/facilities/is_1.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/facilities/is_empty.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/facilities/is_empty.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/facilities/is_empty_variadic.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/facilities/is_empty_variadic.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/punctuation/is_begin_parens.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/punctuation/is_begin_parens.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/punctuation/detail/is_begin_parens.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/punctuation/is_begin_parens.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/facilities/is_empty_variadic.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/facilities/detail/is_empty.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/facilities/is_empty_variadic.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/facilities/is_empty.hpp" 2 3 4
# 17 "/usr/include/boost/preprocessor/facilities/is_1.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/array/detail/get_data.hpp" 2 3 4
# 23 "/usr/include/boost/preprocessor/array/push_back.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/array/insert.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/comparison/not_equal.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/array/insert.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/control/deduce_d.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/control/deduce_d.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/control/deduce_d.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/array/insert.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/pop_back.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/array/pop_back.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/repetition/enum.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/repetition/enum.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/repetition/repeat.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/repetition/repeat.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/repetition/repeat.hpp" 2 3 4
# 23 "/usr/include/boost/preprocessor/repetition/enum.hpp" 2 3 4
# 19 "/usr/include/boost/preprocessor/array/pop_back.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/deduce_z.hpp" 1 3 4
# 15 "/usr/include/boost/preprocessor/repetition/deduce_z.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/repetition/deduce_z.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/array/pop_back.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/pop_front.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/array.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/array/push_front.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/remove.hpp" 1 3 4
# 25 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/replace.hpp" 1 3 4
# 26 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/reverse.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/array/reverse.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/reverse.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/tuple/reverse.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/size.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/tuple/reverse.hpp" 2 3 4
# 19 "/usr/include/boost/preprocessor/array/reverse.hpp" 2 3 4
# 27 "/usr/include/boost/preprocessor/array.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/array/to_list.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/array/to_list.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/to_list.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/array/to_list.hpp" 2 3 4
# 29 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/to_seq.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/array/to_seq.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/to_seq.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/array/to_seq.hpp" 2 3 4
# 30 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/array/to_tuple.hpp" 1 3 4
# 31 "/usr/include/boost/preprocessor/array.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/library.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/comparison.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/comparison.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/comparison/equal.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/comparison.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/comparison/greater.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/comparison/greater.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/comparison/less.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/comparison/greater.hpp" 2 3 4
# 19 "/usr/include/boost/preprocessor/comparison.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/comparison/greater_equal.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/comparison.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/config/limits.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/control.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/control.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/control/expr_if.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/control.hpp" 2 3 4
# 22 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/debug.hpp" 1 3 4
# 15 "/usr/include/boost/preprocessor/debug.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/debug/assert.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/debug.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/debug/line.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/debug/line.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/iteration/iterate.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/iteration/iterate.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/slot/slot.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/slot/slot.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/slot/detail/def.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/slot/slot.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/iteration/iterate.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/debug/line.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/stringize.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/debug/line.hpp" 2 3 4
# 17 "/usr/include/boost/preprocessor/debug.hpp" 2 3 4
# 23 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/facilities.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/facilities.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/facilities/apply.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/facilities/apply.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/is_unary.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/facilities/apply.hpp" 2 3 4
# 17 "/usr/include/boost/preprocessor/facilities.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/facilities/check_empty.hpp" 1 3 4
# 14 "/usr/include/boost/preprocessor/facilities/check_empty.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/variadic/has_opt.hpp" 1 3 4
# 15 "/usr/include/boost/preprocessor/facilities/check_empty.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor/facilities.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/facilities/identity.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/facilities.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/facilities/intercept.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/facilities.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/facilities/va_opt.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/facilities.hpp" 2 3 4
# 24 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/iteration.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/iteration.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/iteration/local.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/iteration.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/iteration/self.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/iteration.hpp" 2 3 4
# 25 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/list.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/list/append.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/at.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/list/at.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/list/rest_n.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/list/at.hpp" 2 3 4
# 20 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/cat.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/enum.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/list/enum.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/list/for_each_i.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/list/for_each_i.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/repetition/for.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/repetition/for.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/repetition/for.hpp" 2 3 4
# 44 "/usr/include/boost/preprocessor/repetition/for.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/repetition/detail/for.hpp" 1 3 4
# 45 "/usr/include/boost/preprocessor/repetition/for.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/list/for_each_i.hpp" 2 3 4
# 19 "/usr/include/boost/preprocessor/list/enum.hpp" 2 3 4
# 22 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/filter.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/first_n.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/list.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/list/for_each.hpp" 1 3 4
# 27 "/usr/include/boost/preprocessor/list.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/list/for_each_product.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/list/for_each_product.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/list/to_tuple.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/list/for_each_product.hpp" 2 3 4
# 29 "/usr/include/boost/preprocessor/list.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/list/size.hpp" 1 3 4
# 32 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/to_array.hpp" 1 3 4
# 33 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/list/to_seq.hpp" 1 3 4
# 34 "/usr/include/boost/preprocessor/list.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/list/transform.hpp" 1 3 4
# 36 "/usr/include/boost/preprocessor/list.hpp" 2 3 4
# 26 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/logical.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/logical.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/logical/and.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/logical.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/logical/bitnor.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/logical.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/logical/bitor.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/logical.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/logical/bitxor.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/logical.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/logical/nor.hpp" 1 3 4
# 25 "/usr/include/boost/preprocessor/logical.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/logical/or.hpp" 1 3 4
# 27 "/usr/include/boost/preprocessor/logical.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/logical/xor.hpp" 1 3 4
# 28 "/usr/include/boost/preprocessor/logical.hpp" 2 3 4
# 27 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/punctuation.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/punctuation.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/punctuation/paren.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/punctuation.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/punctuation/paren_if.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/punctuation.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/punctuation/remove_parens.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/punctuation/remove_parens.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/enum.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/punctuation/remove_parens.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/punctuation.hpp" 2 3 4
# 28 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition.hpp" 1 3 4
# 15 "/usr/include/boost/preprocessor/repetition.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/repetition/deduce_r.hpp" 1 3 4
# 15 "/usr/include/boost/preprocessor/repetition/deduce_r.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/repetition/deduce_r.hpp" 2 3 4
# 16 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/repetition/enum_binary_params.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_params.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_params_with_a_default.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_params_with_defaults.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_shifted.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/repetition/enum_shifted.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/repetition/enum_shifted.hpp" 2 3 4
# 23 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_shifted_binary_params.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_shifted_params.hpp" 1 3 4
# 25 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_trailing.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/repetition/enum_trailing.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/repetition/enum_trailing.hpp" 2 3 4
# 26 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_trailing_binary_params.hpp" 1 3 4
# 27 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/repetition/enum_trailing_params.hpp" 1 3 4
# 28 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/repetition/repeat_from_to.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/repetition/repeat_from_to.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/repetition/repeat_from_to.hpp" 2 3 4
# 31 "/usr/include/boost/preprocessor/repetition.hpp" 2 3 4
# 29 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/selection.hpp" 1 3 4
# 15 "/usr/include/boost/preprocessor/selection.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/selection/max.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/selection.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/selection/min.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/selection.hpp" 2 3 4
# 30 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/seq.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/seq/cat.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/seq/cat.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/seq/fold_left.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/seq/fold_left.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/seq/fold_left.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/seq.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/seq/seq.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/seq/elem.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/seq/seq.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/seq/fold_left.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/size.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/seq/fold_left.hpp" 2 3 4
# 19 "/usr/include/boost/preprocessor/seq/cat.hpp" 2 3 4
# 17 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/seq/enum.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/filter.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/first_n.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/seq/first_n.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/seq/detail/split.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/seq/first_n.hpp" 2 3 4
# 21 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/seq/fold_right.hpp" 1 3 4
# 16 "/usr/include/boost/preprocessor/seq/fold_right.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/detail/auto_rec.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/seq/fold_right.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/seq/reverse.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/seq/fold_right.hpp" 2 3 4
# 23 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/for_each.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/seq/for_each.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/seq/detail/is_empty.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/seq/for_each.hpp" 2 3 4
# 24 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/for_each_i.hpp" 1 3 4
# 25 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/for_each_product.hpp" 1 3 4
# 26 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/insert.hpp" 1 3 4
# 17 "/usr/include/boost/preprocessor/seq/insert.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/seq/rest_n.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/seq/insert.hpp" 2 3 4
# 27 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/pop_back.hpp" 1 3 4
# 28 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/pop_front.hpp" 1 3 4
# 29 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/push_back.hpp" 1 3 4
# 30 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/push_front.hpp" 1 3 4
# 31 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/remove.hpp" 1 3 4
# 32 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/replace.hpp" 1 3 4
# 33 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/seq/subseq.hpp" 1 3 4
# 38 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/to_array.hpp" 1 3 4
# 39 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/to_list.hpp" 1 3 4
# 18 "/usr/include/boost/preprocessor/seq/to_list.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/seq/detail/binary_transform.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/seq/detail/binary_transform.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/variadic/detail/is_single_return.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/seq/detail/binary_transform.hpp" 2 3 4
# 19 "/usr/include/boost/preprocessor/seq/to_list.hpp" 2 3 4
# 40 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/to_tuple.hpp" 1 3 4
# 41 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/transform.hpp" 1 3 4
# 42 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/seq/variadic_seq_to_seq.hpp" 1 3 4
# 43 "/usr/include/boost/preprocessor/seq.hpp" 2 3 4
# 31 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/slot.hpp" 1 3 4
# 32 "/usr/include/boost/preprocessor/library.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/tuple.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/tuple.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/insert.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/tuple/insert.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/tuple/to_array.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/tuple/insert.hpp" 2 3 4
# 22 "/usr/include/boost/preprocessor/tuple.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/pop_back.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/tuple.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/pop_front.hpp" 1 3 4
# 24 "/usr/include/boost/preprocessor/tuple.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/push_back.hpp" 1 3 4
# 25 "/usr/include/boost/preprocessor/tuple.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/push_front.hpp" 1 3 4
# 26 "/usr/include/boost/preprocessor/tuple.hpp" 2 3 4

# 1 "/usr/include/boost/preprocessor/tuple/remove.hpp" 1 3 4
# 28 "/usr/include/boost/preprocessor/tuple.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/tuple/replace.hpp" 1 3 4
# 29 "/usr/include/boost/preprocessor/tuple.hpp" 2 3 4
# 34 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/variadic.hpp" 1 3 4
# 19 "/usr/include/boost/preprocessor/variadic.hpp" 3 4
# 1 "/usr/include/boost/preprocessor/variadic/to_array.hpp" 1 3 4
# 20 "/usr/include/boost/preprocessor/variadic.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/variadic/to_list.hpp" 1 3 4
# 21 "/usr/include/boost/preprocessor/variadic.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/variadic/to_seq.hpp" 1 3 4
# 22 "/usr/include/boost/preprocessor/variadic.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/variadic/to_tuple.hpp" 1 3 4
# 23 "/usr/include/boost/preprocessor/variadic.hpp" 2 3 4
# 35 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 1 "/usr/include/boost/preprocessor/wstringize.hpp" 1 3 4
# 36 "/usr/include/boost/preprocessor/library.hpp" 2 3 4
# 18 "/usr/include/boost/preprocessor.hpp" 2 3 4
# 5 "../include/private/aux.h" 2
# 8 "../include/product.h" 2

# 1 "../include/product/extract.h" 1

# 1 "../include/product/gen/redirects/to_field_type.h" 1

# 1 "../include/product/gen/redirects/../../../private/aux.h" 1
# 5 "../include/product/gen/redirects/to_field_type.h" 2

# 1 "../include/product/gen/redirects/../../introspection.h" 1
# 7 "../include/product/gen/redirects/to_field_type.h" 2
# 6 "../include/product/extract.h" 2

# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stdbool.h" 1 3 4
# 8 "../include/product/extract.h" 2
# 10 "../include/product.h" 2

# 1 "../include/product/gen/fields.h" 1

# 1 "../include/product/gen/../introspection.h" 1
# 5 "../include/product/gen/fields.h" 2
# 12 "../include/product.h" 2
# 1 "../include/product/gen/redirects.h" 1

# 1 "../include/product/gen/redirects/to_field_type.h" 1
# 5 "../include/product/gen/redirects.h" 2
# 13 "../include/product.h" 2
# 1 "../include/product/introspection.h" 1
# 14 "../include/product.h" 2
# 8 "../include/poica.h" 2
# 1 "../include/sum.h" 1
# 9 "../include/sum.h"
# 1 "../include/sum/gen/fields.h" 1

# 1 "../include/sum/gen/../unused_field_type.h" 1

typedef char POICA_P_SUM_UnusedFieldType;
# 5 "../include/sum/gen/fields.h" 2
# 1 "../include/sum/gen/../variant.h" 1

# 1 "../include/sum/gen/../../keywords.h" 1
# 5 "../include/sum/gen/../variant.h" 2
# 1 "../include/sum/gen/../../product/field.h" 1
# 6 "../include/sum/gen/../variant.h" 2
# 6 "../include/sum/gen/fields.h" 2
# 1 "../include/sum/gen/redirects/to_inner_type.h" 1

# 1 "../include/sum/gen/redirects/../../../private/aux.h" 1
# 5 "../include/sum/gen/redirects/to_inner_type.h" 2

# 1 "../include/sum/gen/redirects/../../introspection.h" 1
# 7 "../include/sum/gen/redirects/to_inner_type.h" 2
# 1 "../include/sum/gen/redirects/../../unused_field_type.h" 1
# 8 "../include/sum/gen/redirects/to_inner_type.h" 2
# 1 "../include/sum/gen/redirects/../variant_many.h" 1

# 1 "../include/sum/gen/redirects/../../../private/aux.h" 1
# 5 "../include/sum/gen/redirects/../variant_many.h" 2
# 1 "../include/sum/gen/redirects/../../../private/defer.h" 1
# 6 "../include/sum/gen/redirects/../variant_many.h" 2

# 1 "../include/sum/gen/redirects/../../../product.h" 1
# 8 "../include/sum/gen/redirects/../variant_many.h" 2
# 1 "../include/sum/gen/redirects/../../introspection.h" 1
# 9 "../include/sum/gen/redirects/../variant_many.h" 2
# 1 "../include/sum/gen/redirects/../redirects/to_inner_type.h" 1
# 10 "../include/sum/gen/redirects/../variant_many.h" 2
# 9 "../include/sum/gen/redirects/to_inner_type.h" 2
# 7 "../include/sum/gen/fields.h" 2
# 10 "../include/sum.h" 2
# 1 "../include/sum/gen/redirects.h" 1

# 1 "../include/sum/gen/redirects/to_outer_sum_type.h" 1

# 1 "../include/sum/gen/redirects/../../variant.h" 1
# 7 "../include/sum/gen/redirects/to_outer_sum_type.h" 2
# 6 "../include/sum/gen/redirects.h" 2
# 11 "../include/sum.h" 2
# 1 "../include/sum/gen/tags.h" 1

# 1 "../include/sum/gen/../../private/aux.h" 1
# 5 "../include/sum/gen/tags.h" 2

# 1 "../include/sum/gen/../introspection.h" 1
# 7 "../include/sum/gen/tags.h" 2
# 12 "../include/sum.h" 2
# 1 "../include/sum/gen/variant_many.h" 1
# 13 "../include/sum.h" 2
# 1 "../include/sum/gen/vconstrs.h" 1

# 1 "../include/sum/gen/../../private/defer.h" 1
# 5 "../include/sum/gen/vconstrs.h" 2
# 1 "../include/sum/gen/../../product.h" 1
# 6 "../include/sum/gen/vconstrs.h" 2

# 1 "../include/sum/gen/tags.h" 1
# 9 "../include/sum/gen/vconstrs.h" 2
# 14 "../include/sum.h" 2
# 1 "../include/sum/pattern_matching.h" 1

# 1 "../include/sum/../keywords.h" 1
# 5 "../include/sum/pattern_matching.h" 2
# 1 "../include/sum/../poly.h" 1
# 6 "../include/sum/pattern_matching.h" 2
# 1 "../include/sum/gen/tags.h" 1
# 7 "../include/sum/pattern_matching.h" 2
# 1 "../include/product/gen/redirects/to_field_type.h" 1
# 8 "../include/sum/pattern_matching.h" 2
# 15 "../include/sum.h" 2
# 1 "../include/sum/variant.h" 1
# 16 "../include/sum.h" 2
# 9 "../include/poica.h" 2
# 2 "ast_evaluator.c" 2

# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 424 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 427 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 428 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 429 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 425 "/usr/include/features.h" 2 3 4
# 448 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 449 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 216 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3 4

# 216 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;

typedef long int __quad_t;
typedef unsigned long int __u_quad_t;

typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 130 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 131 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4

typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
    int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;

typedef int __clockid_t;

typedef void *__timer_t;

typedef long int __blksize_t;

typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;

typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;

typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

typedef long int __fsword_t;

typedef long int __ssize_t;

typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;

typedef __off64_t __loff_t;
typedef char *__caddr_t;

typedef long int __intptr_t;

typedef unsigned int __socklen_t;

typedef int __sig_atomic_t;
# 36 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4

struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 37 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4

struct _IO_FILE;

typedef struct _IO_FILE FILE;
# 38 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/libio.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4
typedef struct {
    int __count;
    union {
        unsigned int __wch;
        char __wchb[4];
    } __value;
} __mbstate_t;
# 22 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 2 3 4

typedef struct {
    __off_t __pos;
    __mbstate_t __state;
} _G_fpos_t;
typedef struct {
    __off64_t __pos;
    __mbstate_t __state;
} _G_fpos64_t;
# 36 "/usr/include/x86_64-linux-gnu/bits/libio.h" 2 3 4
# 53 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/x86_64-linux-gnu/bits/libio.h" 2 3 4
# 149 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
struct _IO_jump_t;
struct _IO_FILE;

typedef void _IO_lock_t;

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;

    int _pos;
# 177 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
};

enum __codecvt_result {
    __codecvt_ok,
    __codecvt_partial,
    __codecvt_error,
    __codecvt_noconv
};
# 245 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
struct _IO_FILE {
    int _flags;

    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;

    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;

    struct _IO_marker *_markers;

    struct _IO_FILE *_chain;

    int _fileno;

    int _flags2;

    __off_t _old_offset;

    unsigned short _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];

    _IO_lock_t *_lock;
# 293 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
    __off64_t _offset;

    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;

    size_t __pad5;
    int _mode;

    char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};

typedef struct _IO_FILE _IO_FILE;

struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 337 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);

typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, size_t __n);

typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);

typedef int __io_close_fn(void *__cookie);
# 389 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
extern int __underflow(_IO_FILE *);
extern int __uflow(_IO_FILE *);
extern int __overflow(_IO_FILE *, int);
# 433 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
extern int _IO_getc(_IO_FILE *__fp);
extern int _IO_putc(int __c, _IO_FILE *__fp);
extern int _IO_feof(_IO_FILE *__fp) __attribute__((__nothrow__, __leaf__));
extern int _IO_ferror(_IO_FILE *__fp) __attribute__((__nothrow__, __leaf__));

extern int _IO_peekc_locked(_IO_FILE *__fp);

extern void _IO_flockfile(_IO_FILE *) __attribute__((__nothrow__, __leaf__));
extern void _IO_funlockfile(_IO_FILE *) __attribute__((__nothrow__, __leaf__));
extern int _IO_ftrylockfile(_IO_FILE *) __attribute__((__nothrow__, __leaf__));
# 462 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
extern int _IO_vfscanf(_IO_FILE *__restrict, const char *__restrict,
                       __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf(_IO_FILE *__restrict, const char *__restrict,
                        __gnuc_va_list);
extern __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn(_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area(_IO_FILE *)
    __attribute__((__nothrow__, __leaf__));
# 42 "/usr/include/stdio.h" 2 3 4

typedef __gnuc_va_list va_list;
# 57 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 71 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;

typedef _G_fpos_t fpos_t;
# 131 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 132 "/usr/include/stdio.h" 2 3 4

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove(const char *__filename)
    __attribute__((__nothrow__, __leaf__));

extern int rename(const char *__old, const char *__new)
    __attribute__((__nothrow__, __leaf__));

extern int renameat(int __oldfd, const char *__old, int __newfd,
                    const char *__new) __attribute__((__nothrow__, __leaf__));

extern FILE *tmpfile(void);
# 173 "/usr/include/stdio.h" 3 4
extern char *tmpnam(char *__s) __attribute__((__nothrow__, __leaf__));

extern char *tmpnam_r(char *__s) __attribute__((__nothrow__, __leaf__));
# 190 "/usr/include/stdio.h" 3 4
extern char *tempnam(const char *__dir, const char *__pfx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__));

extern int fclose(FILE *__stream);

extern int fflush(FILE *__stream);
# 213 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked(FILE *__stream);
# 232 "/usr/include/stdio.h" 3 4
extern FILE *fopen(const char *__restrict __filename,
                   const char *__restrict __modes);

extern FILE *freopen(const char *__restrict __filename,
                     const char *__restrict __modes, FILE *__restrict __stream);
# 265 "/usr/include/stdio.h" 3 4
extern FILE *fdopen(int __fd, const char *__modes)
    __attribute__((__nothrow__, __leaf__));
# 278 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes)
    __attribute__((__nothrow__, __leaf__));

extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc)
    __attribute__((__nothrow__, __leaf__));

extern void setbuf(FILE *__restrict __stream, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));

extern int setvbuf(FILE *__restrict __stream, char *__restrict __buf,
                   int __modes, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern void setbuffer(FILE *__restrict __stream, char *__restrict __buf,
                      size_t __size) __attribute__((__nothrow__, __leaf__));

extern void setlinebuf(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int fprintf(FILE *__restrict __stream, const char *__restrict __format,
                   ...);

extern int printf(const char *__restrict __format, ...);

extern int sprintf(char *__restrict __s, const char *__restrict __format, ...)
    __attribute__((__nothrow__));

extern int vfprintf(FILE *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg);

extern int vprintf(const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf(char *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg) __attribute__((__nothrow__));

extern int snprintf(char *__restrict __s, size_t __maxlen,
                    const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));

extern int vsnprintf(char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 0)));
# 365 "/usr/include/stdio.h" 3 4
extern int vdprintf(int __fd, const char *__restrict __fmt,
                    __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__restrict __fmt, ...)
    __attribute__((__format__(__printf__, 2, 3)));

extern int fscanf(FILE *__restrict __stream, const char *__restrict __format,
                  ...);

extern int scanf(const char *__restrict __format, ...);

extern int sscanf(const char *__restrict __s, const char *__restrict __format,
                  ...) __attribute__((__nothrow__, __leaf__));
# 395 "/usr/include/stdio.h" 3 4
extern int
fscanf(FILE *__restrict __stream, const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_fscanf")

    ;
extern int scanf(const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_scanf");
extern int
sscanf(const char *__restrict __s, const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_sscanf") __attribute__((__nothrow__, __leaf__))

;
# 420 "/usr/include/stdio.h" 3 4
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)));

extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 1, 0)));

extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __attribute__((__nothrow__, __leaf__))
__attribute__((__format__(__scanf__, 2, 0)));
# 443 "/usr/include/stdio.h" 3 4
extern int
vfscanf(FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vfscanf")

    __attribute__((__format__(__scanf__, 2, 0)));
extern int
vscanf(const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vscanf")

    __attribute__((__format__(__scanf__, 1, 0)));
extern int
vsscanf(const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vsscanf") __attribute__((__nothrow__, __leaf__))

__attribute__((__format__(__scanf__, 2, 0)));
# 477 "/usr/include/stdio.h" 3 4
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);

extern int getchar(void);
# 495 "/usr/include/stdio.h" 3 4
extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);
# 506 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked(FILE *__stream);
# 517 "/usr/include/stdio.h" 3 4
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);

extern int putchar(int __c);
# 537 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked(int __c, FILE *__stream);

extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);

extern int getw(FILE *__stream);

extern int putw(int __w, FILE *__stream);

extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);
# 603 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                            int __delimiter, FILE *__restrict __stream);
extern __ssize_t getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                          int __delimiter, FILE *__restrict __stream);

extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);

extern int fputs(const char *__restrict __s, FILE *__restrict __stream);

extern int puts(const char *__s);

extern int ungetc(int __c, FILE *__stream);

extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n,
                    FILE *__restrict __stream);

extern size_t fwrite(const void *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
# 673 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream);
extern size_t fwrite_unlocked(const void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

extern int fseek(FILE *__stream, long int __off, int __whence);

extern long int ftell(FILE *__stream);

extern void rewind(FILE *__stream);
# 707 "/usr/include/stdio.h" 3 4
extern int fseeko(FILE *__stream, __off_t __off, int __whence);

extern __off_t ftello(FILE *__stream);
# 731 "/usr/include/stdio.h" 3 4
extern int fgetpos(FILE *__restrict __stream, fpos_t *__restrict __pos);

extern int fsetpos(FILE *__stream, const fpos_t *__pos);
# 757 "/usr/include/stdio.h" 3 4
extern void clearerr(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int feof(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int ferror(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern void clearerr_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int feof_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ferror_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));

extern void perror(const char *__s);

# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 782 "/usr/include/stdio.h" 2 3 4

extern int fileno(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int fileno_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
# 800 "/usr/include/stdio.h" 3 4
extern FILE *popen(const char *__command, const char *__modes);

extern int pclose(FILE *__stream);

extern char *ctermid(char *__s) __attribute__((__nothrow__, __leaf__));
# 840 "/usr/include/stdio.h" 3 4
extern void flockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int ftrylockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern void funlockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
# 868 "/usr/include/stdio.h" 3 4

# 4 "ast_evaluator.c" 2

# 5 "ast_evaluator.c"
typedef struct {
    const struct Expr *left, *right;
} ExprPair;

typedef struct Expr {
    enum {
        POICA_P_MkConst_Tag,
        POICA_P_MkAdd_Tag,
        POICA_P_MkSub_Tag,
        POICA_P_MkMul_Tag,
        POICA_P_MkDiv_Tag,
    } tag;
    struct {
        double MkConst;
        ExprPair MkAdd;
        ExprPair MkSub;
        ExprPair MkMul;
        ExprPair MkDiv;
    } data;
} Expr;
typedef double POICA_P_MkConst_RedirectToInnerType;
typedef ExprPair POICA_P_MkAdd_RedirectToInnerType;
typedef ExprPair POICA_P_MkSub_RedirectToInnerType;
typedef ExprPair POICA_P_MkMul_RedirectToInnerType;
typedef ExprPair POICA_P_MkDiv_RedirectToInnerType;
typedef Expr POICA_P_MkConst_RedirectToOuterSumType;
typedef Expr POICA_P_MkAdd_RedirectToOuterSumType;
typedef Expr POICA_P_MkSub_RedirectToOuterSumType;
typedef Expr POICA_P_MkMul_RedirectToOuterSumType;
typedef Expr POICA_P_MkDiv_RedirectToOuterSumType;
inline static Expr MkConst(double arg) {
    return (Expr){
        .tag = POICA_P_MkConst_Tag,
        .data.MkConst = arg,
    };
}
inline static Expr MkAdd(ExprPair arg) {
    return (Expr){
        .tag = POICA_P_MkAdd_Tag,
        .data.MkAdd = arg,
    };
}
inline static Expr MkSub(ExprPair arg) {
    return (Expr){
        .tag = POICA_P_MkSub_Tag,
        .data.MkSub = arg,
    };
}
inline static Expr MkMul(ExprPair arg) {
    return (Expr){
        .tag = POICA_P_MkMul_Tag,
        .data.MkMul = arg,
    };
}
inline static Expr MkDiv(ExprPair arg) {
    return (Expr){
        .tag = POICA_P_MkDiv_Tag,
        .data.MkDiv = arg,
    };
}
typedef int POICA_P_Expr_UselessTypedef

    ;

double eval(const struct Expr *expr) {
    for (poly poica_p_sum_ptr = (poly)(expr); poica_p_sum_ptr != (poly)0;
         poica_p_sum_ptr = (poly)0)
        for (
# 21 "ast_evaluator.c" 3 4
            _Bool
# 21 "ast_evaluator.c"
                poica_p_break_is_needed =
# 21 "ast_evaluator.c" 3 4
                    0
# 21 "ast_evaluator.c"
            ;
            !poica_p_break_is_needed;
            poica_p_break_is_needed =
# 21 "ast_evaluator.c" 3 4
                1
# 21 "ast_evaluator.c"
        )
            switch ((expr)->tag) {
            case POICA_P_MkConst_Tag:
                if (poica_p_break_is_needed) {
                    break;
                } else {
                    poica_p_break_is_needed =
# 22 "ast_evaluator.c" 3 4
                        1
# 22 "ast_evaluator.c"
                        ;
                }
                for (POICA_P_MkConst_RedirectToInnerType *number =
                         (POICA_P_MkConst_RedirectToInnerType
                              *)(&((POICA_P_MkConst_RedirectToOuterSumType *)
                                       poica_p_sum_ptr)
                                      ->data.MkConst);
                     number != (void *)0;
                     number = (void *)0) {
                    return *number;
                }
            case POICA_P_MkAdd_Tag:
                if (poica_p_break_is_needed) {
                    break;
                } else {
                    poica_p_break_is_needed =
# 25 "ast_evaluator.c" 3 4
                        1
# 25 "ast_evaluator.c"
                        ;
                }
                for (POICA_P_MkAdd_RedirectToInnerType *add =
                         (POICA_P_MkAdd_RedirectToInnerType
                              *)(&((POICA_P_MkAdd_RedirectToOuterSumType *)
                                       poica_p_sum_ptr)
                                      ->data.MkAdd);
                     add != (void *)0;
                     add = (void *)0) {
                    return eval(add->left) + eval(add->right);
                }
            case POICA_P_MkSub_Tag:
                if (poica_p_break_is_needed) {
                    break;
                } else {
                    poica_p_break_is_needed =
# 28 "ast_evaluator.c" 3 4
                        1
# 28 "ast_evaluator.c"
                        ;
                }
                for (POICA_P_MkSub_RedirectToInnerType *sub =
                         (POICA_P_MkSub_RedirectToInnerType
                              *)(&((POICA_P_MkSub_RedirectToOuterSumType *)
                                       poica_p_sum_ptr)
                                      ->data.MkSub);
                     sub != (void *)0;
                     sub = (void *)0) {
                    return eval(sub->left) - eval(sub->right);
                }
            case POICA_P_MkMul_Tag:
                if (poica_p_break_is_needed) {
                    break;
                } else {
                    poica_p_break_is_needed =
# 31 "ast_evaluator.c" 3 4
                        1
# 31 "ast_evaluator.c"
                        ;
                }
                for (POICA_P_MkMul_RedirectToInnerType *mul =
                         (POICA_P_MkMul_RedirectToInnerType
                              *)(&((POICA_P_MkMul_RedirectToOuterSumType *)
                                       poica_p_sum_ptr)
                                      ->data.MkMul);
                     mul != (void *)0;
                     mul = (void *)0) {
                    return eval(mul->left) * eval(mul->right);
                }
            case POICA_P_MkDiv_Tag:
                if (poica_p_break_is_needed) {
                    break;
                } else {
                    poica_p_break_is_needed =
# 34 "ast_evaluator.c" 3 4
                        1
# 34 "ast_evaluator.c"
                        ;
                }
                for (POICA_P_MkDiv_RedirectToInnerType *div =
                         (POICA_P_MkDiv_RedirectToInnerType
                              *)(&((POICA_P_MkDiv_RedirectToOuterSumType *)
                                       poica_p_sum_ptr)
                                      ->data.MkDiv);
                     div != (void *)0;
                     div = (void *)0) {
                    return eval(div->left) / eval(div->right);
                }
            }
}

int main(void) {
    Expr expr =
        MkAdd((ExprPair){(struct Expr *)(struct Expr[]){MkConst(53)},
                         (struct Expr *)(struct Expr[]){MkSub((ExprPair){
                             (struct Expr *)(struct Expr[]){MkDiv((ExprPair){
                                 (struct Expr *)(struct Expr[]){MkConst(155)},
                                 (struct Expr *)(struct Expr[]){MkConst(5)}})},
                             (struct Expr *)(struct Expr[]){MkConst(113)}})}})

        ;

    printf("%f\n", eval(&expr));
}
