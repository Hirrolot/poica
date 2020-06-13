#ifndef POICA_PRODUCT_INTROSPECTION_H
#define POICA_PRODUCT_INTROSPECTION_H

#include <boost/preprocessor.hpp>

#define PRODUCT_INTROSPECT(...)                      POICA_P_PRODUCT_INTROSPECT_AUX(__VA_ARGS__)
#define POICA_P_PRODUCT_INTROSPECT_AUX(name, fields) fields

#define FIELD_NAME(field) BOOST_PP_SEQ_ELEM(0, field)
#define FIELD_TYPE(field) BOOST_PP_SEQ_ELEM(1, field)

#define PRODUCT_FIELD_NAMES(fields)                                            \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_PRODUCT_GEN_FIELD_NAME, _data, fields)

#define POICA_P_PRODUCT_GEN_FIELD_NAME(_r, _data, field) FIELD_NAME(field),

#define PRODUCT_FIELDS_AS_PARAMS(fields)                                       \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_PRODUCT_GEN_FIELD_AS_PARAM,                  \
                          _data,                                               \
                          BOOST_PP_SEQ_POP_BACK(fields))                       \
                                                                               \
    POICA_P_PRODUCT_GEN_FIELD_AS_PARAM_LAST(                                   \
        BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(fields)), fields))

#define POICA_P_PRODUCT_GEN_FIELD_AS_PARAM(_r, _data, field)                   \
    FIELD_TYPE(field) FIELD_NAME(field),

#define POICA_P_PRODUCT_GEN_FIELD_AS_PARAM_LAST(field)                         \
    FIELD_TYPE(field) FIELD_NAME(field)

#endif // POICA_PRODUCT_INTROSPECTION_H
