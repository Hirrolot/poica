#ifndef POICA_SUM_INTROSPECTION_OVERLOAD_ON_VARIANT_H
#define POICA_SUM_INTROSPECTION_OVERLOAD_ON_VARIANT_H

#include <boost/preprocessor.hpp>

/*
 *  1) VARIANT(N) -> macroVARIANT_EMPTY(data, variant_name)
 *  2) VARIANT(N OF (T)) -> macroVARIANT_SINGLE(data, variant_name,
 * variant_type) 3) VARIANT(N OF (FIELD(N1 OF T1) ... FIELD(Nm OF Tm))) ->
 * macroVARIANT_MANY(data, variant_name, fields)
 */
#define OVERLOAD_ON_VARIANT(macro, data, variant)                              \
    POICA_P_SUM_OVERLOAD_ON_VARIANT_AUX(                                       \
        BOOST_PP_CAT(macro,                                                    \
                     BOOST_PP_CAT(POICA_P_SUM_RENAME_VARIANT_KIND_,            \
                                  VARIANT_KIND(variant))),                     \
        data,                                                                  \
        BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_FRONT(variant)))

#define POICA_P_SUM_OVERLOAD_ON_VARIANT_AUX(macro, ...) macro(__VA_ARGS__)

#define POICA_P_SUM_RENAME_VARIANT_KIND_POICA_VARIANT_EMPTY  VARIANT_EMPTY
#define POICA_P_SUM_RENAME_VARIANT_KIND_POICA_VARIANT_SINGLE VARIANT_SINGLE
#define POICA_P_SUM_RENAME_VARIANT_KIND_POICA_VARIANT_MANY   VARIANT_MANY

#endif // POICA_SUM_INTROSPECTION_OVERLOAD_ON_VARIANT_H