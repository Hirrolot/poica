#ifndef POICA_PRIVATE_MAP_EXISTS_H
#define POICA_PRIVATE_MAP_EXISTS_H

#include <poica/private/map/get.h>

#define POICA_P_MAP_EXISTS(map, key)                                           \
    POICA_P_OVERLOAD_ON_KIND(POICA_P_MAP_EXISTS_, POICA_P_MAP_GET(map, key))

#define POICA_P_MAP_EXISTS_FOUND(_value) 1
#define POICA_P_MAP_EXISTS_NOT_FOUND()   0

#endif // POICA_PRIVATE_MAP_EXISTS_H
