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

#ifndef POICA_INTERFACE_H
#define POICA_INTERFACE_H

#include <poica/force_semicolon.h>
#include <poica/private/prefix.h>

#include <poica/interface/gen/i_obj.h>
#include <poica/interface/gen/method_tables.h>
#include <poica/interface/i_obj_utils.h>
#include <poica/interface/method.h>

#include <poica/interface/checks/is_no_mut_self_methods.h>
#include <poica/interface/checks/is_no_self_methods.h>
#include <poica/interface/checks/is_no_static_methods.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX
#define poicaInterface POICA_P_INTERFACE
#else
#define interface POICA_P_INTERFACE
#endif

#define POICA_P_INTERFACE(name, methods)                                       \
    BOOST_PP_IF(POICA_P_INTERFACE_IS_NO_STATIC_METHODS(methods),               \
                BOOST_PP_EMPTY(),                                              \
                POICA_P_INTERFACE_GEN_METHOD_TABLES_STATIC(name, methods);)    \
                                                                               \
    BOOST_PP_IF(POICA_P_INTERFACE_IS_NO_SELF_METHODS(methods),                 \
                BOOST_PP_EMPTY(),                                              \
                POICA_P_INTERFACE_GEN_METHOD_TABLES_SELF(name, methods);       \
                POICA_P_GEN_I_OBJ(name);)                                      \
                                                                               \
    BOOST_PP_IF(POICA_P_INTERFACE_IS_NO_MUT_SELF_METHODS(methods),             \
                BOOST_PP_EMPTY(),                                              \
                POICA_P_INTERFACE_GEN_METHOD_TABLES_MUT_SELF(name, methods);   \
                POICA_P_GEN_MUT_I_OBJ(name);)                                  \
                                                                               \
    POICA_FORCE_SEMICOLON

#endif // POICA_INTERFACE_H
