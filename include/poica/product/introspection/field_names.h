#ifndef POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H
#define POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H

#include <boost/preprocessor.hpp>

#define FIELD_NAME(field) BOOST_PP_SEQ_ELEM(0, field)

#define PRODUCT_FIELD_NAMES_SEQ(fields)                                        \
    POICA_P_PRODUCT_FIELD_X_SEQ(POICA_P_PRODUCT_GEN_FIELD_NAME_SEQ, fields)
#define POICA_P_PRODUCT_GEN_FIELD_NAME_SEQ(_r, _data, field) (FIELD_NAME(field))

#define PRODUCT_FIELD_NAMES_TUPLE(fields)                                      \
    POICA_P_PRODUCT_X_TUPLE(POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE,              \
                            POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE_LAST,         \
                            fields)

#define POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE(_r, _data, field)                 \
    FIELD_NAME(field),
#define POICA_P_PRODUCT_GEN_FIELD_NAME_TUPLE_LAST(field) FIELD_NAME(field)

#endif // POICA_PRODUCT_INTROSPECTION_FIELD_NAMES_H
