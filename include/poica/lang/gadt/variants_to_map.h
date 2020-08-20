#ifndef POICA_LANG_GADT_VARIANTS_TO_MAP_H
#define POICA_LANG_GADT_VARIANTS_TO_MAP_H

#include <poica/lang/gadt/order_entities_to_map.h>
#include <poica/lang/gadt/variant.h>

#define POICA_P_LANG_GADT_VARIANTS_TO_MAP(variants)                            \
    POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP(POICA_P_LANG_GADT_VARIANT_BODY,    \
                                            POICA_P_LANG_GADT_VARIANT_TYPES,   \
                                            variants)

#endif // POICA_LANG_GADT_VARIANTS_TO_MAP_H
