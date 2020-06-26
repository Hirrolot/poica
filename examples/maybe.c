#include <poica.h>

#include <assert.h>
#include <stdio.h>

typedef const char *Msg;

DefMaybe(int);
DefMaybe(Msg);

int main(void) {
    Maybe(int) maybe1 = Just(int)(123);

    /*
     * Output:
     * Just(123)
     */
    match(maybe1) {
        of(Just(int), number) {
            printf("Just(%d)\n", *number);
        }
        of(Nothing(int)) {
            puts("Nothing");
        }
    }

    assert(isJust(int)(maybe1));
    assert(!isNothing(int)(maybe1));

    Maybe(Msg) maybe2 = Nothing(Msg)();

    /*
     * Output:
     * Nothing
     */
    match(maybe2) {
        of(Just(Msg), msg) {
            printf("Just(\"%s\")\n", *msg);
        }
        of(Nothing(Msg)) {
            puts("Nothing");
        }
    }

    assert(!isJust(Msg)(maybe2));
    assert(isNothing(Msg)(maybe2));
}
