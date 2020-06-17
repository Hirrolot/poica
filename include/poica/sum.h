#ifndef POICA_SUM_H
#define POICA_SUM_H

#include <poica/private/aux.h>

#include <poica/keywords.h>
#include <poica/product/field.h>

#include <poica/sum/gen/fields.h>
#include <poica/sum/gen/redirects.h>
#include <poica/sum/gen/tags.h>
#include <poica/sum/gen/variant_many.h>
#include <poica/sum/gen/vconstrs.h>
#include <poica/sum/pattern_matching.h>
#include <poica/sum/try.h>
#include <poica/sum/variant.h>

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
