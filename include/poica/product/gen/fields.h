#ifndef POICA_PRODUCT_GEN_FIELDS_H
#define POICA_PRODUCT_GEN_FIELDS_H

#include <poica/product/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_P_PRODUCT_GEN_FIELDS(fields)                                     \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_PRODUCT_GEN_FIELD, _data, fields)

#define POICA_P_PRODUCT_GEN_FIELD(_r, _data, field)                            \
    FIELD_TYPE(field) FIELD_NAME(field);

#endif // POICA_PRODUCT_GEN_FIELDS_H
