#ifndef POICA_PRODUCT_INTROSPECTION_H
#define POICA_PRODUCT_INTROSPECTION_H

#include <boost/preprocessor.hpp>

#define PRODUCT_INTROSPECT(...)                      POICA_P_PRODUCT_INTROSPECT_AUX(__VA_ARGS__)
#define POICA_P_PRODUCT_INTROSPECT_AUX(name, fields) fields

#define FIELD_NAME(field) BOOST_PP_SEQ_ELEM(0, field)
#define FIELD_TYPE(field) BOOST_PP_SEQ_ELEM(1, field)

#endif // POICA_PRODUCT_INTROSPECTION_H
