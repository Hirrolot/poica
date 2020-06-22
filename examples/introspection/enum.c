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

#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

// clang-format off
#define MY_ENUM                                                             \
    Something,                                                              \
    variant(MkA)                                                            \
    variant(MkB, int)                                                       \
    variantMany(MkC, field(c1, double) field(c2, char))
// clang-format on

enum(MY_ENUM);
#define Something_INTROSPECT POICA_ENUM_INTROSPECT(MY_ENUM)

int main(void) {
    /*
     * Output:
     * ((POICA_VARIANT_KIND_EMPTY)(MkA))
     * ((POICA_VARIANT_KIND_SINGLE)(MkB)(int))
     * ((POICA_VARIANT_KIND_MANY)(MkC)( ((c1)(double)) ((c2)(char)) ))
     */
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}
