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

// The "Register" type class.

#define declRegisterLoad(type)                                                 \
    static type P(registerLoad, type)(const type *self)
#define declRegisterStore(type)                                                \
    static void P(registerStore, type)(type * self, const type *src)

// Swap two registers.
//
// 'type' must implement Register.
#define declSwap(type)                                                         \
    static void P(swap, type)(type * left, type * right, type * tmp)
#define defSwap(type)                                                          \
    declSwap(type) {                                                           \
        P(registerStore, type)(tmp, left);                                     \
        P(registerStore, type)(left, right);                                   \
        P(registerStore, type)(right, tmp);                                    \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

// Implement Register for int and define swap(int).

declRegisterLoad(int);
declRegisterStore(int);
declSwap(int);

declRegisterLoad(int) {
    return *self;
}

declRegisterStore(int) {
    *self = *src;
}

defSwap(int);

/*
 * Output:
 * ax = 2, bx = 63
 * ax = 63, bx = 2
 */
int main(void) {
    int ax = 2, bx = 63, tmp = 0;
    printf("ax = %d, bx = %d\n", ax, bx);

    P(swap, int)(&ax, &bx, &tmp);

    printf("ax = %d, bx = %d\n", ax, bx);
}
