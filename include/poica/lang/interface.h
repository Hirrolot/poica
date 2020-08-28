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

#ifndef POICA_LANG_INTERFACE_H
#define POICA_LANG_INTERFACE_H

#include <poica/lang/force_semicolon.h>
#include <poica/lang/private/consume.h>
#include <poica/lang/private/prefix.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#ifndef POICA_USE_PREFIX

#define newIObj    poicaNewIObj
#define interface  poicaInterface
#define iMethods   poicaIMethods
#define impl       poicaImpl
#define staticImpl poicaStaticImpl
#define vCall      poicaVCall
#define iMethodPtr poicaIMethodPtr

#endif

#define BOOST_VMD_REGISTER_for (for)

#define BOOST_VMD_DETECT_for_for

#define poicaInterface(name, methods)                                                              \
    typedef struct POICA_P_LANG_VTABLE(name) {                                                     \
        methods                                                                                    \
    } POICA_P_LANG_VTABLE(name);                                                                   \
                                                                                                   \
    typedef struct name {                                                                          \
        const void *poica_p_self;                                                                  \
        const POICA_P_LANG_VTABLE(name) * poica_p_vtable;                                          \
    } name;                                                                                        \
                                                                                                   \
    typedef struct POICA_P_LANG_INTERFACE_MUT_NAME(name) {                                         \
        void *poica_p_self;                                                                        \
        const POICA_P_LANG_VTABLE(name) * poica_p_vtable;                                          \
    } POICA_P_LANG_INTERFACE_MUT_NAME(name);                                                       \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#define poicaIMethodPtr(interface_obj, method_name) ((interface_obj).poica_p_vtable->method_name)

#define poicaIMethods(interface_name, implementer_name)                                            \
    POICA_P_LANG_VTABLE(interface_name, implementer_name)

#define poicaImpl(...)                                                                             \
    BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1),                            \
                POICA_P_LANG_IMPL_1,                                                               \
                POICA_P_LANG_IMPL_2)                                                               \
    (__VA_ARGS__)                                                                                  \
                                                                                                   \
        POICA_FORCE_SEMICOLON

#define POICA_P_LANG_IMPL_1(data)                                                                  \
    POICA_P_LANG_IMPL_1_AUX(POICA_P_LANG_EXPAND BOOST_VMD_ELEM(0, data),                           \
                            POICA_P_LANG_EXPAND BOOST_VMD_ELEM(2, data))

#define POICA_P_LANG_IMPL_DECL(vtable_qualifiers_and_specifiers, interface_name, implementer_name) \
    vtable_qualifiers_and_specifiers const POICA_P_LANG_VTABLE(interface_name)                     \
        POICA_P_LANG_VTABLE(interface_name, implementer_name);                                     \
                                                                                                   \
    POICA_P_LANG_INTERFACE_DEF_NEW_I_OBJ(interface_name,                                           \
                                         implementer_name,                                         \
                                         POICA_P_LANG_VTABLE(interface_name, implementer_name),    \
                                         const)                                                    \
    POICA_P_LANG_INTERFACE_DEF_NEW_I_OBJ(POICA_P_LANG_INTERFACE_MUT_NAME(interface_name),          \
                                         implementer_name,                                         \
                                         POICA_P_LANG_VTABLE(interface_name, implementer_name),    \
                                         BOOST_PP_EMPTY())

#define POICA_P_LANG_IMPL_2(data, ...)                                                             \
    POICA_P_LANG_IMPL_2_AUX(POICA_P_LANG_EXPAND BOOST_VMD_ELEM(0, data),                           \
                            POICA_P_LANG_EXPAND BOOST_VMD_ELEM(2, data),                           \
                            __VA_ARGS__)

#define POICA_P_LANG_IMPL_2_AUX(interface_name, implementer_name, ...)                             \
    POICA_P_LANG_INTERFACE_IMPL_AUX(BOOST_PP_EMPTY(), interface_name, implementer_name, __VA_ARGS__)

#define poicaStaticImpl(data, methods)                                                             \
    POICA_P_LANG_STATIC_IMPL_AUX(POICA_P_LANG_EXPAND BOOST_VMD_ELEM(0, data),                      \
                                 POICA_P_LANG_EXPAND BOOST_VMD_ELEM(2, data),                      \
                                 methods)                                                          \
                                                                                                   \
    POICA_P_LANG_IMPL_DECL(static, interface_name, implementer_name)                               \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#define POICA_P_LANG_STATIC_IMPL_AUX(interface_name, implementer_name, ...)                        \
    POICA_P_LANG_INTERFACE_IMPL_AUX(static, interface_name, implementer_name, __VA_ARGS__)

#define POICA_P_LANG_INTERFACE_IMPL_AUX(                                                           \
    vtable_qualifiers_and_specifiers, interface_name, implementer_name, ...)                       \
    POICA_P_LANG_INTERFACE_IMPL_AUX2(vtable_qualifiers_and_specifiers,                             \
                                     interface_name,                                               \
                                     implementer_name,                                             \
                                     POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS(__VA_ARGS__))

#define POICA_P_LANG_INTERFACE_IMPL_AUX2(                                                          \
    vtable_qualifiers_and_specifiers, interface_name, implementer_name, methods)                   \
    POICA_P_LANG_IMPL_GEN_METHODS(interface_name, implementer_name, methods)                       \
                                                                                                   \
    const vtable_qualifiers_and_specifiers POICA_P_LANG_VTABLE(interface_name)                     \
        POICA_P_LANG_VTABLE(interface_name, implementer_name) = {                                  \
            POICA_P_LANG_IMPL_ENUM_METHOD_NAMES(interface_name, implementer_name, methods)};       \
                                                                                                   \
    POICA_P_LANG_IMPL_DECL(BOOST_PP_EMPTY(), interface_name, implementer_name)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS(...)                                           \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_VISIT,                       \
                          BOOST_PP_EMPTY(),                                                        \
                          BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_VISIT(_r, _data, method)                       \
    ((BOOST_PP_SEQ_ELEM(0, method))(BOOST_PP_SEQ_ELEM(                                             \
        1, method))POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_PARENTHESISE_PARAMS(method)         \
         POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_PARENTHESISE_BODY(method))

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_PARENTHESISE_PARAMS(method)                    \
    (POICA_P_LANG_EXPAND(POICA_P_LANG_EXPAND(                                                      \
        POICA_P_LANG_CONSUME POICA_P_LANG_CONSUME                                                  \
            POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST(method))))

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_PARENTHESISE_PARAMS_AUX1(...) (__VA_ARGS__)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST(data)                             \
    POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_AUX(                                  \
        POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_K, data)
#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_AUX(k, data)                      \
    k(POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_PICK_WITH_COMMA data)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_K(...)                            \
    POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_K_AUX(__VA_ARGS__)
#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_K_AUX(x, y)                       \
    (x) POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2(y)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2(data)                            \
    POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2_AUX(                                 \
        POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2_K, data)
#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2_AUX(k, data)                     \
    k(POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_PICK_WITH_COMMA data)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2_K(...)                           \
    POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2_K_AUX(__VA_ARGS__)
#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST2_K_AUX(x, y)                      \
    (x) POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3(y)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3(data)                            \
    POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3_AUX(                                 \
        POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3_K, data)
#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3_AUX(k, data)                     \
    k(POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_PICK_WITH_COMMA data)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3_K(...)                           \
    POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3_K_AUX(__VA_ARGS__)
#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST3_K_AUX(x, y) (x)

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_WITHOUT_LAST_PICK_WITH_COMMA(first, ...) first,

#define POICA_P_LANG_INTERFACE_IMPL_PREPARE_METHODS_PARENTHESISE_BODY(method)                      \
                                                                                                   \
    (POICA_P_LANG_EXPAND(POICA_P_LANG_EXPAND(                                                      \
        POICA_P_LANG_CONSUME POICA_P_LANG_CONSUME POICA_P_LANG_CONSUME method)))

#define POICA_P_LANG_IMPL_GEN_METHODS(interface_name, implementer_name, methods)                   \
    BOOST_PP_SEQ_FOR_EACH_I(                                                                       \
        POICA_P_LANG_IMPL_GEN_METHODS_VISIT, (interface_name)(implementer_name), methods)

#define POICA_P_LANG_IMPL_GEN_METHODS_VISIT(_r, data, i, method)                                   \
    static POICA_P_LANG_IMPL_METHOD_RETURN_TYPE(method) POICA_P_LANG_IMPL_METHOD_NAME(             \
        i, method, BOOST_PP_SEQ_ELEM(0, data), BOOST_PP_SEQ_ELEM(1, data))                         \
        POICA_P_LANG_IMPL_METHOD_PARAMS(method) POICA_P_LANG_IMPL_METHOD_BODY(method)

#define POICA_P_LANG_IMPL_ENUM_METHOD_NAMES(interface_name, implementer_name, methods)             \
    BOOST_PP_SEQ_FOR_EACH_I(                                                                       \
        POICA_P_LANG_IMPL_ENUM_METHODS_VISIT, (interface_name)(implementer_name), methods)

#define POICA_P_LANG_IMPL_ENUM_METHODS_VISIT(_r, data, i, method)                                  \
    POICA_P_LANG_IMPL_METHOD_NAME(                                                                 \
        i, method, BOOST_PP_SEQ_ELEM(0, data), BOOST_PP_SEQ_ELEM(1, data)),

#define POICA_P_LANG_IMPL_METHOD_NAME(i, method, interface_name, implementer_name)                 \
    POICA_P_LANG_PREFIX(                                                                           \
        BOOST_PP_CAT(BOOST_PP_CAT(interface_name,                                                  \
                                  BOOST_PP_CAT(implementer_name, BOOST_PP_SEQ_ELEM(1, method))),   \
                     i))
#define POICA_P_LANG_IMPL_METHOD_RETURN_TYPE(method) BOOST_PP_SEQ_ELEM(0, method)
#define POICA_P_LANG_IMPL_METHOD_PARAMS(method)      BOOST_PP_SEQ_ELEM(2, method)
#define POICA_P_LANG_IMPL_METHOD_BODY(method)                                                      \
    { POICA_P_LANG_IMPL_METHOD_BODY_EXPAND(POICA_P_LANG_EXPAND BOOST_PP_SEQ_ELEM(3, method)) }

#define POICA_P_LANG_IMPL_METHOD_BODY_EXPAND(...) __VA_ARGS__

#define POICA_P_LANG_VTABLE(...) BOOST_PP_OVERLOAD(POICA_P_LANG_VTABLE_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_LANG_VTABLE_1(interface_name)                                                      \
    POICA_P_LANG_PREFIX(BOOST_PP_CAT(interface_name, _VTable))

#define POICA_P_LANG_VTABLE_2(interface_name, implementer_name)                                    \
    BOOST_PP_CAT(BOOST_PP_CAT(POICA_P_LANG_VTABLE_1(interface_name), _), implementer_name)

#define POICA_P_LANG_INTERFACE_MUT_NAME(name) BOOST_PP_CAT(name, Mut)

#define poicaVCall(interface_obj, method_name, ...)                                                \
    BOOST_PP_IF(                                                                                   \
        BOOST_VMD_IS_EMPTY(__VA_ARGS__),                                                           \
        (interface_obj).poica_p_vtable->method_name((interface_obj).poica_p_self),                 \
        (interface_obj).poica_p_vtable->method_name((interface_obj).poica_p_self, __VA_ARGS__))

#define POICA_P_LANG_INTERFACE_DEF_NEW_I_OBJ(                                                      \
    interface_name, implementer_name, implementer_vtable_name, self_qualifier)                     \
    inline static interface_name PoicaP(poicaNewIObj, interface_name, implementer_name)(           \
        self_qualifier implementer_name * self) {                                                  \
        interface_name i_obj;                                                                      \
        i_obj.poica_p_self = self;                                                                 \
        i_obj.poica_p_vtable = &implementer_vtable_name;                                           \
        return i_obj;                                                                              \
    }

#endif // POICA_LANG_INTERFACE_H
