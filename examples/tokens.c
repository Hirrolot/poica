#include <poica.h>

#include <stdio.h>

// clang-format off
SUM(
    Token,
    VARIANT(MkIdent OF const char *)
    VARIANT(MkInteger OF int)
    VARIANT(MkComma)
    VARIANT(MkPlus)
    VARIANT(MkOpenParen)
    VARIANT(MkCloseParen)
);
// clang-format on

void print_token(Token token) {
    MATCH(&token) {
        CASE(MkIdent, ident) {
            printf("%s", *ident);
        }
        CASE(MkInteger, integer) {
            printf("%d", *integer);
        }
        CASE(MkPlus) {
            printf(" + ");
        }
        CASE(MkOpenParen) {
            printf("(");
        }
        CASE(MkCloseParen) {
            printf(")");
        }
    }
}

int main(void) {
    Token tokens[] = {
        MkOpenParen(),
        MkIdent("x"),
        MkPlus(),
        MkInteger(123),
        MkCloseParen(),
    };

    /*
     * Output:
     * (x + 123)
     */
    for (int i = 0; i < sizeof(tokens) / sizeof(tokens[0]); i++) {
        print_token(tokens[i]);
    }

    puts("");
}
