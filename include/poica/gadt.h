#ifndef POICA_GADT_H
#define POICA_GADT_H

#include <poica/private/call_macro.h>
#include <poica/private/map.h>
#include <poica/private/variadic_to_seq.h>

#include <poica/choice.h>
#include <poica/force_semicolon.h>

#include <poica/gadt/construct_variants.h>
#include <poica/gadt/match.h>
#include <poica/gadt/variant.h>
#include <poica/gadt/variants_to_map.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define poicaGadt POICA_P_GADT

#else

#define gadt POICA_P_GADT

#endif

#define POICA_P_GADT(name, ...)                                                \
    POICA_P_GADT_EXPAND(BOOST_PP_SEQ_FOR_EACH(                                 \
        POICA_P_GADT_VISIT,                                                    \
        name,                                                                  \
        POICA_P_GADT_VARIANTS_TO_MAP(POICA_P_GADT_CONSTRUCT_VARIANTS(          \
            POICA_P_VARIADIC_TO_SEQ(__VA_ARGS__)))))                           \
                                                                               \
    POICA_FORCE_SEMICOLON

#define POICA_P_GADT_VISIT(_r, gadt_name, variants)                            \
    POICA_P_GADT_DEFER(POICA_P_GADT_VISIT_AUX)(gadt_name, (variants))

#define POICA_P_GADT_VISIT_AUX(gadt_name, variants)                            \
    POICA_P_CHOICE(POICA_P_GADT_CHOICE_NAME(gadt_name, variants),              \
                   BOOST_PP_SEQ_FOR_EACH(POICA_P_GADT_VISIT_GEN_VARIANT,       \
                                         POICA_P_MAP_ITEM_KEY(variants),       \
                                         POICA_P_MAP_ITEM_VALUE(variants)));

#define POICA_P_GADT_CHOICE_NAME(gadt_name, variants)                          \
    POICA_P_P(gadt_name, BOOST_PP_TUPLE_REM() POICA_P_MAP_ITEM_KEY(variants))

#define POICA_P_GADT_VISIT_GEN_VARIANT(_r, variant_self_types, variant)        \
    (BOOST_PP_SEQ_REPLACE(variant,                                             \
                          1,                                                   \
                          POICA_P_P(POICA_VARIANT_NAME(variant),               \
                                    POICA_P_EXPAND variant_self_types)))

#define POICA_P_GADT_EMPTY()
#define POICA_P_GADT_DEFER(op)   op POICA_P_GADT_EMPTY()
#define POICA_P_GADT_EXPAND(...) __VA_ARGS__

#endif // POICA_GADT_H
