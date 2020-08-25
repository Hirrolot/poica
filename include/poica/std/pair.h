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

#ifndef POICA_STD_PAIR_H
#define POICA_STD_PAIR_H

#include <poica/lang/p.h>

#include <poica/lang/record.h>

#ifdef POICA_USE_PREFIX
#define PoicaDefPair POICA_P_STD_PAIR_DEF
#else
#define DefPair POICA_P_STD_PAIR_DEF
#endif

#define POICA_P_STD_PAIR_DEF(fst_type, snd_type)                               \
    POICA_P_LANG_RECORD(POICA_P_LANG_P(Pair, fst_type, snd_type),              \
                        POICA_P_LANG_FIELD(fst, fst_type)                      \
                            POICA_P_LANG_FIELD(snd, snd_type))

#endif // POICA_STD_PAIR_H
