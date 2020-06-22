#ifndef POICA_CHOICE_VARIANT_TAG_H
#define POICA_CHOICE_VARIANT_TAG_H

#ifdef POICA_USE_PREFIX
#define poicaVariantTag POICA_P_VARIANT_TAG
#else
#define variantTag POICA_P_VARIANT_TAG
#endif

#define POICA_P_VARIANT_TAG(choice_ptr) ((choice_ptr)->tag)

#endif // POICA_CHOICE_VARIANT_TAG_H
