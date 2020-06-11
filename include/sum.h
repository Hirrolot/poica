#ifndef POICA_SUM_H
#define POICA_SUM_H

#include "aux.h"

#include "sum/fields.h"
#include "sum/pattern_matching.h"
#include "sum/redirects.h"
#include "sum/tags.h"
#include "sum/vconstrs.h"

#include <boost/preprocessor.hpp>

#define SUM(name, variants)                                                    \
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
    typedef int POICA_P_PREFIX(BOOST_PP_CAT(name, _UselessTypedef))

#define VARIANT(...)                                                           \
    BOOST_PP_OVERLOAD(POICA_P_SUM_VARIANT_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_SUM_VARIANT_1(variant_name) ((EMPTY)(variant_name))
#define POICA_P_SUM_VARIANT_2(variant_name, variant_type)                      \
    ((NONEMPTY)(variant_name)(variant_type))

#endif // POICA_SUM_H
