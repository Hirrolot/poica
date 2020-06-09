# poica

## Table of contents
  - [Tuples](#tuples)
    - [Use cases](#use-cases)
      - [Collections](#collections)
  - [Sum types & pattern matching](#sum-types--pattern-matching)
    - [Use cases](#use-cases-1)
      - [Error handling](#error-handling)
      - [AST evaluation](#ast-evaluation)
  - [Algebraic effects](#algebraic-effects)
    - [Use cases](#use-cases-2)
      - [Exceptions](#exceptions)
      - [Asynchronous programming](#asynchronous-programming)

## Tuples

A tuple is just an [anonymous structure] with field names `_0`, `_1`, ..., `_N`. The idea is that you can define it _in-place_, right in a body of a procedure, like this:

[anonymous structure]: https://en.cppreference.com/w/c/language/struct

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

#### Collections

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

### Use cases

#### Error handling
Error handling in C is usually inconsistent, error-prone, and even somewhat cryptic. However, a sum type can represent either a successful or a failure value, and pattern matching can be used to handle an error.

Let's define a wrapper around the [`socket`] syscall to understand the differences:

[`socket`]: https://man7.org/linux/man-pages/man2/socket.2.html


[[`examples/socket_wrapper.c`](https://github.com/Hirrolot/poica/blob/master/examples/socket_wrapper.c)]
```c
SUM(
    SocketErr,
    VARIANT(MkEACCES)
    VARIANT(MkEAFNOSUPPORT)
    VARIANT(MkEINVAL)
    VARIANT(MkEMFILE)
    VARIANT(MkENOBUFS)
    VARIANT(MkENOMEM)
    VARIANT(MkEPROTONOSUPPORT)
    VARIANT(MkOtherErr OF int)
);

SUM(
    SocketRes,
    VARIANT(MkOk OF int)
    VARIANT(MkErr OF SocketErr)
);

SocketRes socket_wrapper(int domain, int type, int protocol) {
    // The body is omitted...
}

int main(void) {
    SocketRes res = socket_wrapper(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    MATCH(&res) {
        CASE(MkOk, fd) {
            printf("fd = %d\n", *fd);
            close(*fd);
        }
        CASE(MkErr, error) {
            puts("An error has occurred!");
            // Handle `error` here...
        }
    }
}
```

Compare the code in `main` to the usual approach with a procedure returning an integral number, some range of which designates a succeses and another range - a failure:

```c
int fd;

if ((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    // -1 is failure! 
} else {
    // [0; ...] is success.
}
```

Sum types have two significant advantages over "magic" numbers:

 - **Readability.** Such identifiers as `MkOk` and `MkErr` are more for humans, not for machines.

 - **Exhaustiveness checking.** A compiler ensures that all the cases of `SocketRes` are handled. However, it's impossible with magic numbers, since they have no actual meaning for a compiler.

#### AST evaluation
Let us have a simple arithmetical language, consisting of:

 - Constants of `double`;
 - Expressions: either `expr1 (+ | - | * | /) expr2` or a constant.

The good news are that sum types can be used to represent the hierarchical structure (an ordered [tree]) of [ASTs], and pattern matching is a technique to evaluate them:

[tree]: https://en.wikipedia.org/wiki/Tree_%28data_structure%29
[ASTs]: https://en.wikipedia.org/wiki/Abstract_syntax_tree

[[`examples/ast_evaluator.c`](https://github.com/Hirrolot/poica/blob/master/examples/ast_evaluator.c)]
```c
#include "../include/obj.h"
#include "../include/sum_type.h"

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

<details>
  <summary>Output</summary>

```
-29.000000
```

</details>

## Algebraic effects

### Use cases

#### Exceptions

#### Asynchronous programming
