# poica

## Table of contents
  - [Sum types & pattern matching](#sum-types--pattern-matching)
  - [Tuples](#tuples)
    - [Use cases](#use-cases-1)
      - [Iteration on fields](#iteration-on-fields)
  - [Algebraic effects](#algebraic-effects)

## Sum types & pattern matching

Using [sum types] (aka tagged unions) together with [pattern matching], we can _naturally_ map the problem domain to the actual code. Simply put:

 - A sum type is a type that is either a dog, a cat, or an elephant.
 - Pattern matching is doing something depending on the matching value (of a sum type). If a value is a dog, walk with it, if a cat, feed it, or if an elephant - ride it.

[sum types]: https://en.wikipedia.org/wiki/Tagged_union
[pattern matching]: https://en.wikipedia.org/wiki/Pattern_matching

Now the statements above can be encoded directly in C:

[[`examples/dog_cat_elephant.c`](https://github.com/Hirrolot/poica/blob/master/examples/dog_cat_elephant.c)]
```c
typedef struct {
    unsigned speed;
} Dog;

typedef struct {
    const char *eye_colour;
} Cat;

typedef struct {
    float ears_size;
} Elephant;

SUM(
    Animal,
    VARIANT(MkDog OF Dog)
    VARIANT(MkCat OF Cat)
    VARIANT(MkElephant OF Elephant)
);

void process_animal(Animal animal) {
    MATCH(&animal) {
        CASE(MkDog, dog) {
            printf("Dog\n");
            printf("Speed = %u km/hour\n", dog->speed);
            printf("Walking...\n");
        }
        CASE(MkCat, cat) {
            printf("Cat\n");
            printf("Eye colour = %s\n", cat->eye_colour);
            printf("Feeding...\n");
        }
        CASE(MkElephant, elephant) {
            printf("Elephant\n");
            printf("Ears size = %f meters\n", elephant->ears_size);
            printf("Riding...\n");
        }
    }

    puts("");
}

int main(void) {
    Animal dog = MkDog((Dog){.speed = 12});
    Animal cat = MkCat((Cat){.eye_colour = "green"});
    Animal elephant = MkElephant((Elephant){.ears_size = .5});

    process_animal(dog);
    process_animal(cat);
    process_animal(elephant);
}
```

<details>
  <summary>Output</summary>

```
Dog
Speed = 12 km/hour
Walking...

Cat
Eye colour = green
Feeding...

Elephant
Ears size = 0.500000 meters
Riding...
```

</details>

Practical examples of sum types include [AST evaluation] and [error handling].

[AST evaluation]: https://github.com/Hirrolot/poica/wiki/AST-evaluation
[error handling]: https://github.com/Hirrolot/poica/wiki/Error-handling

## Tuples

A tuple is just a structure with fields named `_0`, `_1`, ..., `_N`. You can define it both outside and inside procedures (aka _in-place_), like this:

```c
#include "../include/tuple.h"

#include <stdio.h>

int main(void) {
    TUPLE(const char *, int, double) tuple = {"Hello, tuples!", 123, 1885.1191};

    printf("('%s', %d, %f)\n", tuple._0, tuple._1, tuple._2);
}
```

<details>
  <summary>Output</summary>

```
('Hello, tuples!', 123, 1885.119100)
```

</details>

### Use cases

#### Iteration on fields

Tuples can be used for advanced [metaprogramming], typically using [Boost/Preprocessor]. As an example, here's how you can iterate over tuple's fields to display them:

[metaprogramming]: https://en.wikipedia.org/wiki/Metaprogramming
[Boost/Preprocessor]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/index.html

```c
#include "../include/tuple.h"

#include <stdbool.h>
#include <stdio.h>

#include <boost/preprocessor.hpp>

#define ITER_FIELDS(macro, tuple, count)                                       \
    BOOST_PP_REPEAT(count, DISPLAY_FIELD, tuple)                               \
    do {                                                                       \
    } while (false)

#define DISPLAY_FIELD(_z, i, tuple)                                            \
    printf(#tuple "._%d = ", (i));                                             \
    printf(SPECIFIER(TUPLE_FIELD(tuple, i)), TUPLE_FIELD(tuple, i));           \
    puts("");

#define SPECIFIER(field)                                                       \
    _Generic((field), int : "%d", double : "%f", const char * : "'%s'", float * : "%p")

int main(void) {
    TUPLE(int, double, const char *, double, int, float *)
    tuple = {
        151,
        .2525,
        "Black magic",
        14.1411,
        64,
        (float *)0x1383755,
    };

    ITER_FIELDS(CONSUME, tuple, 6);
}
```

<details>
    <summary>Output</summary>

```
tuple._0 = 151
tuple._1 = 0.252500
tuple._2 = 'Black magic'
tuple._3 = 14.141100
tuple._4 = 64
tuple._5 = 0x1383755
```

</details>

## Algebraic effects
