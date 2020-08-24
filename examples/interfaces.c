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
