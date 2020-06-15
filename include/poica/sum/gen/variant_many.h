#ifndef POICA_SUM_GEN_VARIANT_MANY
#define POICA_SUM_GEN_VARIANT_MANY

#include <poica/private/aux.h>
#include <poica/private/defer.h>

#include <poica/product.h>
#include <poica/sum/gen/redirects/to_inner_type.h>
#include <poica/sum/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCTS(variants)                        \
    POICA_P_EXPAND(BOOST_PP_SEQ_FOR_EACH(                                      \
        POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT, _data, variants))

#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT(_r, data, variant)                \
    OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_, _data, variant)

#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_VARIANT_EMPTY(_data, _variant_name)
#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_VARIANT_SINGLE(                   \
    _data, _variant_name, _variant_type)
#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_VARIANT_MANY(                     \
    _data, variant_name, fields)                                               \
    POICA_P_DEFER(PRODUCT)                                                     \
    (POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name), fields);

#endif // POICA_SUM_GEN_VARIANT_MANY
 