#ifndef POICA_SUM_GEN_VCONSTRS_H
#define POICA_SUM_GEN_VCONSTRS_H

#include "../../private/defer.h"
#include "../introspection.h"

#include "vconstrs/variant_empty.h"
#include "vconstrs/variant_many.h"
#include "vconstrs/variant_single.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTRS(sum_name, variants)                           \
    POICA_P_EXPAND(                                                            \
        BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_VCONSTR, sum_name, variants))

#define POICA_P_SUM_GEN_VCONSTR(_r, sum_name, variant)                         \
    OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_VCONSTR_, sum_name, variant)

#endif // POICA_SUM_GEN_VCONSTRS_H
