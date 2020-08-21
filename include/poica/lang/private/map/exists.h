#ifndef POICA_LANG_PRIVATE_MAP_EXISTS_H
#define POICA_LANG_PRIVATE_MAP_EXISTS_H

#include <poica/lang/private/map/get.h>

#define POICA_P_LANG_MAP_EXISTS(map, key)                                      \
    POICA_P_LANG_OVERLOAD_ON_KIND(POICA_P_LANG_MAP_EXISTS_,                    \
                                  POICA_P_LANG_MAP_GET(map, key))

#define POICA_P_LANG_MAP_EXISTS_FOUND(_value) 1
#define POICA_P_LANG_MAP_EXISTS_NOT_FOUND()   0

#endif // POICA_LANG_PRIVATE_MAP_EXISTS_H
