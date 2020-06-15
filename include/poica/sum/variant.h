#ifndef POICA_SUM_VARIANT_H
#define POICA_SUM_VARIANT_H

#include <poica/keywords.h>
#include <poica/product/field.h>

#include <boost/preprocessor.hpp>

#define VARIANT(...)                                                           \
    BOOST_PP_OVERLOAD(POICA_P_VARIANT_, __VA_ARGS__)(__VA_ARGS__)

#define MANY ,

#define POICA_P_VARIANT_1(variant_name) ((POICA_VARIANT_EMPTY)(variant_name))

#define POICA_P_VARIANT_2(variant_name, variant_type)                          \
    ((POICA_VARIANT_SINGLE)(variant_name)(variant_type))

#define POICA_P_VARIANT_3(variant_name, _many, fields)                         \
    ((POICA_VARIANT_MANY)(variant_name)(fields))

#endif // POICA_SUM_VARIANT_H
