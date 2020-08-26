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

#ifndef POICA_LANG_PRIVATE_MAP_MAP_ITEM_H
#define POICA_LANG_PRIVATE_MAP_MAP_ITEM_H

#include <poica/lang/private/call_macro.h>
#include <poica/lang/private/map/is_empty.h>
#include <poica/lang/private/map/item.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define POICA_P_LANG_MAP_MAP_ITEM(mapping, aux_data, map, key)                 \
    BOOST_PP_IF(POICA_P_LANG_MAP_IS_EMPTY(map),                                \
                POICA_P_LANG_MAP_MAP_ITEM_EMPTY,                               \
                POICA_P_LANG_MAP_MAP_ITEM_NON_EMPTY)                           \
    (mapping, aux_data, map, key)

#define POICA_P_LANG_MAP_MAP_ITEM_EMPTY(_mapping, _aux_data, _map, _key)       \
    POICA_P_LANG_MAP()
#define POICA_P_LANG_MAP_MAP_ITEM_NON_EMPTY(mapping, aux_data, map, key)       \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_LANG_MAP_MAP_ITEM_VISIT, (mapping)(aux_data)(key), map)

#define POICA_P_LANG_MAP_MAP_ITEM_VISIT(_s, data, item)                        \
    POICA_P_LANG_CALL_MACRO_SEQ_ARGS(POICA_P_LANG_MAP_MAP_ITEM_VISIT_AUX,      \
                                     data((item)))

#define POICA_P_LANG_MAP_MAP_ITEM_VISIT_AUX(mapping, aux_data, key, item)      \
    BOOST_PP_IF(POICA_P_LANG_MAP_IS_KEY_OF_ITEM(key, item),                    \
                POICA_P_LANG_MAP_MAP_ITEM_REPLACE(mapping, aux_data, item),    \
                item)

#define POICA_P_LANG_MAP_MAP_ITEM_REPLACE(mapping, aux_data, item)             \
    POICA_P_LANG_MAP_ITEM(                                                     \
        POICA_P_LANG_MAP_ITEM_KEY(item),                                       \
        mapping(aux_data, POICA_P_LANG_MAP_ITEM_VALUE(item)))

#endif // POICA_LANG_PRIVATE_MAP_MAP_ITEM_H
