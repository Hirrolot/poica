#ifndef POICA_CHOICE_PATTERN_MATCHING_MUT_H
#define POICA_CHOICE_PATTERN_MATCHING_MUT_H

#include <poica/choice/pattern_matching/aux.h>

#ifdef POICA_USE_PREFIX

#define poicaMatchMut(choice_ptr) POICA_P_MATCH(, choice_ptr)
#define poicaCaseManyMut(variant_name, var_names)                              \
    POICA_P_CASE_MANY(, variant_name, var_names)
#define poicaCase(...) POICA_P_CASE(, __VA_ARGS__)

#else

#define matchMut(choice_ptr) POICA_P_MATCH(, choice_ptr)
#define caseManyMut(variant_name, var_names)                                   \
    POICA_P_CASE_MANY(, variant_name, var_names)

// clang-format off
#define caseMut(...) POICA_P_CASE(, __VA_ARGS__)
// clang-format on

#endif

#endif // POICA_CHOICE_PATTERN_MATCHING_MUT_H
