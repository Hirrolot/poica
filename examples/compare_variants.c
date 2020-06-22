#include <poica.h>

#include <assert.h>
#include <stdio.h>

// clang-format off
enum(
    MyEnum,
    variant(MkInt, int)
    variant(MkStr, const char *)
    variant(MkDouble, double)
);
// clang-format on

int main(void) {
    MyEnum enum1 = MkInt(123), enum2 = MkStr("Hello"), enum3 = MkInt(6578);

    assert(variantTag(&enum1) != variantTag(&enum2));
    assert(variantTag(&enum1) == variantTag(&enum3));
}
