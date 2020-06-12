#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

// clang-format off
#define MY_PRODUCT                                                             \
    Something,                                                                 \
    FIELD(a OF int)                                                            \
    FIELD(b OF const char *)                                                   \
    FIELD(c OF double)                                                         \
// clang-format on

PRODUCT(MY_PRODUCT);
#define Something_INTROSPECT PRODUCT_INTROSPECT(MY_PRODUCT)

int main(void) {
    /*
     * Output:
     * ((a)(int)) ((b)(const char *)) ((c)(double))
     */
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}
