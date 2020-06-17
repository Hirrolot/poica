// Error handling with ADTs. This is demonstrated on parsing the "'<full name>'
// <age>" string.

#include <poica.h>

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// clang-format off
PRODUCT(
    Person,
    FIELD(full_name OF const char *)
    FIELD(age OF unsigned char)
);

// Can be represented as an ordinary enumeration, but we define it as a sum type
// for consistency.
SUM(
    ParseErr,
    VARIANT(MkInvalidAge)
    VARIANT(MkNoFirstApostrophe)
    VARIANT(MkNoSecondApostrophe)
);

SUM(
    ParseRes,
    VARIANT(MkParseOk OF Person)
    VARIANT(MkParseErr OF ParseErr)
);
// clang-format on

void skip_emptiness(const char **src) {
    while (**src != '\0' && isblank(**src)) {
        (*src)++;
    }
}

// clang-format off
SUM(
    ParseFullNameRes,
    VARIANT(MkParseFullNameOk)
    VARIANT(MkParseFullNameErr OF ParseErr)
);
// clang-format on

ParseFullNameRes parse_full_name(Person *person, const char **src) {
    if ((person->full_name = strchr(*src, '\'')) == NULL) {
        return MkParseFullNameErr(MkNoFirstApostrophe());
    }

    person->full_name++;
    *src = (char *)person->full_name;

    return MkParseFullNameOk();
}

// clang-format off
SUM(
    ParseAgeRes,
    VARIANT(MkParseAgeOk)
    VARIANT(MkParseAgeErr OF ParseErr)
);
// clang-format on

ParseAgeRes parse_age(Person *person, char **src) {
    char *age_pos;
    if ((age_pos = strchr(*src, '\'')) == NULL) {
        return MkParseAgeErr(MkNoSecondApostrophe());
    }

    *age_pos = '\0';
    age_pos++;
    *src = age_pos;

    skip_emptiness((const char **)&age_pos);

    if (sscanf(age_pos, "%hhu", &person->age) == 0) {
        return MkParseAgeErr(MkInvalidAge());
    }

    return MkParseAgeOk();
}

ParseRes parse(char *src) {
    Person person;

    {
        ParseFullNameRes res = parse_full_name(&person, (const char **)&src);
        TRY(&res, CASE(MkParseFullNameErr, err), MkParseErr(*err));
    }

    {
        ParseAgeRes res = parse_age(&person, &src);
        TRY(&res, CASE(MkParseAgeErr, err), MkParseErr(*err));
    }

    return MkParseOk(person);
}

const char *stringify_parse_err(const ParseErr *err) {
    MATCH(err) {
        CASE(MkInvalidAge) {
            return "an invalid age";
        }
        CASE(MkNoFirstApostrophe) {
            return "no first apostrophe";
        }
        CASE(MkNoSecondApostrophe) {
            return "no second apostrophe";
        }
    }
}

int main(void) {
    char src[] = "'James Brown' 73";
    ParseRes res = parse(src);

    /*
     * Output:
     * Success!
     */
    MATCH(&res) {
        CASE(MkParseOk, person) {
            assert(person->age == 73);
            assert(strcmp(person->full_name, "James Brown") == 0);
            puts("Success!");
        }
        CASE(MkParseErr, err) {
            printf("Parsing has been failed! Reason: %s\n",
                   stringify_parse_err(err));
        }
    }
}
