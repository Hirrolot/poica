#include <poica.h>

#include <assert.h>
#include <stdio.h>

// clang-format off
choice(
    MyChoice,
    variant(MkInt, int)
    variant(MkStr, const char *)
    variant(MkDouble, double)
);
// clang-format on

int main(void) {
    MyChoice choice1 = MkInt(123), choice2 = MkStr("Hello"),
             choice3 = MkInt(6578);

    assert(variantTag(&choice1) != variantTag(&choice2));
    assert(variantTag(&choice1) == variantTag(&choice3));
}
