#ifndef POICA_PRODUCT_INTROSPECTION_FIELD_TYPES_H
#define POICA_PRODUCT_INTROSPECTION_FIELD_TYPES_H

#include <boost/preprocessor.hpp>

#define FIELD_TYPE(field) BOOST_PP_SEQ_ELEM(1, field)

#define PRODUCT_FIELD_TYPES(fields)                                            \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_PRODUCT_GEN_FIELD_TYPE, _data, fields)

#define POICA_P_PRODUCT_GEN_FIELD_TYPE(_r, _data, field) FIELD_TYPE(field),

#endif // POICA_PRODUCT_INTROSPECTION_FIELD_TYPES_H
