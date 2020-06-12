#ifndef POICA_SUM_INTROSPECTION_H
#define POICA_SUM_INTROSPECTION_H

#include <boost/preprocessor.hpp>

#define SUM_INTROSPECT(...)                        POICA_P_SUM_INTROSPECT_AUX(__VA_ARGS__)
#define POICA_P_SUM_INTROSPECT_AUX(name, variants) variants

/*
 * Either of:
 * 1) VARIANT_EMPTY
 * 2) VARIANT_SINGLE
 * 3) VARIANT_MANY
 */
#define VARIANT_KIND(variant) BOOST_PP_SEQ_ELEM(0, variant)

#define VARIANT_NAME(variant) BOOST_PP_SEQ_ELEM(1, variant)

/*
 *  1) VARIANT(N) -> macroEMPTY_VARIANT(data, variant_name)
 *  2) VARIANT(N OF (T)) -> macroNONEMPTY(data, variant_name, variant_type)
 *  3) VARIANT(N OF (FIELD(N1 OF T1) ... FIELD(Nm OF Tm))) ->
 * macroVARIANT_MANY(data, variant_name, fields)
 */
#define OVERLOAD_ON_VARIANT(macro, data, variant)                              \
    POICA_P_SUM_OVERLOAD_ON_VARIANT_AUX(                                       \
        BOOST_PP_CAT(macro, VARIANT_KIND(variant)),                            \
        data,                                                                  \
        BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_FRONT(variant)))

#define POICA_P_SUM_OVERLOAD_ON_VARIANT_AUX(macro, ...) macro(__VA_ARGS__)

#endif // POICA_SUM_INTROSPECTION_H
