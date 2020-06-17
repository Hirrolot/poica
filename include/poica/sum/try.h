#ifndef POICA_SUM_TRY_H
#define POICA_SUM_TRY_H

#include <poica/sum/pattern_matching.h>

#include <boost/preprocessor.hpp>

#define TRY(sum_ptr, case_expr, failure_expr)                                  \
    MATCH(sum_ptr) {                                                           \
        case_expr {                                                            \
            return failure_expr;                                               \
        }                                                                      \
        DEFAULT {}                                                             \
    }

#endif // POICA_SUM_TRY_H
