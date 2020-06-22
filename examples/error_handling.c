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

// Error handling with ADTs. This is demonstrated on parsing the "'<full name>'
// <age>" string.

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

// Can be represented as an ordinary enumeration, but we define it as a sum type
// for consistency.
choice(
    ParseErr,
    variant(MkInvalidAge)
    variant(MkNoFirstApostrophe)
    variant(MkNoSecondApostrophe)
);

choice(
    ParseRes,
    variant(MkParseOk, Person)
    variant(MkParseErr, ParseErr)
);
// clang-format on

void skip_emptiness(const char **src) {
    while (**src != '\0' && isblank(**src)) {
        (*src)++;
    }
}

// clang-format off
choice(
    ParseFullNameRes,
    variant(MkParseFullNameOk)
    variant(MkParseFullNameErr, ParseErr)
);
// clang-format on

ParseFullNameRes parse_full_name(Person *person, const char **src) {
    if ((person->full_name = strchr(*src, '\'')) == NULL) {
        return MkParseFullNameErr(MkNoFirstApostrophe());
    }

    person->full_name++;
    *src = (const char *)person->full_name;

    return MkParseFullNameOk();
}

// clang-format off
choice(
    ParseAgeRes,
    variant(MkParseAgeOk)
    variant(MkParseAgeErr, ParseErr)
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
        try
            (&res, of(MkParseFullNameErr, err), MkParseErr(*err));
    }

    {
        ParseAgeRes res = parse_age(&person, &src);
        try
            (&res, of(MkParseAgeErr, err), MkParseErr(*err));
    }

    return MkParseOk(person);
}

const char *stringify_parse_err(const ParseErr *err) {
    match(err) {
        of(MkInvalidAge) {
            return "a range must be a nonnegative integral number";
        }
        of(MkNoFirstApostrophe) {
            return "no apostrophe before a full name";
        }
        of(MkNoSecondApostrophe) {
            return "no apostrophe after a full name";
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
    match(&res) {
        of(MkParseOk, person) {
            assert(person->age == 73);
            assert(strcmp(person->full_name, "James Brown") == 0);
            puts("Success!");
        }
        of(MkParseErr, err) {
            printf("Parsing has been failed! Reason: %s.\n",
                   stringify_parse_err(err));
        }
    }
}
