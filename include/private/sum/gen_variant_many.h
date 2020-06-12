#ifndef POICA_PRIVATE_SUM_GEN_VARIANT_MANY
#define POICA_PRIVATE_SUM_GEN_VARIANT_MANY

#include "../../product.h"
#include "../aux.h"
#include "../defer.h"
#include "overload_on_variant.h"
#include "redirects/to_inner_type.h"

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

#endif // POICA_PRIVATE_SUM_GEN_VARIANT_MANY
