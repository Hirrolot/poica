#include <poica.h>

#include <stdio.h>

typedef const char *Msg;

DefPair(Msg, double);

int main(void) {
    Pair(Msg, double) pair = {"Hello", 89267.2529909};

    /*
     * Output:
     * fst = Hello
     * snd = 89267.252991
     */
    printf("fst = %s\n", pair.fst);
    printf("snd = %f\n", pair.snd);
}
