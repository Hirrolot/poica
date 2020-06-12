#include "../include/poica.h"

#include <stdio.h>

// clang-format off
PRODUCT(
    Game,
    FIELD(name OF const char *)
    FIELD(cost OF unsigned)
);

SUM(
    UserCommand,
    VARIANT(MkLogOut)
    VARIANT(MkOrderGame OF Game)
    VARIANT(MkBugReport OF MANY
        FIELD(title OF const char *) FIELD(body OF const char *)
    )
);
// clang-format on

void process_command(UserCommand command) {
    MATCH(&command) {
        CASE(MkLogOut) {
            printf("Logging out...\n");
        }
        CASE(MkOrderGame, game) {
            printf("$%u '%s' has been ordered!\n", game->cost, game->name);
        }
        CASE(MkBugReport, MANY(title, body)) {
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
