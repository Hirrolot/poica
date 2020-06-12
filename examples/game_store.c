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
    VARIANT(MkSendMessage OF MANY
        FIELD(message OF const char *) FIELD(to OF const char *)
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
        CASE(MkSendMessage, MANY(message, to)) {
            printf("Sending '%s' to '%s'...\n", *message, *to);
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
