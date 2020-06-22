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

/* Demonstrates message passing using ADTs.
 *
 * One coroutine waits for a command (represented as a sum type) and responses
 * to the sender, and then the answer is printed to stdout.
 *
 * Note: this example uses libdill and currently works only under UNIX-like
 * systems. More information: http://libdill.org.
 */

#include <poica.h>

#include <assert.h>
#include <stdio.h>

#include <libdill.h>

#define CHECK_RC(rc) assert(rc != -1)

// clang-format off
enum(
    Command,
    variantMany(MkAdd, field(left, int) field(right, int))
    variant(MkDouble, int)
);
// clang-format on

coroutine void worker(int rx) {
    Command command;
    int rc = chrecv(rx, (void *)&command, sizeof(command), -1);
    CHECK_RC(rc);

    int res;
    match(&command) {
        caseMany(MkAdd, (left, right)) {
            res = *left + *right;
        }
        case(MkDouble, number) {
            res = *number * 2;
        }
    }

    rc = chsend(rx, (const void *)&res, sizeof(res), -1);
    CHECK_RC(rc);
}

int main() {
    int ch[2];
    int *tx = ch;
    int *rx = ch + 1;

    int rc = chmake(ch);
    CHECK_RC(rc);

    const Command command = MkAdd(1, 2);

    rc = go(worker(*rx));
    CHECK_RC(rc);

    rc = chsend(*tx, (const void *)&command, sizeof(command), -1);
    CHECK_RC(rc);

    int res;
    rc = chrecv(*tx, (void *)&res, sizeof(res), -1);
    CHECK_RC(rc);

    chdone(*tx);
    chdone(*rx);

    printf("%d\n", res);
}