#include <math.h>
#include <stdio.h>

#include <poica.h>

// clang-format off
PRODUCT(
    Triangle,
    FIELD(a OF double)
    FIELD(b OF double)
    FIELD(c OF double)
);
// clang-format on

// clang-format off
double compute_area(Triangle triangle) {
    EXTRACT((a, b, c) FROM (&triangle OF Triangle));

    const double p = (a + b + c) / 2;
    const double area = sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}
// clang-format on

int main(void) {
    Triangle triangle = {4, 13, 15};

    /*
     * Output:
     * 24.000000
     */
    printf("%f\n", compute_area(triangle));
}
