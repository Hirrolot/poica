# poica
A programming language on top of C macros, supporting many modern concepts: [ADTs], [pattern matching], [type introspection], [modular programming].

[ADTs]: https://en.wikipedia.org/wiki/Algebraic_data_type
[pattern matching]: https://en.wikipedia.org/wiki/Pattern_matching
[type introspection]: https://en.wikipedia.org/wiki/Type_introspection
[algebraic effects]: https://www.eff-lang.org/handlers-tutorial.pdf
[modular programming]: https://en.wikipedia.org/wiki/Modular_programming

## Table of contents
  - [ADTs & pattern matching](#adts--pattern-matching)

## ADTs & pattern matching

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
