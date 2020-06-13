#ifndef SUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_EMPTY_H
#define SUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_EMPTY_H

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_VARIANT_EMPTY(          \
    _data, variant_name)                                                       \
    typedef POICA_P_SUM_UnusedFieldType                                        \
        POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name);

#endif // SUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_EMPTY_H
