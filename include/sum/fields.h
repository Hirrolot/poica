#ifndef POICA_SUM_FIELDS_H
#define POICA_SUM_FIELDS_H

#include "aux.h"

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_FIELDS(variants)                                       \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_FIELD, _data, variants)

#define POICA_P_SUM_GEN_FIELD(_r, _data, variant)                              \
    POICA_P_SUM_OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_FIELD_, _data, variant)

#define POICA_P_SUM_GEN_FIELD_EMPTY(_data, variant_name)                       \
    PoicaPUnusedField variant_name;

#define POICA_P_SUM_GEN_FIELD_NONEMPTY(_data, variant_name, variant_type)      \
    variant_type variant_name;

#endif // POICA_SUM_FIELDS_H
