#ifndef POICA_POICA_P_SUM_TYPE_H
#define POICA_POICA_P_SUM_TYPE_H

#include "../aux.h"

#include <boost/preprocessor.hpp>

typedef char PoicaPUnusedField;

#define POICA_P_SUM_UNUSED_VALUE ('\0')

// Either EMPTY or NONEMPTY.
#define POICA_P_SUM_VARIANT_KIND(variant) BOOST_PP_SEQ_ELEM(0, variant)

#define POICA_P_SUM_VARIANT_NAME(variant) BOOST_PP_SEQ_ELEM(1, variant)

#define POICA_P_SUM_VARIANT_NAME_AS_TAG(variant_name)                          \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _Tag))

#define POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)               \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToInnerType))

#define POICA_P_SUM_REDIRECT_VARIANT_TO_OUTER_SUM_TYPE(variant_name)           \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToOuterSumType))

/*
 * `variant` is either of two forms:
 *  1) (EMPTY)(variant_name)
 *  2) (NONEMPTY)(variant_name)(variant_type)
 *
 * The first form corresponds to the unit type, and the second specifies a type
 * explicitly:
 *  1) VARIANT(MkSomething)
 *  2) VARIANT(MkSomething OF T)
 *
 * If `variant` is of the first form, this macro invokes
 * `macroEMPTY(data, variant_name)`.
 * In the second case - `macroNONEMPTY(data, variant_name, variant_type)`.
 */
#define POICA_P_SUM_OVERLOAD_ON_VARIANT(macro, data, variant)                  \
    POICA_P_SUM_OVERLOAD_ON_VARIANT_AUX(                                       \
        BOOST_PP_CAT(macro, POICA_P_SUM_VARIANT_KIND(variant)),                \
        data,                                                                  \
        BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_FRONT(variant)))

#define POICA_P_SUM_OVERLOAD_ON_VARIANT_AUX(macro, ...) macro(__VA_ARGS__)

#endif // POICA_POICA_P_SUM_TYPE_H
