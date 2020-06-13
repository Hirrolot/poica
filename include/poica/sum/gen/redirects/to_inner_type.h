#ifndef POICA_SUM_GEN_REDIRECTS_TO_INNER_TYPE_H
#define POICA_SUM_GEN_REDIRECTS_TO_INNER_TYPE_H

#include <poica/private/aux.h>

#include <poica/sum/gen/variant_many.h>
#include <poica/sum/introspection.h>
#include <poica/sum/unused_field_type.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_INNER_TYPE(variants)              \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE, _data, variants)

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE(_r, _data, variant)     \
    OVERLOAD_ON_VARIANT(                                                       \
        POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_, _data, variant)

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_VARIANT_EMPTY(          \
    _data, variant_name)                                                       \
    typedef POICA_P_SUM_UnusedFieldType                                        \
        POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name);

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_VARIANT_SINGLE(         \
    _data, variant_name, variant_type)                                         \
    typedef variant_type POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(           \
        variant_name);

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_VARIANT_MANY(           \
    _data, variant_name, _fields)

#define POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)               \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToInnerType))

#endif // POICA_SUM_GEN_REDIRECTS_TO_INNER_TYPE_H
