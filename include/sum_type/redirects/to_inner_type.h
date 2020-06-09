#ifndef POICA_POICA_P_SUM_TYPE_REDIRECTS_TO_INNER_TYPE_H
#define POICA_POICA_P_SUM_TYPE_REDIRECTS_TO_INNER_TYPE_H

#include "../../aux.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_INNER_TYPE(variants)              \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE, _data, variants)

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE(_r, _data, variant)     \
    POICA_P_SUM_OVERLOAD_ON_VARIANT(                                           \
        POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_, _data, variant)

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_EMPTY(_data,            \
                                                             variant_name)     \
    typedef PoicaPUnusedField POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(      \
        variant_name);

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_NONEMPTY(               \
    _data, variant_name, variant_type)                                         \
    typedef variant_type POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(           \
        variant_name);

#endif // POICA_POICA_P_SUM_TYPE_REDIRECTS_TO_INNER_TYPE_H
