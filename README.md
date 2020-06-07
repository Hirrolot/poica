# poica

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
```

Output:

```
Kind = dog
Speed = 12 km/hour
Action: walking

Kind = cat
Eye colour = green
Action: feeding

Kind = elephant
Ears size = 0.500000 meters
Action: riding
```

### AST evaluation
One practical use case of sum types is [AST] evaluation:

[AST]: https://en.wikipedia.org/wiki/Abstract_syntax_tree

[[`examples/ast_evaluator.c`](https://github.com/Hirrolot/poica/blob/master/examples/ast_evaluator.c)]
```c
#include "../src/obj.h"
#include "../src/sum_type.h"

#include <stdio.h>

typedef struct {
    const struct Expr *left, *right;
} ExprPair;

SUM(
    Expr,
    VARIANT(MkConst OF double)
    VARIANT(MkAdd OF ExprPair)
    VARIANT(MkSub OF ExprPair)
    VARIANT(MkMul OF ExprPair)
    VARIANT(MkDiv OF ExprPair)
);

double eval(const struct Expr *expr) {
    MATCH(expr) {
        CASE(MkConst, number) {
            return *number;
        }
        CASE(MkAdd, add) {
            return eval(add->left) + eval(add->right);
        }
        CASE(MkSub, sub) {
            return eval(sub->left) - eval(sub->right);
        }
        CASE(MkMul, mul) {
            return eval(mul->left) * eval(mul->right);
        }
        CASE(MkDiv, div) {
            return eval(div->left) / eval(div->right);
        }
    }
}

#define OP(op, left, right)                                                    \
    Mk##op((ExprPair){OBJ(left OF struct Expr), OBJ(right OF struct Expr)})

int main(void) {
    Expr expr = OP(Add, MkConst(53),
                   OP(Sub, OP(Div, MkConst(155), MkConst(5)), MkConst(113)));

    printf("%f\n", eval(&expr));
}

#undef OP
```

Output:

```
-29.000000
```
