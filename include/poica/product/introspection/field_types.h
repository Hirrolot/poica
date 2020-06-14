#ifndef POICA_PRODUCT_INTROSPECTION_FIELD_TYPES_H
#define POICA_PRODUCT_INTROSPECTION_FIELD_TYPES_H

#include <poica/product/introspection/aux.h>

#include <boost/preprocessor.hpp>

#define FIELD_TYPE(field) BOOST_PP_SEQ_ELEM(1, field)

#define PRODUCT_FIELD_TYPES_SEQ(fields)                                        \
    POICA_P_PRODUCT_FIELD_X_SEQ(POICA_P_PRODUCT_GEN_FIELD_TYPE_SEQ, fields)
#define POICA_P_PRODUCT_GEN_FIELD_TYPE_SEQ(_r, _data, field) (FIELD_TYPE(field))

#define PRODUCT_FIELD_TYPES_TUPLE(fields)                                      \
    POICA_P_PRODUCT_X_TUPLE(POICA_P_PRODUCT_GEN_FIELD_TYPE_TUPLE,              \
                            POICA_P_PRODUCT_GEN_FIELD_TYPE_TUPLE_LAST,         \
                            fields)

#define POICA_P_PRODUCT_GEN_FIELD_TYPE_TUPLE(_r, _data, field)                 \
    FIELD_TYPE(field),
#define POICA_P_PRODUCT_GEN_FIELD_TYPE_TUPLE_LAST(field) FIELD_TYPE(field)

#endif // POICA_PRODUCT_INTROSPECTION_FIELD_TYPES_H
