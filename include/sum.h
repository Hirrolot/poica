#ifndef POICA_SUM_H
#define POICA_SUM_H

#include "private/aux.h"

#include "private/sum/fields.h"
#include "private/sum/gen_variant_many.h"
#include "private/sum/pattern_matching.h"
#include "private/sum/redirects.h"
#include "private/sum/tags.h"
#include "private/sum/variant.h"
#include "private/sum/vconstrs.h"

#include <boost/preprocessor.hpp>

#define SUM(name, variants)                                                    \
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
