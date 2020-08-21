#ifndef POICA_LANG_PRIVATE_MAP_APPEND_H
#define POICA_LANG_PRIVATE_MAP_APPEND_H

#include <poica/lang/private/map/item.h>

// Appends the provided item to `map`. Beware: this macro can produce an
// associative map, which has two items with identical keys.
#define POICA_P_LANG_MAP_APPEND(map, key, value)                               \
    map POICA_P_LANG_MAP_ITEM(key, value)

#endif // POICA_LANG_PRIVATE_MAP_APPEND_H
