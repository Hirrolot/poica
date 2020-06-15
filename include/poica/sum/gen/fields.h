#ifndef POICA_SUM_GEN_FIELDS_H
#define POICA_SUM_GEN_FIELDS_H

#include <poica/sum/gen/redirects/to_inner_type.h>
#include <poica/sum/variant.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_FIELDS(variants)                                       \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_FIELD, _data, variants)

#define POICA_P_SUM_GEN_FIELD(_r, _data, variant)                              \
    OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_FIELD_, _data, variant)

#define POICA_P_SUM_GEN_FIELD_VARIANT_EMPTY(_data, variant_name)

#define POICA_P_SUM_GEN_FIELD_VARIANT_SINGLE(                                  \
    _data, variant_name, variant_type)                                         \
    variant_type variant_name;

#define POICA_P_SUM_GEN_FIELD_VARIANT_MANY(_data, variant_name, _fields)       \
    POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) variant_name;

#endif // POICA_SUM_GEN_FIELDS_H
