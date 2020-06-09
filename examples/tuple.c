#include "../include/tuple.h"

#include <stdio.h>

int main(void) {
    TUPLE(const char *, int, double) tuple = {"Hello, tuples!", 123, 1885.1191};

    /*
     * Output:
     * ('Hello, tuples!', 123, 1885.119100)
     */
    printf("('%s', %d, %f)\n", tuple._0, tuple._1, tuple._2);
}
