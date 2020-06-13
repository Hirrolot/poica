#ifndef POICA_OBJ_H
#define POICA_OBJ_H

#include <poica/keywords.h>

/**
 * Expands to a pointer to an unnamed object of the specified type created
 * in-place.
 *
 * @see https://en.cppreference.com/w/c/language/compound_literal
 */
#define OBJ(...) POICA_P_OBJ_AUX(__VA_ARGS__)

#define POICA_P_OBJ_AUX(value, value_type)                                     \
    (value_type *)(value_type[]) {                                             \
        value                                                                  \
    }

#endif // POICA_OBJ_H
