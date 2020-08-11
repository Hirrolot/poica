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

#ifndef POICA_INTERFACE_GEN_METHOD_TABLES_STATIC_H
#define POICA_INTERFACE_GEN_METHOD_TABLES_STATIC_H

#include <poica/private/overload_on_kind.h>
#include <poica/private/prefix.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX
#define PoicaIStaticMethods POICA_P_I_STATIC_METHODS
#else
#define IStaticMethods POICA_P_I_STATIC_METHODS
#endif

#define POICA_P_I_STATIC_METHODS(...)                                          \
    BOOST_PP_OVERLOAD(POICA_P_I_STATIC_METHODS_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_I_STATIC_METHODS_1(interface_name)                             \
    POICA_P_PREFIX(BOOST_PP_CAT(interface_name, _StaticMethods))

#define POICA_P_I_STATIC_METHODS_2(interface_name, implementer_name)           \
    BOOST_PP_CAT(                                                              \
        BOOST_PP_CAT(POICA_P_I_STATIC_METHODS_1(interface_name), _Impl_),      \
        implementer_name)

#define POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC(interface_name, methods)    \
    typedef struct POICA_P_I_STATIC_METHODS(interface_name) {                  \
        BOOST_PP_SEQ_FOR_EACH(                                                 \
            POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC_VISIT_ONE, _data,       \
            methods)                                                           \
    } POICA_P_I_STATIC_METHODS(interface_name)

#define POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC_VISIT_ONE(                  \
    _r, _data, method)                                                         \
    POICA_P_OVERLOAD_ON_KIND(                                                  \
        POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC_VISIT_ONE_, method)

#define POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC_VISIT_ONE_I_METHOD_KIND_STATIC( \
    return_type, name, params)                                                     \
    return_type(*name) params;

#define POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC_VISIT_ONE_I_METHOD_KIND_SELF( \
    return_type, name, params)

#define POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC_VISIT_ONE_I_METHOD_KIND_MUT_SELF( \
    return_type, name, params)

#endif // POICA_INTERFACE_GEN_METHOD_TABLES_STATIC_H
