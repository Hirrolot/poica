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

// clang-format off
choice(
    Token,
    variant(Ident, const char *)
    variant(Integer, int)
    variant(Plus)
    variant(OpenParen)
    variant(CloseParen)
);
// clang-format on

void print_token(Token token) {
    match(token) {
        of(Ident, ident) {
            printf("%s", *ident);
        }
        of(Integer, integer) {
            printf("%d", *integer);
        }
        of(Plus) {
            printf(" + ");
        }
        of(OpenParen) {
            printf("(");
        }
        of(CloseParen) {
            printf(")");
        }
    }
}

int main(void) {
    Token tokens[] = {
        OpenParen(),
        Ident("x"),
        Plus(),
        Integer(123),
        CloseParen(),
    };

    /*
     * Output:
     * (x + 123)
     */
    for (int i = 0; i < sizeof(tokens) / sizeof(tokens[0]); i++) {
        print_token(tokens[i]);
    }

    puts("");
}
