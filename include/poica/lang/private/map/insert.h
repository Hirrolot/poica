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

#ifndef POICA_LANG_PRIVATE_MAP_INSERT_H
#define POICA_LANG_PRIVATE_MAP_INSERT_H

#include <poica/lang/private/map/is_empty.h>
#include <poica/lang/private/map/item.h>
#include <poica/lang/private/map/map_item.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define POICA_P_LANG_MAP_INSERT(map, key, value)                                                   \
    BOOST_PP_IF(POICA_P_LANG_MAP_IS_EMPTY(map),                                                    \
                POICA_P_LANG_MAP_INSERT_EMPTY,                                                     \
                POICA_P_LANG_MAP_INSERT_NON_EMPTY)                                                 \
    (map, key, value)

#define POICA_P_LANG_MAP_INSERT_EMPTY(_map, key, value) POICA_P_LANG_MAP_ITEM(key, value)
#define POICA_P_LANG_MAP_INSERT_NON_EMPTY(map, key, value)                                         \
    BOOST_PP_IF(POICA_P_LANG_MAP_EXISTS(map, key),                                                 \
                POICA_P_LANG_MAP_INSERT_NON_EMPTY_EXISTS,                                          \
                POICA_P_LANG_MAP_INSERT_NON_EMPTY_DOES_NOT_EXIST)                                  \
    (map, key, value)

#define POICA_P_LANG_MAP_INSERT_NON_EMPTY_EXISTS(map, key, value)                                  \
    POICA_P_LANG_MAP_MAP_ITEM(                                                                     \
        POICA_P_LANG_MAP_INSERT_MAP_ITEM, POICA_P_LANG_MAP_ITEM(key, value), map, key)

#define POICA_P_LANG_MAP_INSERT_NON_EMPTY_DOES_NOT_EXIST(map, key, value)                          \
    POICA_P_LANG_MAP_APPEND(map, key, value)

#define POICA_P_LANG_MAP_INSERT_MAP_ITEM(new_item, _old_item) new_item

#endif // POICA_LANG_PRIVATE_MAP_INSERT_H
