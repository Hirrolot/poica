/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Hirrolot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Error handling with ADTs. This is demonstrated on parsing the "'<full name>'
 * <age>" string.
 */

#include <poica.h>

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// clang-format off
record(
    Person,
    field(full_name, const char *)
    field(age, unsigned char)
);
// clang-format on

typedef enum {
    INVALID_AGE,
    NO_FIRST_APOSTROPHE,
    NO_SECOND_APOSTROPHE,
} ParseErr;

const char *err_msgs[] = {
    [INVALID_AGE] = "a range must be a nonnegative integral number",
    [NO_FIRST_APOSTROPHE] = "no apostrophe before a full name",
    [NO_SECOND_APOSTROPHE] = "no apostrophe after a full name",
};

ResDef(Person, ParseErr);
MaybeDef(ParseErr);

void skip_emptiness(const char **src) {
    while (**src != '\0' && isblank(**src)) {
        (*src)++;
    }
}

Maybe(ParseErr) parse_full_name(Person *person, const char **src) {
    if ((person->full_name = strchr(*src, '\'')) == NULL) {
        return Just(ParseErr)(NO_FIRST_APOSTROPHE);
    }

    person->full_name++;
    *src = (const char *)person->full_name;

    return Nothing(ParseErr)();
}

Maybe(ParseErr) parse_age(Person *person, char **src) {
    char *age_pos;
    if ((age_pos = strchr(*src, '\'')) == NULL) {
        return Just(ParseErr)(NO_SECOND_APOSTROPHE);
    }

    *age_pos = '\0';
    age_pos++;
    *src = age_pos;

    skip_emptiness((const char **)&age_pos);

    if (sscanf(age_pos, "%hhu", &person->age) == 0) {
        return Just(ParseErr)(INVALID_AGE);
    }

    return Nothing(ParseErr)();
}

Res(Person, ParseErr) parse(char *src) {
    Person person;

    Maybe(ParseErr) res1 = parse_full_name(&person, (const char **)&src);
    try
        (res1, Just(ParseErr), Err(Person, ParseErr));

    Maybe(ParseErr) res2 = parse_age(&person, &src);
    try
        (res2, Just(ParseErr), Err(Person, ParseErr));

    return Ok(Person, ParseErr)(person);
}

int main(void) {
    char src[] = "'James Brown' 73";
    Res(Person, ParseErr) res = parse(src);

    /*
     * Output:
     * Success!
     */
    match(res) {
        of(Ok(Person, ParseErr), person) {
            assert(person->age == 73);
            assert(strcmp(person->full_name, "James Brown") == 0);
            puts("Success!");
        }
        of(Err(Person, ParseErr), err) {
            printf("Parsing has been failed! Reason: %s.\n", err_msgs[*err]);
        }
    }
}
