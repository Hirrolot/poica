#ifndef POICA_SUM_H
#define POICA_SUM_H

#include "keywords.h"
#include "product/field.h"

#include "private/aux.h"

#include "sum/gen/fields.h"
#include "sum/gen/redirects.h"
#include "sum/gen/tags.h"
#include "sum/gen/variant_many.h"
#include "sum/gen/vconstrs.h"
#include "sum/pattern_matching.h"
#include "sum/variant.h"

#include <boost/preprocessor.hpp>

#define SUM(...) POICA_P_SUM_AUX(__VA_ARGS__)

#define POICA_P_SUM_AUX(name, variants)                                        \
    POICA_P_SUM_GEN_VARIANT_MANY_PRODUCTS(variants)                            \
                                                                               \
    typedef struct name {                                                      \
        enum { POICA_P_SUM_GEN_TAGS(variants) } tag;                           \
        struct {                                                               \
            POICA_P_SUM_GEN_FIELDS(variants)                                   \
        } data;                                                                \
    } name;                                                                    \
                                                                               \
    POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_INNER_TYPE(variants)                  \
    POICA_P_SUM_GEN_REDIRECTS_VARIANT_TO_OUTER_SUM_TYPE(name, variants)        \
    POICA_P_SUM_GEN_VCONSTRS(name, variants)                                   \
                                                                               \
    POICA_P_USELESS_TYPEDEF(name)

#endif // POICA_SUM_H
