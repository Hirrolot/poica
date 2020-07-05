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

#define declRegisterLoad(type) static type registerLoad(type)(const type *self)
#define declRegisterStore(type)                                                \
    static void registerStore(type)(type * self, const type *src)

#define implRegisterLoad(type)  declRegisterLoad(type)
#define implRegisterStore(type) declRegisterStore(type)

#define registerLoad(type)  POICA_MONOMORPHISE(registerLoad, type)
#define registerStore(type) POICA_MONOMORPHISE(registerStore, type)

// The "Init type class.

#define declInit(type) static type init(type)(void)
#define implInit(type) declInit(type)

#define init(type) POICA_MONOMORPHISE(init, type)

// Swap two registers.

// 'type' must implement Register and Init.
#define declSwap(type) static void swap(type)(type * left, type * right)
#define defSwap(type)                                                          \
    declSwap(type) {                                                           \
        type temp = init(type)();                                              \
        registerStore(type)(&temp, left);                                      \
        registerStore(type)(left, right);                                      \
        registerStore(type)(right, &temp);                                     \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

#define swap(type) POICA_MONOMORPHISE(swap, type)

// Define Register, Init, and swap for int.

declRegisterLoad(int);
declRegisterStore(int);
declSwap(int);

implRegisterLoad(int) {
    return *self;
}

implRegisterStore(int) {
    *self = *src;
}

implInit(int) {
    return 0;
}

defSwap(int);

/*
 * Output:
 * ax = 2, bx = 63
 * ax = 63, bx = 2
 */
int main(void) {
    int ax = 2, bx = 63;
    printf("ax = %d, bx = %d\n", ax, bx);

    swap(int)(&ax, &bx);

    printf("ax = %d, bx = %d\n", ax, bx);
}
