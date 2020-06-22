#ifndef POICA_ENUM_VARIANT_TAG_H
#define POICA_ENUM_VARIANT_TAG_H

#ifdef POICA_USE_PREFIX
#define poicaVariantTag POICA_P_VARIANT_TAG
#else
#define variantTag POICA_P_VARIANT_TAG
#endif

#define POICA_P_VARIANT_TAG(sum_ptr) ((sum_ptr)->tag)

#endif // POICA_ENUM_VARIANT_TAG_H
