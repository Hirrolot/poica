#ifndef POICA_CHOICE_PATTERN_MATCHING_MUT_H
#define POICA_CHOICE_PATTERN_MATCHING_MUT_H

#include <poica/choice/pattern_matching/aux.h>

#ifdef POICA_USE_PREFIX

#define poicaMatchMut(choice_ptr) POICA_P_MATCH(, choice_ptr)
#define poicaOfManyMut(variant_name, var_names)                                \
    POICA_P_OF_MANY(, variant_name, var_names)
#define poicaOfMut(...) POICA_P_OF(, __VA_ARGS__)

#else

#define matchMut(choice_ptr) POICA_P_MATCH(, choice_ptr)
#define ofManyMut(variant_name, var_names)                                     \
    POICA_P_OF_MANY(, variant_name, var_names)
#define ofMut(...) POICA_P_OF(, __VA_ARGS__)

#endif

#endif // POICA_CHOICE_PATTERN_MATCHING_MUT_H
