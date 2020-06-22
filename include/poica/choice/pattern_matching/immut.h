#ifndef POICA_CHOICE_PATTERN_MATCHING_IMMUT_H
#define POICA_CHOICE_PATTERN_MATCHING_IMMUT_H

#include <poica/choice/pattern_matching/aux.h>

#ifdef POICA_USE_PREFIX

#define poicaMatch(choice_ptr) POICA_P_MATCH(const, choice_ptr)
#define poicaCaseMany(variant_name, var_names)                                 \
    POICA_P_CASE_MANY(const, variant_name, var_names)
#define poicaCase(...) POICA_P_CASE(const, __VA_ARGS__)

#else

#define match(choice_ptr) POICA_P_MATCH(const, choice_ptr)
#define caseMany(variant_name, var_names)                                      \
    POICA_P_CASE_MANY(const, variant_name, var_names)

// clang-format off
#define case(...) POICA_P_CASE(const, __VA_ARGS__)
// clang-format on

#endif

#endif // POICA_CHOICE_PATTERN_MATCHING_IMMUT_H
