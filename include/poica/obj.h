#ifndef POICA_OBJ_H
#define POICA_OBJ_H

#include <poica/keywords.h>

#define OBJ(...) POICA_P_OBJ_AUX(__VA_ARGS__)

#define POICA_P_OBJ_AUX(value, value_type)                                     \
    (value_type *)(value_type[]) {                                             \
        value                                                                  \
    }

#endif // POICA_OBJ_H
