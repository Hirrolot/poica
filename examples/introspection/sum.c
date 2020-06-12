#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

// clang-format off
#define MY_SUM                                                             \
    Something,                                                             \
    VARIANT(A)                                                             \
    VARIANT(B OF int)                                                      \
    VARIANT(C OF MANY FIELD(C1 OF double) FIELD(C2 OF char))               \
// clang-format on

SUM(MY_SUM);
#define SomethingINTROSPECT SUM_INTROSPECT(MY_SUM)

int main(void) {
    /*
     * Output:
     * ((VARIANT_EMPTY)(A))
     * ((VARIANT_SINGLE)(B)(int))
     * ((VARIANT_MANY)(C)( ((C1)(double)) ((C2)(char)) ))
     */
    puts(BOOST_PP_STRINGIZE(SomethingINTROSPECT));
}
