#ifndef POICA_PRIVATE_ASSOCIATIVE_ARRAY_INSERT_H
#define POICA_PRIVATE_ASSOCIATIVE_ARRAY_INSERT_H

#include <poica/private/associative_array/item.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define POICA_P_ASSOCIATIVE_ARRAY_INSERT(array, name, value)                   \
    BOOST_PP_IF(                                                               \
        BOOST_VMD_IS_EMPTY(BOOST_PP_EMPTY() array),                            \
        POICA_P_ASSOCIATIVE_ARRAY_ITEM(name, value),                           \
        POICA_P_ASSOCIATIVE_ARRAY_INSERT_NON_EMPTY(array, name, value))

#define POICA_P_ASSOCIATIVE_ARRAY_INSERT_NON_EMPTY(array, name, value)         \
    BOOST_PP_IF(                                                               \
        BOOST_VMD_IS_EMPTY(BOOST_PP_EMPTY()                                    \
                               POICA_P_ASSOCIATIVE_ARRAY_INSERT_TRY_INSERT(    \
                                   array, name, value)),                       \
        array POICA_P_ASSOCIATIVE_ARRAY_ITEM(name, value),                     \
        POICA_P_ASSOCIATIVE_ARRAY_INSERT_TRY_INSERT(array, name, value))

#define POICA_P_ASSOCIATIVE_ARRAY_INSERT_TRY_INSERT(array, name, value)        \
    BOOST_PP_SEQ_FOR_EACH_I(                                                   \
        POICA_P_ASSOCIATIVE_ARRAY_INSERT_VISIT, (array)(name)(value), array)

#define POICA_P_ASSOCIATIVE_ARRAY_INSERT_VISIT(_s, data, i, item)              \
    POICA_P_ASSOCIATIVE_ARRAY_INSERT_VISIT_AUX(BOOST_PP_SEQ_ELEM(0, data),     \
                                               BOOST_PP_SEQ_ELEM(1, data),     \
                                               BOOST_PP_SEQ_ELEM(2, data),     \
                                               i,                              \
                                               item)

#define POICA_P_ASSOCIATIVE_ARRAY_INSERT_VISIT_AUX(                            \
    array, new_item_name, new_item_value, i, item)                             \
    BOOST_PP_IF(BOOST_VMD_EQUAL(POICA_P_ASSOCIATIVE_ARRAY_ITEM_NAME((item)),   \
                                new_item_name),                                \
                BOOST_PP_SEQ_REPLACE(array,                                    \
                                     i,                                        \
                                     POICA_P_ASSOCIATIVE_ARRAY_ITEM(           \
                                         new_item_name, new_item_value)),      \
                BOOST_PP_EMPTY())

#endif // POICA_PRIVATE_ASSOCIATIVE_ARRAY_INSERT_H
