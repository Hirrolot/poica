#include "../include/tuple.h"

#include <stdbool.h>
#include <stdio.h>

#include <boost/preprocessor.hpp>

#define ITER_FIELDS(macro, val, count)                                         \
    BOOST_PP_REPEAT(count, DISPLAY_FIELD, val)                                 \
    do {                                                                       \
    } while (false)

#define DISPLAY_FIELD(_z, i, val)                                              \
    printf("tuple._%d = ", (i));                                               \
    printf(SPECIFIER(TUPLE_FIELD(val, i)), TUPLE_FIELD(val, i));               \
    puts("");

#define SPECIFIER(val)                                                         \
    _Generic((val), int : "%d", double : "%f", const char * : "'%s'", float * : "%p")

int main(void) {
    TUPLE(int, double, const char *, double, int, float *)
    tuple = {
        151, .2525, "Black magic", 14.1411, 64, (float *)0x1383755,
    };

    /*
     * tuple._0 = 151
     * tuple._1 = 0.252500
     * tuple._2 = 'Black magic'
     * tuple._3 = 14.141100
     * tuple._4 = 64
     * tuple._5 = 0x1383755
     */
    ITER_FIELDS(CONSUME, tuple, 6);
}
