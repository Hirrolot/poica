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

#include <assert.h>
#include <stdio.h>

typedef const char *Msg;

DefEither(int, Msg);

void print_either(P(Either, int, Msg) either) {
    match(either) {
        of(P(Left, int, Msg), number) {
            printf("Left(%d)\n", *number);
        }
        of(P(Right, int, Msg), msg) {
            printf("Right(\"%s\")\n", *msg);
        }
    }
}

int main(void) {
    P(Either, int, Msg) either1 = P(Left, int, Msg)(123);

    /*
     * Output:
     * Left(123)
     */
    print_either(either1);
    assert(P(isLeft, int, Msg)(either1));
    assert(!P(isRight, int, Msg)(either1));

    P(Either, int, Msg) either2 = P(Right, int, Msg)("Hello");

    /*
     * Output:
     * Right("Hello")
     */
    print_either(either2);
    assert(!P(isLeft, int, Msg)(either2));
    assert(P(isRight, int, Msg)(either2));
}
