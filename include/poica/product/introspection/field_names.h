#ifndef POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H
#define POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H

#include <boost/preprocessor.hpp>

#define FIELD_NAME(field) BOOST_PP_SEQ_ELEM(0, field)

#define PRODUCT_FIELD_NAMES(fields)                                            \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_PRODUCT_GEN_FIELD_NAME, _data, fields)

#define POICA_P_PRODUCT_GEN_FIELD_NAME(_r, _data, field) FIELD_NAME(field),

#endif // POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H
