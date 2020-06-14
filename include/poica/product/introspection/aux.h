#ifndef POICA_PRODUCT_INTROSPECTION_AUX_H
#define POICA_PRODUCT_INTROSPECTION_AUX_H

#include <boost/preprocessor.hpp>

#define POICA_P_PRODUCT_FIELD_X_SEQ(macro, fields)                             \
    BOOST_PP_SEQ_FOR_EACH(macro, _data, fields)

#define POICA_P_PRODUCT_FIELD_X_TUPLE(macro, macro_last, fields)               \
    (BOOST_PP_SEQ_FOR_EACH(macro, _data, BOOST_PP_SEQ_POP_BACK(fields))        \
                                                                               \
         macro_last(BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(fields)), \
                                      fields)))

#endif // POICA_PRODUCT_INTROSPECTION_AUX_H
