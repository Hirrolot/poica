# poica
[![CI](https://github.com/Hirrolot/poica/workflows/C/C++%20CI/badge.svg)](https://github.com/Hirrolot/poica/actions?query=workflow%3A%22C%2FC%2B%2B+CI%22)
[![version](https://img.shields.io/badge/version-0.1.0-orange.svg)](https://github.com/Hirrolot/poica/releases/tag/v0.1.0)
[![docs](https://img.shields.io/badge/docs-wiki/Specification-blue.svg)](https://github.com/Hirrolot/poica/wiki/Specification)

This library provides [algebraic data types], [type introspection], and [pattern matching] for pure C11.

<details>
 <summary>Table of contents</summary>

 - [Features](#features)
 - [Installation](#installation)
 - [Motivation](#motivation)
 - [ADTs](#adts)
   - [Sum types](#sum-types)
   - [Product types](#product-types)
 - [Type introspection](#type-introspection)
   - [Sum types](#sum-types-1)
   - [Product types](#product-types-1)
 - [Real-world usage](#real-world-usage)
   - [Safe, consistent error handling](#safe-consistent-error-handling)
   - [Message passing, tokens, AST, ...](#message-passing-tokens-ast-)
 - [Contributing](#contributing)
 - [Changelog](#changelog)
 - [FAQ](#faq)

</details>

## Features
 - C11-compliant
 - Can work on bare-metal environments
 - Comes with the [specification]
 - No third-party code generators, just `#include <poica.h>` and go!

[specification]: https://github.com/Hirrolot/poica/wiki/Specification

## Installation

```sh
git clone https://github.com/Hirrolot/poica.git
cd poica
```

The only dependency is [Boost/Preprocessor]. If you are on a UNIX-like system, just run the following script:

```
sudo bash scripts/install_boost_pp.sh
```

Alternatively, [Boost/Preprocessor] can be downloaded and then installed from its [official releases](https://github.com/boostorg/preprocessor/releases).

Since poica is a header-only library, feel free to copy necessary files to your project and `#include <poica.h>` to exports its API (using the `-I` compiler option). That's all.

## Motivation

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
SUM(
    OurTaggedUnion,
    VARIANT(MkState1 OF int)
    VARIANT(MkState2 OF const char *)
    VARIANT(MkState3 OF double)
);

// (i) Compilation failed!
OurTaggedUnion res1 = MkState2(123);

OurTaggedUnion res2 = MkState3(.99);
some_procedure(/* Impossible to pass state_1! */);
```

## ADTs

[**ADT**s (**A**lgebraic **D**ata **T**ypes)] provide a convenient approach to combine, destruct, and introspect data types. There are two main kinds of them: **sum types** and **product types**.

Simply put, a **sum type** is _either_ of `T1`, ..., `Tn`, and a **product type** is _both_ `T1`, ..., `Tn`. Another name of sum types is a [tagged union], and product types correspond to structures in C.

[Pattern matching] is checking each variant of a sum type, and, if a matched variant is an actual one, trigger some action. They are like `if` statements, but for sum types, rather than for boolean expressions.

[**ADT**s (**A**lgebraic **D**ata **T**ypes)]: https://en.wikipedia.org/wiki/Algebraic_data_type
[algebraic data types]: https://en.wikipedia.org/wiki/Algebraic_data_type

[tagged union]: https://en.wikipedia.org/wiki/Tagged_union

[Pattern matching]: https://en.wikipedia.org/wiki/Pattern_matching
[pattern matching]: https://en.wikipedia.org/wiki/Pattern_matching

### Sum types

For example, a [binary tree] like this:

[binary tree]: https://en.wikipedia.org/wiki/Binary_tree

<div align="center">
  <img src="https://i.imgur.com/MkefQNV.png" width="380px" />
</div>

Can be conveniently represented as a sum type and further manipulated using pattern matching. In the code below we first construct this binary tree, and then print all its elements to `stdout`:

[[`examples/binary_tree.c`](examples/binary_tree.c)]
```c
#include <poica.h>

#include <stdio.h>

SUM(
    Tree,
    VARIANT(MkEmpty)
    VARIANT(MkLeaf OF int)
    VARIANT(MkNode OF MANY
        FIELD(left OF struct Tree *)
        FIELD(number OF int)
        FIELD(right OF struct Tree *)
    )
);

void print_tree(const Tree *tree) {
    MATCH(tree) {
        CASE(MkEmpty) {
            return;
        }
        CASE(MkLeaf, number) {
            printf("%d\n", *number);
        }
        CASE(MkNode, MANY(left, number, right)) {
            print_tree(*left);
            printf("%d\n", *number);
            print_tree(*right);
        }
    }
}

#define TREE(tree)                OBJ(tree OF Tree)
#define NODE(left, number, right) TREE(MkNode(left, number, right))
#define LEAF(number)              TREE(MkLeaf(number))

int main(void) {
    const Tree *tree =
        NODE(NODE(LEAF(81), 456, NODE(LEAF(90), 7, LEAF(111))), 57, LEAF(123));

    print_tree(tree);
}

#undef TREE
#undef NODE
#undef LEAF
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

### Product types

If we have structures in C, why we need product types? Well, because product types provide some extra features, such as type introspection (discussed in the next section) and fields extraction.

For example, consider [Heron's formula]:

[Heron's formula]: https://en.wikipedia.org/wiki/Heron's_formula

<div align="center">
  <img src="https://i.imgur.com/OuXtE5c.png" width="500px" />
</div>

Which computes area of a triangle, if all three sides are known. This can be accomplished with product types as follows:

[[`examples/heron_formula.c`](examples/heron_formula.c)]
```c
#include <math.h>
#include <stdio.h>

#include <poica.h>

PRODUCT(
    Triangle,
    FIELD(a OF double)
    FIELD(b OF double)
    FIELD(c OF double)
);

double compute_area(Triangle triangle) {
    EXTRACT((a, b, c) FROM (&triangle OF Triangle));

    const double p = (a + b + c) / 2;
    const double area = sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}

int main(void) {
    Triangle triangle = {4, 13, 15};
    printf("%f\n", compute_area(triangle));
}

```

<details>
    <summary>Output</summary>

```
24.000000
```

</details>

`EXTRACT` just creates new variables of the appropriate types and assigns them values from `triangle`. Compare the above code to this version of `compute_area`:

```c
double compute_area(Triangle triangle) {
    const double p = (triangle.a + triangle.b + triangle.c) / 2;
    const double area = sqrt(p * (p - triangle.a) * (p - triangle.b) * (p - triangle.c));

    return area;
}
```

This is how fields extraction can make our code a bit cleaner. In general, fields extraction is preffered when there's a lot of repeating access to fields of a single variable, and it's obvious to what variable the fields correspond.

## Type introspection

[Type introspection] is supported in the sence that you can query the type properties of ADTs at compile-time and then handle them somehow in your hand-written macros.

[Type introspection]: https://en.wikipedia.org/wiki/Introspection_(computer_science)
[type introspection]: https://en.wikipedia.org/wiki/Introspection_(computer_science)

### Sum types

[[`examples/introspection/sum.c`](examples/introspection/sum.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_SUM                                                             \
    Something,                                                             \
    VARIANT(MkA)                                                           \
    VARIANT(MkB OF int)                                                    \
    VARIANT(MkC OF MANY FIELD(c1 OF double) FIELD(c2 OF char))             \

SUM(MY_SUM);
#define Something_INTROSPECT SUM_INTROSPECT(MY_SUM)

int main(void) {
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}

```

<details>
    <summary>Output</summary>

```
((POICA_VARIANT_EMPTY)(MkA))
((POICA_VARIANT_SINGLE)(MkB)(int))
((POICA_VARIANT_MANY)(MkC)( ((c1)(double)) ((c2)(char)) ))
```

</details>

### Product types

[[`examples/introspection/product.c`](examples/introspection/product.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_PRODUCT                                                             \
    Something,                                                                 \
    FIELD(a OF int)                                                            \
    FIELD(b OF const char *)                                                   \
    FIELD(c OF double)                                                         \

PRODUCT(MY_PRODUCT);
#define Something_INTROSPECT PRODUCT_INTROSPECT(MY_PRODUCT)

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

That is, the metainformation about types is actually a [sequence] in the terms of [Boost/Preprocessor]. So the [`BOOST_PP_SEQ_*` macros] can be used further, as well as [other utility macros](https://github.com/Hirrolot/poica/wiki/Specification) from poica.

[sequence]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/data/sequences.html
[Boost/Preprocessor]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/
[`BOOST_PP_SEQ_*` macros]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/headers/seq.html

With type introspection it is possible to achieve [type-driven (de)serialization], [declarative command-line arguments parsing], the [decorator pattern] and more such things.

[type-driven (de)serialization]: https://github.com/serde-rs/json
[declarative command-line arguments parsing]: https://github.com/clap-rs/clap
[decorator pattern]: https://en.wikipedia.org/wiki/Decorator_pattern

### Real-world usage

### Safe, consistent error handling

ADTs provide a safe, consistent approach to error handling. A procedure that can fail returns a sum type, designating either a successful or a failure value, like this:

```c
SUM(
    RecvMsgErrKind,
    VARIANT(MkBadConnection)
    VARIANT(MkNoSuchUser)
    ...
);

SUM(
    RecvMsgRes,
    VARIANT(MkRecvMsgOk OF char *)
    VARIANT(MkSendMsgErr OF RecvMsgErrKind))
);

RecvMsgRes recv_msg(...) { ... }
```

And then `RecvMsgRes` can be matched to decide what to do in the case of `MkRecvMsgOk` and `MkSendMsgErr`:

```c
RecvMsgRes res = recv_msg(...);
MATCH(&res) {
    CASE(MkRecvMsgOk, msg) { ... }
    CASE(MkSendMsgErr, err_kind) { ... }
}
```

But why this is better than `int` error codes? Because of:

 - **Readability.** Such identifiers as `MkRecvMsgOk` and `MkSendMsgErr` are more for humans, and therefore, it's much harder to confuse them with each other. In contrast to this, the usual approach in C to determine an error is by using magic ranges (for example, <0 or -1).

 - **Consistency.** No need to invent different strategies to handle different kinds of errors (i.e. using exceptions for less likely errors, `int` codes for a normal control flow, ...); ADTs address the problem of error handling generally.

 - **Exhaustiveness checking (case analysis).** A smart compiler and static analysis tools ensure that all the variants of `RecvMsgRes` are handled in `MATCH`, so we can't forget to handle an error and make a possibly serious bug by leaving an application work as there's no error, when there is.

ADTs even have advantages over exceptions: they do not perform transformations with a program stack, since they are just values with no implicit logic that can hurt performance.

See [`examples/error_handling.c`](examples/error_handling.c) as an example of error handling using ADTs.


### Message passing, tokens, AST, ...

ADTs have tremendous amount of applications to real-world programming. For example, it's very naturally to [encode tokens](examples/tokens.c) as a sum type, [pass messages](examples/message_passing.c) from one process to another, [evaluate an AST](examples/ast.c).

## Contributing

[wiki/Contributing](https://github.com/Hirrolot/poica/wiki/Contributing)

## Changelog

[wiki/Changelog](https://github.com/Hirrolot/poica/wiki/Changelog)

## FAQ

Q: What "poica" means?

A: "poica" is a [Quenya] word, which means clean, pure. It reflects its API.


[Quenya]: https://www.ambar-eldaron.com/telechargements/quenya-engl-A4.pdf

Q: Are these macros zero-cost?

A: poica has no runtime and performs no system calls, the macros expand to plain C code. Here are the disassembled versions of the examples:

| Example | Link |
|--------|-------|
| `ast.c` | https://godbolt.org/z/BHQEog |
| `binary_tree.c` | https://godbolt.org/z/5XKjVu |
| `heron_formula.c` | https://godbolt.org/z/xaqL_r |
| `tokens.c` | https://godbolt.org/z/pNx4jX |
| `error_handling.c` | https://godbolt.org/z/6Kotvn |

Q: Any pitfalls?

A: The only pitfall I discovered so far is scary macro errors, describing consequences, not causes. However, in user code they can be solved by just carefully looking at line numbers that trigger an error.

Q: Why they are called algebraic?

A: Read ["The algebra (and calculus!) of algebraic data types"](https://codewords.recurse.com/issues/three/algebra-and-calculus-of-algebraic-data-types) by [Joel Burget](https://codewords.recurse.com/about#Joel%20Burget).

Q: Is it allowed to use Boost/Preprocessor in C?

A: Yes.
