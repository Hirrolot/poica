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

#ifndef POICA_RECORD_H
#define POICA_RECORD_H

#include <poica/record/field.h>
#include <poica/record/gen/fields.h>
#include <poica/record/introspection.h>

#include <boost/preprocessor.hpp>

// This macro is variadic because, due to type introspection, it must work
// correctly if actual record data is transferred through a macro:
// RECORD(MY_RECORD);

#ifdef POICA_USE_PREFIX
#define poicaRecord(...) POICA_P_RECORD(__VA_ARGS__)
#else
#define record(...) POICA_P_RECORD(__VA_ARGS__)
#endif

#define POICA_P_RECORD(...)                                                    \
    BOOST_PP_OVERLOAD(POICA_P_RECORD_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_RECORD_1(name) POICA_P_RECORD_2(name, field(_, Unit))

#define POICA_P_RECORD_2(name, fields)                                         \
    typedef struct name {                                                      \
        POICA_P_RECORD_GEN_FIELDS(fields)                                      \
    } name

#endif // POICA_RECORD_H
