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
#include <poica/interface/gen/methods_ptrs.h>
#include <poica/interface/method.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define poicaInterface        POICA_P_INTERFACE
#define poicaVTable           POICA_P_VTABLE
#define poicaVTableImpl       POICA_P_VTABLE_IMPL
#define poicaIObjCall         POICA_P_I_OBJ_CALL
#define poicaIObjCallWithArgs POICA_P_I_OBJ_CALL_WITH_ARGS
#define poicaInitIObj         POICA_P_INIT_I_OBJ

#else

#define interface        POICA_P_INTERFACE
#define VTable           POICA_P_VTABLE
#define VTableImpl       POICA_P_VTABLE_IMPL
#define iObjCall         POICA_P_I_OBJ_CALL
#define iObjCallWithArgs POICA_P_I_OBJ_CALL_WITH_ARGS
#define initIObj         POICA_P_INIT_I_OBJ

#endif

#define POICA_P_INTERFACE(name, functions)                                     \
    typedef struct POICA_P_VTABLE(name) {                                      \
        POICA_P_INTERFACE_GEN_METHODS_PTRS(functions)                          \
    } POICA_P_VTABLE(name);                                                    \
                                                                               \
    POICA_P_GEN_I_OBJ(name);                                                   \
    POICA_P_GEN_MUT_I_OBJ(name);                                               \
                                                                               \
    POICA_FORCE_SEMICOLON

#define POICA_P_VTABLE(interface_name)                                         \
    POICA_P_PREFIX(BOOST_PP_CAT(interface_name, _VTable))

#define POICA_P_I_OBJ_CALL(i_obj, method) (i_obj).vtable->method(&(i_obj))

#define POICA_P_I_OBJ_CALL_WITH_ARGS(i_obj, method, ...)                       \
    (i_obj).vtable.method(&(i_obj), __VA_ARGS__)

#define POICA_P_VTABLE_IMPL(interface_name, implementer_name)                  \
    BOOST_PP_CAT(POICA_P_VTABLE(interface_name), implementer_name)

#define POICA_P_INIT_I_OBJ(i_obj, new_self, new_vtable)                        \
    (i_obj).self = (new_self);                                                 \
    (i_obj).vtable = (new_vtable);

#endif // POICA_INTERFACE_H
