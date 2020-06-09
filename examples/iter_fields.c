#include "../include/tuple.h"

#include <stdbool.h>
#include <stdio.h>

#include <boost/preprocessor.hpp>

#define ITER_FIELDS(macro, val, start_idx, end_idx)                            \
    BOOST_PP_REPEAT_FROM_TO(start_idx, end_idx, INVOKE, (macro)(val))          \
    do {                                                                       \
    } while (false)

#define INVOKE(_z, i, data) MACRO(data)(i, VAL(data))

#define MACRO(data) BOOST_PP_SEQ_ELEM(0, data)
#define VAL(data)   BOOST_PP_SEQ_ELEM(1, data)

#define CONSUME(i, val)                                                        \
    printf("tuple._%d = ", (i));                                               \
    printf(SPECIFIER(BOOST_PP_CAT(val._, i)), BOOST_PP_CAT(val._, i));         \
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
    ITER_FIELDS(CONSUME, tuple, 0, 6);
}
