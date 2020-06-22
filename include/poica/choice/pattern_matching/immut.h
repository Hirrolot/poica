#ifndef POICA_CHOICE_PATTERN_MATCHING_IMMUT_H
#define POICA_CHOICE_PATTERN_MATCHING_IMMUT_H

#include <poica/choice/pattern_matching/aux.h>

#ifdef POICA_USE_PREFIX

#define poicaMatch(choice_ptr) POICA_P_MATCH(const, choice_ptr)
#define poicaOfMany(variant_name, var_names)                                   \
    POICA_P_OF_MANY(const, variant_name, var_names)
#define poicaOf(...) POICA_P_OF(const, __VA_ARGS__)

#else

#define match(choice_ptr) POICA_P_MATCH(const, choice_ptr)
#define ofMany(variant_name, var_names)                                        \
    POICA_P_OF_MANY(const, variant_name, var_names)
#define of(...) POICA_P_OF(const, __VA_ARGS__)

#endif

#endif // POICA_CHOICE_PATTERN_MATCHING_IMMUT_H
