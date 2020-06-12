# poica

[**ADTs** (**A**lgebraic **D**ata **T**ype**s**)] provide a convenient approach to combine and destruct data types. There are two main kinds of them: sum types and product types.

Simply put, a sum type is _either_ of `T1`, ..., `Tn`, and a product type is _both_ `T1`, ..., `Tn`. Another name of sum types is a [tagged union], and product types correspond to structures in C.

Here is a simple example of user commands in a game store:

[**ADTs** (**A**lgebraic **D**ata **T**ype**s**)]: https://en.wikipedia.org/wiki/Algebraic_data_type
[tagged union]: https://en.wikipedia.org/wiki/Tagged_union


[[`examples/game_store.c`](https://github.com/Hirrolot/poica/blob/master/examples/game_store.c)]
```c
#include <poica.h>

#include <stdio.h>

PRODUCT(
    Game,
    FIELD(name OF const char *)
    FIELD(cost OF double)
);

SUM(
    UserCommand,
    VARIANT(MkLogOut)
    VARIANT(MkOrderGame OF Game)
    VARIANT(MkReportBug OF MANY
        FIELD(title OF const char *) FIELD(body OF const char *)
    )
);

void process_command(UserCommand command) {
    MATCH(&command) {
        CASE(MkLogOut) {
            printf("Logging out...\n");
        }
        CASE(MkOrderGame, game) {
            printf("$%f '%s' has been ordered!\n", game->cost, game->name);
        }
        CASE(MkReportBug, MANY(title, body)) {
            printf("Reporting a bug '%s', '%s'...\n", *title, *body);
        }
    }
}

int main(void) {
    Game game = {
        .name = "Amnesia: The Dark Descent",
        .cost = 10.99,
    };
    UserCommand command = MkOrderGame(game);

    process_command(command);
}
```

ADTs can be used practically everywhere, but just to get started take a look at [AST evaluation] and [error handling].

[AST evaluation]: https://github.com/Hirrolot/poica/wiki/AST-evaluation
[error handling]: https://github.com/Hirrolot/poica/wiki/Error-handling

## Type introspection

[Type introspection] is supported in the sence that you can query the type properties of ADTs at compile-time and then handle them somehow in your hand-written macros.

Here are what product and sum types return when they are introspected:

[Type introspection]: https://en.wikipedia.org/wiki/Introspection_(computer_science)

[[`examples/introspection/product.c`](https://github.com/Hirrolot/poica/blob/master/examples/introspection/product.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_PRODUCT                                                             \
    Something,                                                                 \
    FIELD(a OF int)                                                            \
    FIELD(b OF const char *)                                                   \
    FIELD(c OF double)                                                         \

PRODUCT(MY_PRODUCT);
#define SomethingINTROSPECT PRODUCT_INTROSPECT(MY_PRODUCT)

int main(void) {
    puts(BOOST_PP_STRINGIZE(SomethingINTROSPECT));
}
```

<details>
    <summary>Output</summary>

```
((a)(int)) ((b)(const char *)) ((c)(double))
```

</details>

[[`examples/introspection/sum.c`](https://github.com/Hirrolot/poica/blob/master/examples/introspection/sum.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_SUM                                                             \
    Something,                                                             \
    VARIANT(A)                                                             \
    VARIANT(B OF int)                                                      \
    VARIANT(C OF MANY FIELD(C1 OF double) FIELD(C2 OF char))               \

SUM(MY_SUM);
#define SomethingINTROSPECT SUM_INTROSPECT(MY_SUM)

int main(void) {
    puts(BOOST_PP_STRINGIZE(SomethingINTROSPECT));
}
```

<details>
    <summary>Output</summary>

```
((POICA_VARIANT_EMPTY)(A))
((POICA_VARIANT_SINGLE)(B)(int))
((POICA_VARIANT_MANY)(C)( ((C1)(double)) ((C2)(char)) ))
```

</details>

That is, the metainformation about types is actually a [sequence] in the terms of [Boost/Preprocessor]. So the [`BOOST_PP_SEQ_*` macros] can be used to manipulate these sequences further.

[sequence]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/data/sequences.html
[Boost/Preprocessor]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/
[`BOOST_PP_SEQ_*` macros]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/headers/seq.html
