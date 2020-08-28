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

#include <math.h>
#include <stdio.h>

// clang-format off
interface(
    Shape,
    double (*area)(const void *self);
);

record(
    Square,
    field(width, double)
    field(height, double)
);

record(
    Triangle,
    field(a, double)
    field(b, double)
    field(c, double)
);

impl(
    (Shape) for (Square),
    (double)(area)(const void *self)(
        const Square *square = (const Square *)self;
        return square->width * square->height;
    )
);

impl(
    (Shape) for (Triangle),
    (double)(area)(const void *self)(
        const Triangle *triangle = (const Triangle *)self;
        double a = triangle->a, b = triangle->b, c = triangle->c;

        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    )
);
// clang-format off

/*
 * Output:
 * 20.400000
 * 24.000000
 */
int main(void) {
    const Square square = { .width = 6, .height = 3.4 };
    const Triangle triangle = { .a = 4, .b = 13, .c = 15};

    printf("%f\n", iMethods(Shape, Square).area(&square));
    printf("%f\n", iMethods(Shape, Triangle).area(&triangle));
}
