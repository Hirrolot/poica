#ifndef POICA_LANG_PRIVATE_MAP_ITEM_H
#define POICA_LANG_PRIVATE_MAP_ITEM_H

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_MAP_ITEM(key, value) ((key)(value))

#define POICA_P_LANG_MAP_ITEM_KEY(item)                                        \
    BOOST_PP_SEQ_ELEM(0, POICA_P_LANG_MAP_ITEM_EXPAND item)

#define POICA_P_LANG_MAP_ITEM_VALUE(item)                                      \
    BOOST_PP_SEQ_ELEM(1, POICA_P_LANG_MAP_ITEM_EXPAND item)

#define POICA_P_LANG_MAP_ITEM_EXPAND(...) __VA_ARGS__

#define POICA_P_LANG_MAP_IS_KEY_OF_ITEM(key, item)                             \
    BOOST_VMD_EQUAL(POICA_P_LANG_MAP_ITEM_KEY(item), key)

#endif // POICA_LANG_PRIVATE_MAP_ITEM_H
