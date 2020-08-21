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

#ifndef POICA_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP_H
#define POICA_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP_H

#include <poica/lang/gadt/order_entities_to_map.h>

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP(...)                    \
    POICA_P_LANG_GADT_ORDER_ENTITIES_TO_MAP(                                   \
        POICA_P_LANG_MATCH_GADT_GET_ARM_REST,                                  \
        POICA_P_LANG_MATCH_GADT_GET_ARM_TYPES,                                 \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#endif // POICA_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP_H
