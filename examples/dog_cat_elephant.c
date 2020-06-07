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
    Animal,
    VARIANT(MkDog OF Dog)
    VARIANT(MkCat OF Cat)
    VARIANT(MkElephant OF Elephant)
);
// clang-format on

void process_animal(Animal animal) {
    MATCH(&animal) {
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
    Animal dog = MkDog((Dog){.speed = 12});
    Animal cat = MkCat((Cat){.eye_colour = "green"});
    Animal elephant = MkElephant((Elephant){.ears_size = .5});

    process_animal(dog);
    process_animal(cat);
    process_animal(elephant);
}
