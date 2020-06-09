#ifndef POICA_TUPLE_H
#define POICA_TUPLE_H

#include <boost/preprocessor.hpp>

#define TUPLE(...)                                                             \
    struct {                                                                   \
        BOOST_PP_SEQ_FOR_EACH_I(POICA_P_TUPLE_GEN_FIELD, _data,                \
                                BOOST_PP_TUPLE_TO_SEQ((__VA_ARGS__)))          \
    }

#define TUPLE_FIELD(tuple_name, i) BOOST_PP_CAT(tuple_name._, i)

#define POICA_P_TUPLE_GEN_FIELD(_r, _data, i, type) type BOOST_PP_CAT(_, i);

#endif // POICA_TUPLE_H
