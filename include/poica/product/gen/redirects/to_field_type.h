#ifndef POICA_PRODUCT_GEN_REDIRECTS_TO_FIELD_TYPE_H
#define POICA_PRODUCT_GEN_REDIRECTS_TO_FIELD_TYPE_H

#include <poica/private/aux.h>

#include <poica/product/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_P_PRODUCT_GEN_REDIRECTS_TO_FIELD_TYPE(product_name, fields)      \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_PRODUCT_GEN_REDIRECT_TO_FIELD_TYPE, product_name, fields)

#define POICA_P_PRODUCT_GEN_REDIRECT_TO_FIELD_TYPE(_r, product_name, field)    \
    typedef FIELD_TYPE(field) POICA_P_PRODUCT_REDIRECT_TO_FIELD_TYPE(          \
        product_name, FIELD_NAME(field));

#define POICA_P_PRODUCT_REDIRECT_TO_FIELD_TYPE(product_name, field_name)       \
    POICA_P_PREFIX(BOOST_PP_CAT(                                               \
        product_name,                                                          \
        BOOST_PP_CAT(_, BOOST_PP_CAT(field_name, _RedirectToFieldType))))

#endif // POICA_PRODUCT_GEN_REDIRECTS_TO_FIELD_TYPE_H
