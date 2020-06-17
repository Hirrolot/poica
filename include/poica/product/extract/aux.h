#ifndef POICA_PRODUCT_EXTRACT_AUX_H
#define POICA_PRODUCT_EXTRACT_AUX_H

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define POICA_P_PRODUCT_EXTRACT_X(macro, fields, val)                          \
    BOOST_PP_SEQ_FOR_EACH(macro, val, BOOST_PP_TUPLE_TO_SEQ(fields))           \
                                                                               \
    do {                                                                       \
    } while (false)

#endif // POICA_PRODUCT_EXTRACT_AUX_H
