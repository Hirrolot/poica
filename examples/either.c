#include <poica.h>

#include <assert.h>
#include <stdio.h>

typedef const char *Msg;

DefEither(int, Msg);

void print_either(Either(int, Msg) either) {
    match(either) {
        of(Left(int, Msg), number) {
            printf("Left(%d)\n", *number);
        }
        of(Right(int, Msg), msg) {
            printf("Right(\"%s\")\n", *msg);
        }
    }
}

int main(void) {
    Either(int, Msg) either1 = Left(int, Msg)(123);

    /*
     * Output:
     * Left(123)
     */
    print_either(either1);
    assert(isLeft(int, Msg)(either1));
    assert(!isRight(int, Msg)(either1));

    Either(int, Msg) either2 = Right(int, Msg)("Hello");

    /*
     * Output:
     * Right("Hello")
     */
    print_either(either2);
    assert(!isLeft(int, Msg)(either2));
    assert(isRight(int, Msg)(either2));
}
