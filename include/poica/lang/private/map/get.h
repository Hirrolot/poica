/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Hirrolot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef POICA_LANG_PRIVATE_MAP_GET_H
#define POICA_LANG_PRIVATE_MAP_GET_H

#include <poica/lang/private/map/item.h>
#include <poica/lang/private/overload_on_kind.h>

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_MAP_GET(map, key)                                                             \
    POICA_P_LANG_EXPAND(BOOST_PP_IF(BOOST_VMD_IS_EMPTY(map),                                       \
                                    POICA_P_LANG_MAP_GET_EMPTY_SEQ,                                \
                                    POICA_P_LANG_MAP_GET_NON_EMPTY_SEQ)(map, key))

#define POICA_P_LANG_MAP_GET_EMPTY_SEQ(map, key) (NOT_FOUND)
#define POICA_P_LANG_MAP_GET_NON_EMPTY_SEQ(map, key)                                               \
    POICA_P_LANG_OVERLOAD_ON_KIND(                                                                 \
        POICA_P_LANG_MAP_GET_,                                                                     \
        BOOST_PP_SEQ_FOLD_LEFT(POICA_P_LANG_MAP_GET_VISIT, (NOT_FOUND_YET)(key), map))

#define POICA_P_LANG_MAP_GET_ALREADY_FOUND(_key, value) (FOUND)(value)
#define POICA_P_LANG_MAP_GET_NOT_FOUND_YET(_key)        (NOT_FOUND)

#define POICA_P_LANG_MAP_GET_VISIT(_d, state, item)                                                \
    POICA_P_LANG_OVERLOAD_ON_KIND(POICA_P_LANG_MAP_GET_VISIT_, state((item)))

#define POICA_P_LANG_MAP_GET_VISIT_ALREADY_FOUND(key, value, item) (ALREADY_FOUND)(key)(value)

#define POICA_P_LANG_MAP_GET_VISIT_NOT_FOUND_YET(key, item)                                        \
    BOOST_PP_IF(POICA_P_LANG_MAP_IS_KEY_OF_ITEM(key, item),                                        \
                POICA_P_LANG_MAP_GET_VISIT_NOT_FOUND_YET_KEY_OF_ITEM,                              \
                POICA_P_LANG_MAP_GET_VISIT_NOT_FOUND_NOT_YET_KEY_OF_ITEM)                          \
    (key, item)

#define POICA_P_LANG_MAP_GET_VISIT_NOT_FOUND_YET_KEY_OF_ITEM(key, item)                            \
    (ALREADY_FOUND)(key)(POICA_P_LANG_MAP_ITEM_VALUE(item))
#define POICA_P_LANG_MAP_GET_VISIT_NOT_FOUND_NOT_YET_KEY_OF_ITEM(key, item) (NOT_FOUND_YET)(key)

#endif // POICA_LANG_PRIVATE_MAP_GET_H
