#ifndef SUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_SINGLE_H
#define SUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_SINGLE_H

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_VARIANT_SINGLE(         \
    _data, variant_name, variant_type)                                         \
    typedef variant_type POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(           \
        variant_name);

#endif // SUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_SINGLE_H
