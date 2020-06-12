#ifndef POICA_PRODUCT_H
#define POICA_PRODUCT_H

#include "field.h"
#include "keywords.h"

#include "private/aux.h"
#include "private/product/extract.h"
#include "private/product/fields.h"
#include "private/product/redirects.h"

#include <boost/preprocessor.hpp>

#define PRODUCT(name, fields)                                                  \
    typedef struct name {                                                      \
        POICA_P_PRODUCT_GEN_FIELDS(fields)                                     \
    } name;                                                                    \
                                                                               \
    POICA_P_PRODUCT_GEN_REDIRECTS_TO_FIELD_TYPE(name, fields)                  \
                                                                               \
    POICA_P_USELESS_TYPEDEF(name)

#define FIELD_NAME(field) BOOST_PP_SEQ_ELEM(0, field)
#define FIELD_TYPE(field) BOOST_PP_SEQ_ELEM(1, field)

#define PRODUCT_INTROSPECT(name, fields) fields

#endif // POICA_PRODUCT_H
