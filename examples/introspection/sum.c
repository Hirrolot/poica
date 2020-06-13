#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

// clang-format off
#define MY_SUM                                                             \
    Something,                                                             \
    VARIANT(MkA)                                                           \
    VARIANT(MkB OF int)                                                    \
    VARIANT(MkC OF MANY FIELD(c1 OF double) FIELD(c2 OF char))             \
// clang-format on

SUM(MY_SUM);
#define Something_INTROSPECT SUM_INTROSPECT(MY_SUM)

int main(void) {
    /*
     * Output:
     * ((POICA_VARIANT_EMPTY)(MkA))
     * ((POICA_VARIANT_SINGLE)(MkB)(int))
     * ((POICA_VARIANT_MANY)(MkC)( ((c1)(double)) ((c2)(char)) ))
     */
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}
