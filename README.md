> WARNING: this is just my experiment I work on in my free time. Do **NOT** rely on it.

# poica
[![CI](https://github.com/Hirrolot/poica/workflows/C/C++%20CI/badge.svg)](https://github.com/Hirrolot/poica/actions?query=workflow%3A%22C%2FC%2B%2B+CI%22)
[![version](https://img.shields.io/badge/version-0.5.0-orange.svg)](https://github.com/Hirrolot/poica/releases/tag/v0.5.0)

The goal of this project is to implement the features of powerful type systems in plain C11 via its macro system, thereby improving static reasoning and achieving a better way to organise our code.

## Table of contents
 - [Installation](#installation)
 - [Algebraic data types](#algebraic-data-types)
   - [Sum types](#sum-types)
   - [Product types](#product-types)
 - [Type introspection](#type-introspection)
   - [Sum types](#sum-types-1)
   - [Product types](#product-types-1)
 - [Safe, consistent error handling](#safe-consistent-error-handling)
 - [Built-in ADTs](#built-in-adts)
 - [OOP](#oop)
   - [Interfaces](#interfaces)
   - [Dynamic dispatch](#dynamic-dispatch)
 - [Type-generic programming](#type-generic-programming)
   - [Generic types](#generic-types)
   - [Higher-kinded types](#higher-kinded-types)
   - [Generalised algebraic data types](#generalised-algebraic-data-types)
   - [Type-safe higher-order abstract syntax](#type-safe-higher-order-abstract-syntax)
 - [Options](#options)
 - [Roadmap](#roadmap)
 - [FAQ](#faq)

## Installation

The recommended way is using [Git submodules]. Enter your project and execute:

```sh
git submodule add -b master https://github.com/Hirrolot/poica
git submodule update --init --recursive
```

If you use [CMake], you can then connect poica as follows:

```cmake
include_directories(poica/include poica/preprocessor/include poica/vmd/include)
```

And `#include <poica.h>` inside your source files to export its public API. Building isn't required, because poica is a header-only library.

If you use GCC, `-ftrack-macro-expansion=0` would reduce compilation time and memory consumption.

[Git submodules]: https://git-scm.com/book/en/v2/Git-Tools-Submodules
[CMake]: https://cmake.org/

## Algebraic data types

Usually in C we use unions to tell a compiler that we're going to interpret a single memory region in different ways. To decide how to interpret a union, we endow it with a tag and get a [tagged union].

However, there'll be quite lot of duplication in code:

```c
typedef struct {
    enum {
        OUR_TAGGED_UNION_STATE_1,
        OUR_TAGGED_UNION_STATE_2,
        OUR_TAGGED_UNION_STATE_3,
    } state;

    union {
        int state_1;
        const char *state_2;
        double state_3;
    } data;
} OurTaggedUnion;
```

What's even worse is that this approach is unsafe, meaning that we can construct invalid `OurTaggedUnion` (i), or, for example, (ii) access `data.state_1` when the actual state is `OUR_TAGGED_UNION_STATE_3`:

```c
// (i)
OurTaggedUnion res1 = { .state = OUR_TAGGED_UNION_STATE_2, .data.state_1 = 123 };

// (ii)
OurTaggedUnion res2 = { .state = OUR_TAGGED_UNION_STATE_3, .data.state_3 = .99 };
some_procedure(res2.data.state_1);
```

poica solves these two problems by introducing [algebraic data types] (discussed in the next section). That's how it's accomplished with poica:

```c
choice(
    OurTaggedUnion,
    variant(State1, int)
    variant(State2, const char *)
    variant(State3, double)
);

// (i) Compilation failed!
OurTaggedUnion res1 = State2(123);

OurTaggedUnion res2 = State3(.99);
some_procedure(/* Impossible to pass state_1! */);
```

[tagged union]: https://en.wikipedia.org/wiki/Tagged_union

### Sum types

For example, a [binary tree] like this:

<div align="center">
  <img src="images/BINARY_TREE.png" width="380px" />
</div>

Can be conveniently represented as a sum type and further manipulated using pattern matching. In the code below we first construct this binary tree, and then print all its elements to `stdout`:

[[`examples/binary_tree.c`](examples/binary_tree.c)]
```c
#include <poica.h>

#include <stdio.h>

choice(
    Tree,
    variant(Empty)
    variant(Leaf, int)
    variantMany(Node,
        field(left, struct Tree *)
        field(number, int)
        field(right, struct Tree *)
    )
);

void print_tree(const Tree *tree) {
    match(*tree) {
        of(Empty) {
            return;
        }
        of(Leaf, number) {
            printf("%d\n", *number);
        }
        ofMany(Node, (left, number, right)) {
            print_tree(*left);
            printf("%d\n", *number);
            print_tree(*right);
        }
    }
}

#define TREE(tree)                obj(tree, Tree)
#define NODE(left, number, right) TREE(Node(left, number, right))
#define LEAF(number)              TREE(Leaf(number))

int main(void) {
    const Tree *tree = NODE(NODE(LEAF(81), 456, NODE(LEAF(90), 7, LEAF(111))), 57, LEAF(123));

    print_tree(tree);
}
```

<details>
    <summary>Output</summary>

```
81
456
90
7
111
57
123
```

</details>

[binary tree]: https://en.wikipedia.org/wiki/Binary_tree

### Product types

If we have structures in C, why do we need product types? Well, because product types provide type introspection (discussed in the next section). A product type is represented like this:

```c
record(
    UserAccount,
    field(name, const char *)
    field(balance, double)
    field(age, unsigned char)
);
```

And it can be further manipulated like an ordinary structure:

```c
UserAccount user = {"Gandalf", 14565.322, 715};
user.name = "Mithrandir";
user.age++;
user.balance *= 2;
```

## Type introspection

[Type introspection] is supported in the sense that you can query the type properties of ADTs at compile-time and then handle them somehow in your hand-written macros.

[Type introspection]: https://en.wikipedia.org/wiki/Introspection_(computer_science)

### Sum types

[[`examples/introspection/choice.c`](examples/introspection/choice.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_CHOICE                                                           \
    Something,                                                              \
    variant(A)                                                              \
    variant(B, int)                                                         \
    variantMany(C, field(c1, double) field(c2, char))

choice(MY_CHOICE);
#define Something_INTROSPECT POICA_CHOICE_INTROSPECT(MY_CHOICE)

int main(void) {
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}
```

<details>
    <summary>Output</summary>

```
((POICA_VARIANT_KIND_EMPTY)(A))
((POICA_VARIANT_KIND_SINGLE)(B)(int))
((POICA_VARIANT_KIND_MANY)(C)( ((c1)(double)) ((c2)(char)) ))
```

</details>

### Product types

[[`examples/introspection/record.c`](examples/introspection/record.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_RECORD                                                           \
    Something,                                                              \
    field(a, int)                                                           \
    field(b, const char *)                                                  \
    field(c, double)

record(MY_RECORD);
#define Something_INTROSPECT POICA_RECORD_INTROSPECT(MY_RECORD)

int main(void) {
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}
```

<details>
    <summary>Output</summary>

```
((a)(int)) ((b)(const char *)) ((c)(double))
```

</details>

Metainformation about types is actually a [sequence] in the terms of [Boost/Preprocessor]. So the `BOOST_PP_SEQ_*` macros can be used further, as well as [Boost/VMD] and the [intrinsics](https://github.com/Hirrolot/poica/blob/master/spec/INTRINSICS.md) from poica.

[sequence]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/data/sequences.html
[Boost/Preprocessor]: http://boost.org/libs/preprocessor
[Boost/VMD]: http://boost.org/libs/vmd

## Safe, consistent error handling

ADTs provide a safe, consistent approach to error handling. A procedure that can fail returns a sum type, designating either a successful or a failure value, like this:

```c
typedef enum RecvMsgErrKind {
    BAD_CONN,
    NO_SUCH_USER,
    ...
} RecvMsgErrKind;

typedef const char *Msg;

DefRes(Msg, RecvMsgErrKind);

P(Res, Msg, RecvMsgErrKind) recv_msg(...) { ... }
```

And then `P(Res, Msg, RecvMsgErrKind)` can be matched to decide what to do in the case of `P(Ok, Msg, RecvMsgErrKind)` and `P(Err, Msg, RecvMsgErrKind)`:

```c
P(Res, Msg, RecvMsgErrKind) res = recv_msg(...);
match(res) {
    of(P(Ok, Msg, RecvMsgErrKind), msg) { ... }
    of(P(Err, Msg, RecvMsgErrKind), err_kind) { ... }
}
```

But why this is better than `int` error codes? Because of:

 - **Readability.** Such identifiers as `Ok` and `Err` are more for humans, and therefore, it's much harder to confuse them with each other. In contrast to this, the usual approach in C to determine an error is by using magic ranges (for example, <0 or -1).

 - **Consistency.** No need to invent different strategies to handle different kinds of errors (i.e. using exceptions for less likely errors, `int` codes for a normal control flow, ...); ADTs address the problem of error handling generally.

 - **Exhaustiveness checking (case analysis).** A smart compiler and static analysis tools ensure that all the variants of `Res` are handled in `match`, so we can't forget to handle an error and make a possibly serious bug by leaving an application work as there's no error, when there is.

ADTs even have advantages over exceptions: they do not perform transformations with a program stack, since they are just values with no implicit logic that can hurt performance.

See [`examples/error_handling.c`](examples/error_handling.c) as an example of error handling using ADTs.

## Built-in ADTs

| ADT | Description | Example |
|-----|-------------|---------|
| `Maybe` | An optional value | [`examples/maybe.c`](examples/maybe.c) |
| `Either` | Either this value or that | [`examples/either.c`](examples/either.c) |
| `Pair` | A pair of elements | [`examples/pair.c`](examples/pair.c) |
| `Res` | Either a successful or a failure value | [`examples/error_handling.c`](examples/error_handling.c) |

The last one has been presented in the previous section. All these generic types share the common API:

```c
// Generate a definition of an ADT.
DefX(T1, ..., Tn);

// Generate a type name.
P(X, T1, ..., Tn) = ...;
```

The utility functions can be found in the [specification](spec/STD.md).

## OOP

### Interfaces

[[`examples/interfaces.c`](examples/interfaces.c)]
```c
#include <poica.h>

#include <math.h>
#include <stdio.h>

interface(
    Shape,
    double (*area)(const void *self);
);

record(
    Square,
    field(width, double)
    field(height, double)
);

record(
    Triangle,
    field(a, double)
    field(b, double)
    field(c, double)
);

impl(
    (Shape) for (Square),
    (double)(area)(const void *self)(
        const Square *square = (const Square *)self;
        return square->width * square->height;
    )
);

impl(
    (Shape) for (Triangle),
    (double)(area)(const void *self)(
        const Triangle *triangle = (const Triangle *)self;
        double a = triangle->a, b = triangle->b, c = triangle->c;

        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    )
);

int main(void) {
    const Square square = { .width = 6, .height = 3.4 };
    const Triangle triangle = { .a = 4, .b = 13, .c = 15};

    printf("%f\n", iMethods(Shape, Square).area(&square));
    printf("%f\n", iMethods(Shape, Triangle).area(&triangle));
}
```

<details>
    <summary>Output</summary>

```
20.400000
24.000000
```

</details>

### Dynamic dispatch

[[`examples/dyn_dispatch.c`](examples/dyn_dispatch.c)]
```c
#include <poica.h>

#include <stdio.h>

interface(
    Animal,
    void (*noise)(void *self);
);

record(Dog, field(counter, int));
record(Cat, field(counter, int));

impl(
    (Animal) for (Dog),
    (void)(noise)(void *self)(
        Dog *dog = (Dog *)self;
        dog->counter++;
        printf("Woof! Counter: %d\n", dog->counter);
    )
);

impl(
    (Animal) for (Cat),
    (void)(noise)(void *self)(
        Cat *cat = (Cat *)self;
        cat->counter++;
        printf("Meow! Counter: %d\n", cat->counter);
    )
);

int main(void) {
    Dog dog = {.counter = 0};
    Cat cat = {.counter = 0};

    AnimalMut animal;

    animal = P(newIObj, AnimalMut, Dog)(&dog);

    vCall(animal, noise);
    vCall(animal, noise);
    vCall(animal, noise);

    animal = P(newIObj, AnimalMut, Cat)(&cat);

    vCall(animal, noise);
    vCall(animal, noise);
}
```

<details>
    <summary>Output</summary>

```
Woof! Counter: 1
Woof! Counter: 2
Woof! Counter: 3
Meow! Counter: 1
Meow! Counter: 2
```

</details>

[object-oriented programming]: https://en.wikipedia.org/wiki/Object-oriented_programming
[Dynamic dispatch]: https://en.wikipedia.org/wiki/Dynamic_dispatch
[virtual method table (VTable)]: https://en.wikipedia.org/wiki/Virtual_method_table

## Type-generic programming

This problem is often addressed via `void *` in C. However, it has two big disadvantages:

 - A compiler is unable to perform type-specific optimisations;
 - `void *` types could be confused with each other;
 - Not self-documenting.

poica uses a technique called _monomorphisation_, which means that it'll instantiate your generic types with concrete substitutions after preprocessing, eliminating all the disadvantages of `void *`.

### Generic types

Below is a trivial implementation of a generic [linked list]:

[linked list]: https://en.wikipedia.org/wiki/Linked_list

[[`examples/generic_linked_list.c`](examples/generic_linked_list.c)]
```c
#include <poica.h>

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define DeclLinkedList(type)                                                   \
    typedef struct P(LinkedList, type) {                                       \
        type *data;                                                            \
        struct P(LinkedList, type) * next;                                     \
    } P(LinkedList, type);                                                     \
                                                                               \
    static P(LinkedList, type) * P(listNew, type)(type item);                  \
    static void P(listFree, type)(P(LinkedList, type) * list);                 \
                                                                               \
    POICA_FORCE_SEMICOLON

#define DefLinkedList(type)                                                    \
    static P(LinkedList, type) * P(listNew, type)(type item) {                 \
        P(LinkedList, type) *list = malloc(sizeof(*list));                     \
        assert(list);                                                          \
                                                                               \
        list->data = malloc(sizeof(type));                                     \
        assert(list->data);                                                    \
        memcpy(list->data, &item, sizeof(type));                               \
        list->next = NULL;                                                     \
                                                                               \
        return list;                                                           \
    }                                                                          \
                                                                               \
    static void P(listFree, type)(P(LinkedList, type) * list) {                \
        P(LinkedList, type) *node = list;                                      \
                                                                               \
        do {                                                                   \
            free(node->data);                                                  \
            P(LinkedList, type) *next_node = node->next;                       \
            free(node);                                                        \
            node = next_node;                                                  \
        } while (node);                                                        \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

DeclLinkedList(int);
DefLinkedList(int);

int main(void) {
    P(LinkedList, int) *list = P(listNew, int)(123);
    list->next = P(listNew, int)(456);
    list->next->next = P(listNew, int)(789);

    P(listFree, int)(list);
}
```

There's nothing much to say, except that `P` (which stands for _polymorphic_) expands to a unique function or type identifier, e.g. performs type substitution.

### Higher-kinded types

TODO

### Generalised algebraic data types

TODO

### Type-safe higher-order abstract syntax

TODO

## Options

There are several options, implemented via macro definitions (turned off by default):

 - `POICA_USE_PREFIX` -- removes all the public unprefixed `camelCase`ed and `PascalCase`ed identifiers (`match`, `DefRes`, ...) from the current translation unit. The prefixed versions (`poicaMatch`, `PoicaDefRes`, ...) are defined unconditionally.
 - `POICA_ENABLE_ASSERTIONS` -- enables some consistency checks on input data to macros. Can increase compilation time!

## Roadmap

 - Higher-order abstract syntax
 - Allow specifying attributes on ADTs and their items (probably a breaking change).
 - Add several libraries of wrappers for common libraries (see [issue #1](https://github.com/Hirrolot/poica/issues/1)).
 - Add a library for type-driven JSON (de)serialization (see [serde-json]).
 - Add a library for type-driven command-line argument parsing (see [clap]).

[serde-json]: https://github.com/serde-rs/json
[clap]: https://github.com/clap-rs/clap

## FAQ

Q: What "poica" means?

A: "poica" is a [Quenya] word, which means clean, pure. It reflects its API.

[Quenya]: https://www.ambar-eldaron.com/telechargements/quenya-engl-A4.pdf
