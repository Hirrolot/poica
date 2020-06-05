#ifndef POICA_SUM_TYPE_H
#define POICA_SUM_TYPE_H

#include "misc.h"
#include "poly.h"

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define SUM(name, variants)                                                    \
    typedef struct name {                                                      \
        enum { BOOST_PP_SEQ_FOR_EACH(GEN_TAG, _data, variants) } tag;          \
        struct {                                                               \
            BOOST_PP_SEQ_FOR_EACH(GEN_FIELD, _data, variants)                  \
        } data;                                                                \
    } name;                                                                    \
                                                                               \
    BOOST_PP_SEQ_FOR_EACH(GEN_REDIRECT_VARIANT_TO_INNER_TYPE, _data, variants) \
    BOOST_PP_SEQ_FOR_EACH(GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE, name,        \
                          variants)                                            \
                                                                               \
    BOOST_PP_SEQ_FOR_EACH(GEN_VCONSTR, name, variants)                         \
                                                                               \
    typedef int BOOST_PP_CAT(name, UselessTypedef)

#define GEN_REDIRECT_VARIANT_TO_INNER_TYPE(_r, _data, variant)                 \
    typedef VARIANT_TYPE(variant)                                              \
        REDIRECT_VARIANT_TO_INNER_TYPE(VARIANT_NAME(variant));
#define REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)                           \
    BOOST_PP_CAT(variant_name, RedirectToInnerType)

#define GEN_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(_r, sum_name, variant)          \
    typedef sum_name REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(VARIANT_NAME(variant));
#define REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(variant_name)                       \
    BOOST_PP_CAT(variant_name, RedirectToOuterSumType)

#define GEN_TAG(_r, _data, variant)       VARIANT_NAME_AS_TAG(VARIANT_NAME(variant)),
#define VARIANT_NAME_AS_TAG(variant_name) BOOST_PP_CAT(variant_name, Tag)

#define GEN_FIELD(_r, _data, variant)                                          \
    VARIANT_TYPE(variant) VARIANT_NAME(variant);

#define VARIANT_NAME(variant) BOOST_PP_TUPLE_ELEM(2, 0, variant)
#define VARIANT_TYPE(variant) BOOST_PP_TUPLE_ELEM(2, 1, variant)

#define GEN_VCONSTR(_r, sum_name, variant)                                     \
    inline static sum_name VARIANT_NAME(variant)(VARIANT_TYPE(variant) arg) {  \
        return (sum_name){.tag = VARIANT_NAME_AS_TAG(VARIANT_NAME(variant)),   \
                          .data.VARIANT_NAME(variant) = arg};                  \
    }

#define VARIANT(...)                            VARIANT_AUX(__VA_ARGS__)
#define VARIANT_AUX(variant_name, variant_type) ((variant_name OF variant_type))

#define MATCH(sum_ptr)                                                         \
    for (poly inner_sum_ptr = (poly)sum_ptr; inner_sum_ptr != (poly)0;         \
         inner_sum_ptr = (poly)0)                                              \
        for (bool break_is_needed = false; !break_is_needed;                   \
             break_is_needed = true)                                           \
            switch (sum_ptr->tag)

#define CASE(variant_name, var_name)                                           \
    case VARIANT_NAME_AS_TAG(variant_name):                                    \
        BREAK_IF_NEEDED                                                        \
                                                                               \
        REDIRECT_VARIANT_TO_INNER_TYPE(variant_name) *var_name =               \
            (REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)                      \
                 *)(&((REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(                     \
                          variant_name) *)inner_sum_ptr)                       \
                         ->data.variant_name);

#define DEFAULT                                                                \
    default:                                                                   \
        BREAK_IF_NEEDED

#define BREAK_IF_NEEDED                                                        \
    if (break_is_needed) {                                                     \
        break;                                                                 \
    } else {                                                                   \
        break_is_needed = true;                                                \
    }

#endif // POICA_SUM_TYPE_H
