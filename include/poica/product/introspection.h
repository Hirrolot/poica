#ifndef POICA_PRODUCT_INTROSPECTION_H
#define POICA_PRODUCT_INTROSPECTION_H

#include <poica/product/introspection/field_names.h>
#include <poica/product/introspection/field_types.h>

#include <poica/product/introspection/fields_as_params.h>

#include <boost/preprocessor.hpp>

#define PRODUCT_INTROSPECT(...)                      POICA_P_PRODUCT_INTROSPECT_AUX(__VA_ARGS__)
#define POICA_P_PRODUCT_INTROSPECT_AUX(name, fields) fields

#endif // POICA_PRODUCT_INTROSPECTION_H
