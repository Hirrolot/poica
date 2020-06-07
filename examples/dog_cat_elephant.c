#include "../src/sum_type.h"

#include <stdio.h>

typedef struct {
    unsigned speed;
} Dog;

typedef struct {
    const char *eye_colour;
} Cat;

typedef struct {
    float ears_size;
} Elephant;

// clang-format off
SUM(
    AnimalKind,
    VARIANT(MkDog OF Dog)
    VARIANT(MkCat OF Cat)
    VARIANT(MkElephant OF Elephant)
);
// clang-format on

typedef struct {
    const char *name;
    unsigned age;
    AnimalKind kind;
} Animal;

void process_animal(Animal animal) {
    printf("Age = %u\n", animal.age);
    printf("Name = %s\n", animal.name);

    MATCH(&animal.kind) {
        CASE(MkDog, dog) {
            printf("Kind = dog\n");
            printf("Speed = %u km/hour\n", dog->speed);
            printf("Action: walking\n");
        }
        CASE(MkCat, cat) {
            printf("Kind = cat\n");
            printf("Eye colour = %s\n", cat->eye_colour);
            printf("Action: feeding\n");
        }
        CASE(MkElephant, elephant) {
            printf("Kind = elephant\n");
            printf("Ears size = %f meters\n", elephant->ears_size);
            printf("Action: riding\n");
        }
    }

    puts("");
}

int main(void) {
    // clang-format off
    Animal dog = {
        .name = "Pitty",
        .age = 2,
        .kind = MkDog((Dog){.speed = 12})
    };
    Animal cat = {
        .name = "Dazy",
        .age = 5,
        .kind = MkCat((Cat){.eye_colour = "green"})
    };
    Animal elephant = {
        .name = "Hurry",
        .age = 2,
        .kind = MkElephant((Elephant){.ears_size = .5})
    };
    // clang-format on

    process_animal(dog);
    process_animal(cat);
    process_animal(elephant);
}
