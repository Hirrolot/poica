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

#ifndef POICA_PRIVATE_AUX_H
#define POICA_PRIVATE_AUX_H

#include <boost/preprocessor.hpp>

#define POICA_P_PREFIX(something) BOOST_PP_CAT(POICA_P_, something)

/* Forces a user to put a semicolon.
 *
 * This works by (ab)using the concept of tentative definitions. A translation
 * unit will look like this:
 *
 * ...
 * static int poica_p_force_semicolon;
 * ...
 * static int poica_p_force_semicolon;
 * ...
 * ...
 *
 * All these declarations are tentative. Eventually a compiler won't find an
 * external definition of poica_p_force_semicolon and eventually produce an
 * external definition with an initializer equal to 0.
 */
#define POICA_P_FORCE_SEMICOLON static int poica_p_force_semicolon

#endif // POICA_PRIVATE_AUX_H
