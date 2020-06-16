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

    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
// clang-format on

int main(void) {
    Triangle triangle = {13.5146, 14, 9.2214};
    double area = compute_area(triangle);

    /*
     * Output:
     * 59.679495
     */
    printf("%f\n", area);
}
