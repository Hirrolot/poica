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

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#ifdef POICA_USE_PREFIX

#define poicaInterface  POICA_P_INTERFACE
#define PoicaVTable     POICA_P_VTABLE
#define poicaImpl       POICA_P_IMPL
#define poicaStaticImpl POICA_P_STATIC_IMPL
#define poicaVCall      POICA_P_V_CALL

#define POICA_P_NEW_I_OBJ poicaNewIObj

#else

#define interface  POICA_P_INTERFACE
#define VTable     POICA_P_VTABLE
#define impl       POICA_P_IMPL
#define staticImpl POICA_P_STATIC_IMPL
#define vCall      POICA_P_V_CALL

#define POICA_P_NEW_I_OBJ newIObj

#endif

#define POICA_P_INTERFACE(name, methods)                                       \
    typedef struct POICA_P_VTABLE(name) {                                      \
        methods                                                                \
    } POICA_P_VTABLE(name);                                                    \
                                                                               \
    typedef struct name {                                                      \
        const void *self;                                                      \
        const POICA_P_VTABLE(name) * vtable;                                   \
    } name;                                                                    \
                                                                               \
    typedef struct POICA_P_INTERFACE_MUT_NAME(name) {                          \
        void *self;                                                            \
        const POICA_P_VTABLE(name) * vtable;                                   \
    } POICA_P_INTERFACE_MUT_NAME(name);                                        \
                                                                               \
    POICA_FORCE_SEMICOLON

#define POICA_P_IMPL(interface_name, implementer_name, methods)                \
    POICA_P_INTERFACE_IMPL_AUX(                                                \
        static, interface_name, implementer_name, methods)

#define POICA_P_STATIC_IMPL(interface_name, implementer_name, methods)         \
    POICA_P_INTERFACE_IMPL_AUX(                                                \
        BOOST_PP_EMPTY(), interface_name, implementer_name, methods)

#define POICA_P_INTERFACE_IMPL_AUX(vtable_qualifiers_and_specifiers,           \
                                   interface_name,                             \
                                   implementer_name,                           \
                                   methods)                                    \
    const vtable_qualifiers_and_specifiers POICA_P_VTABLE(interface_name)      \
        POICA_P_VTABLE(interface_name, implementer_name) = {                   \
            POICA_P_EXPAND(POICA_P_EXPAND methods)};                           \
                                                                               \
    POICA_P_INTERFACE_DEF_NEW_I_OBJ(                                           \
        interface_name,                                                        \
        implementer_name,                                                      \
        POICA_P_VTABLE(interface_name, implementer_name),                      \
        const)                                                                 \
    POICA_P_INTERFACE_DEF_NEW_I_OBJ(                                           \
        POICA_P_INTERFACE_MUT_NAME(interface_name),                            \
        implementer_name,                                                      \
        POICA_P_VTABLE(interface_name, implementer_name),                      \
        BOOST_PP_EMPTY())                                                      \
                                                                               \
    POICA_FORCE_SEMICOLON

#define POICA_P_VTABLE(...)                                                    \
    BOOST_PP_OVERLOAD(POICA_P_VTABLE_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_VTABLE_1(interface_name)                                       \
    POICA_P_PREFIX(BOOST_PP_CAT(interface_name, _VTable))

#define POICA_P_VTABLE_2(interface_name, implementer_name)                     \
    BOOST_PP_CAT(BOOST_PP_CAT(POICA_P_VTABLE_1(interface_name), _),            \
                 implementer_name)

#define POICA_P_INTERFACE_MUT_NAME(name) BOOST_PP_CAT(name, Mut)

#define POICA_P_V_CALL(interface_obj, method, ...)                             \
    BOOST_PP_IF(                                                               \
        BOOST_VMD_IS_EMPTY(__VA_ARGS__),                                       \
        (interface_obj).vtable->method((interface_obj).self),                  \
        (interface_obj).vtable->method((interface_obj).self, __VA_ARGS__))

#define POICA_P_INTERFACE_DEF_NEW_I_OBJ(                                       \
    interface_name, implementer_name, implementer_vtable_name, self_qualifier) \
    inline static interface_name P(                                            \
        POICA_P_NEW_I_OBJ, interface_name, implementer_name)(                  \
        self_qualifier implementer_name * self) {                              \
        interface_name i_obj;                                                  \
        i_obj.self = self;                                                     \
        i_obj.vtable = &implementer_vtable_name;                               \
        return i_obj;                                                          \
    }

#endif // POICA_INTERFACE_H
