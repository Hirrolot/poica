#ifndef POICA_PRODUCT_H
#define POICA_PRODUCT_H

#include <poica/private/aux.h>

#include <poica/keywords.h>
#include <poica/product/field.h>

#include <poica/product/extract.h>
#include <poica/product/field.h>
#include <poica/product/gen/fields.h>
#include <poica/product/gen/redirects.h>
#include <poica/product/introspection.h>

#include <boost/preprocessor.hpp>

#define PRODUCT(...) POICA_P_PRODUCT_AUX(__VA_ARGS__)

#define POICA_P_PRODUCT_AUX(name, fields)                                      \
    typedef struct name {                                                      \
        POICA_P_PRODUCT_GEN_FIELDS(fields)                                     \
    } name;                                                                    \
                                                                               \
    POICA_P_PRODUCT_GEN_REDIRECTS_TO_FIELD_TYPE(name, fields)                  \
                                                                               \
    POICA_P_USELESS_TYPEDEF(name)

#endif // POICA_PRODUCT_H
