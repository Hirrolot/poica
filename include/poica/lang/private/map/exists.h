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

#ifndef POICA_LANG_PRIVATE_MAP_EXISTS_H
#define POICA_LANG_PRIVATE_MAP_EXISTS_H

#include <poica/lang/private/map/get.h>

#define POICA_P_LANG_MAP_EXISTS(map, key)                                                          \
    POICA_P_LANG_OVERLOAD_ON_KIND(POICA_P_LANG_MAP_EXISTS_, POICA_P_LANG_MAP_GET(map, key))

#define POICA_P_LANG_MAP_EXISTS_FOUND(_value) 1
#define POICA_P_LANG_MAP_EXISTS_NOT_FOUND()   0

#endif // POICA_LANG_PRIVATE_MAP_EXISTS_H
