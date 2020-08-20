#ifndef POICA_LANG_GADT_CONSTRUCT_VARIANTS_H
#define POICA_LANG_GADT_CONSTRUCT_VARIANTS_H

#include <poica/lang/gadt/variant.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define BOOST_VMD_REGISTER_of   (of)
#define BOOST_VMD_REGISTER_self (self)

#define BOOST_VMD_DETECT_of_of
#define BOOST_VMD_DETECT_self_self

#define POICA_P_LANG_GADT_CONSTRUCT_VARIANTS(variants)                         \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_GADT_CONSTRUCT_VARIANTS_VISIT,          \
                          BOOST_PP_EMPTY(),                                    \
                          variants)

#define POICA_P_LANG_GADT_CONSTRUCT_VARIANTS_VISIT(_r, _data, gadt_variant)    \
    POICA_P_LANG_GADT_VARIANT(BOOST_VMD_ELEM(0, gadt_variant),                 \
                              BOOST_VMD_ELEM(3, gadt_variant))

#endif // POICA_LANG_GADT_CONSTRUCT_VARIANTS_H
