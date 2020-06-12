#ifndef POICA_PRODUCT_FIELD_H
#define POICA_PRODUCT_FIELD_H

#include "../keywords.h"

#define FIELD(...)                                POICA_P_FIELD_AUX(__VA_ARGS__)
#define POICA_P_FIELD_AUX(field_name, field_type) ((field_name)(field_type))

#endif // POICA_PRODUCT_FIELD_H
