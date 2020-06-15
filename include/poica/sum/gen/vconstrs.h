#ifndef POICA_SUM_GEN_VCONSTRS_H
#define POICA_SUM_GEN_VCONSTRS_H

#include <poica/private/defer.h>

#include <poica/sum/introspection.h>

#include <poica/sum/gen/vconstrs/variant_empty.h>
#include <poica/sum/gen/vconstrs/variant_many.h>
#include <poica/sum/gen/vconstrs/variant_single.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTRS(sum_name, variants)                           \
    POICA_P_EXPAND(POICA_P_EXPAND(                                             \
        BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_VCONSTR, sum_name, variants)))

#define POICA_P_SUM_GEN_VCONSTR(_r, sum_name, variant)                         \
    OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_VCONSTR_, sum_name, variant)

#endif // POICA_SUM_GEN_VCONSTRS_H
