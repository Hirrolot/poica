# poica

[**ADTs** (**A**lgebraic **D**ata **T**ype**s**)] provide a convenient approach to combine and destruct data types. There are two main kinds of them: sum types and product types.

Simply put, a sum type is _either_ of `T1`, ..., `Tn`, and a product type is _both_ `T1`, ..., `Tn`. Another name of sum types is a [tagged union], and product types correspond to structures in C.

Here is a simple example of game store commands:

[**ADTs** (**A**lgebraic **D**ata **T**ype**s**)]: https://en.wikipedia.org/wiki/Algebraic_data_type
[tagged union]: https://en.wikipedia.org/wiki/Tagged_union

```c
#include <poica.h>

#include <stdio.h>

PRODUCT(
    Game,
    FIELD(name OF const char *)
    FIELD(cost OF unsigned)
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
            printf("$%u '%s' has been ordered!\n", game->cost, game->name);
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
