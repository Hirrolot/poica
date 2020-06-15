#ifndef POICA_SUM_INTROSPECTION_H
#define POICA_SUM_INTROSPECTION_H

#include <poica/sum/introspection/overload_on_variant.h>

#include <boost/preprocessor.hpp>

#define SUM_INTROSPECT(...)                        POICA_P_SUM_INTROSPECT_AUX(__VA_ARGS__)
#define POICA_P_SUM_INTROSPECT_AUX(name, variants) variants

#define VARIANT_KIND(variant) BOOST_PP_SEQ_ELEM(0, variant)
#define VARIANT_NAME(variant) BOOST_PP_SEQ_ELEM(1, variant)

#endif // POICA_SUM_INTROSPECTION_H
