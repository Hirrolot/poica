#ifndef POICA_SUM_INTROSPECTION_H
#define POICA_SUM_INTROSPECTION_H

#include <boost/preprocessor.hpp>

#define SUM_INTROSPECT(...)                        POICA_P_SUM_INTROSPECT_AUX(__VA_ARGS__)
#define POICA_P_SUM_INTROSPECT_AUX(name, variants) variants

/*
 * Either of:
 * 1) POICA_VARIANT_EMPTY
 * 2) POICA_VARIANT_SINGLE
 * 3) POICA_VARIANT_MANY
 */
#define VARIANT_KIND(variant) BOOST_PP_SEQ_ELEM(0, variant)

#define VARIANT_NAME(variant) BOOST_PP_SEQ_ELEM(1, variant)

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

#endif // POICA_SUM_INTROSPECTION_H
