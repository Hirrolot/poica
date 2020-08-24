This document describes the core language features. The formal grammar is specified via [EBNF], the semantics is given informally.

[EBNF]: https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_Form

## Sum types

```ebnf
<sum-type>                  = "choice(" identifier "," { variant }+ ");" ;
<variant>                   = "variant(" identifier ")"
                            | "variant(" identifier "," type ")"
                            | "variantMany(" identifier "," { field }+ ")" ;

<variant-tag>               = "variantTag(" expr ")" ;

<match>                     = "match(" expr ")" "{" { of compound-statement }+ "}" [ otherwise ] ;
<matches>                   = "matches(" expr "," identifier ")" ;

<of>                        = "of(" identifier ")"
                            | "of(" identifier "," identifier ")"
                            | "ofMany(" identifier ", (" { identifier }+  "))" ;
<of-mut>                    = "ofMut(" identifier ")"
                            | "ofMut(" identifier "," identifier ")"
                            | "ofManyMut(" identifier ", (" { identifier }+  "))" ;

<otherwise>                 = "otherwise" compound-statement ;
```

### `<sum-type>`

Expands to:

```c
typedef struct <sum-name> {
    // Omitted...
} <sum-name>;

<value-constructors>
```

`<value-constructors>` are pure functions that construct variants of `<sum-name>`. Their signatures depend on a kind of a variant:

```
variant(<variant-name>)
--->
inline static <sum-name> <variant-name>(void) { ... }
```

```
variant(<variant-name>, <type>)
--->
inline static <sum-name> <variant-name>(<type>) { ... }
```

```
variantMany(<variant-name>, field(<f1>, <F1>) ... field(<fm>, <Fm>))
--->
inline static <sum-name> <variant-name>(F1, ..., Fm) { ... }
```

### `<variant>`

Expands to:

```
variant(<variant-name>)
--->
((POICA_VARIANT_KIND_EMPTY)(<variant-name>))
```

```
variant(<variant-name>, <type>)
--->
((POICA_VARIANT_KIND_SINGLE)(<variant-name>)(<type>))
```

```
variantMany(<variant-name>, field(<f1>, <F1>) ... field(<fm>, <Fm>))
--->
((POICA_VARIANT_KIND_MANY)(<variant-name>)( ((<f1>)(<F1>)) ... ((<fm>)(<Fm>)) ))
```

### `<variant-tag>`

Expands to the value of an anonymous [plain C enumeration], designating a unique (among the variants of the sum type of `<expr>`) tag in `<expr>`.

This macro can be used to compare two variants, ignoring the inner data (see [`examples/compare_variants.c`](https://github.com/Hirrolot/poica/blob/master/examples/compare_variants.c)).

[plain C enumeration]: https://en.cppreference.com/w/c/language/enum

### `<match>`

Tests `<expr>` of a sum type for all variants of `<sum-type>`, one after another, starting from the first. If correspondence is found, executes `<compound-statement>` specified after the corresponding [`of`](#of), and then goes to the first statement after `match`.

If not all the variants are specified in `match`, a compiler should generate a warning. This is called _exhaustiveness checking_ (or _case analysis_).

### `<matches>`

Tests whether `<expr>` of a sum type corresponds to `<variant-type>`. Expands to a boolean expression.

### `<of>`, `<of-mut>`

There are again several forms of this macro, each corresponds to a kind of a variant:

 - For `variant(<variant-name>)` use `of(<variant-name>)`.

 - For `variant(<variant-name>, <type>)` use `of(<variant-name>, <var>)`. `<var>` is of type `const <type> *` and is accessible in `<compound-statement>`.

 - For `variantMany(<variant-name>, field(<f1>, <F1>) ... field(<fm>, <Fm>))` use `ofMany(<variant-name>, (<f1>, ..., <fm>))`. `<f1>`, ..., `<fm>` are of types `const F1 *`, ..., `const Fm *`, respectively, and are accessible in `<compound-statement>`.

There exist mutable versions - `ofMut` and `ofManyMut`. The difference is that the mutable versions provide `T *` instead of `const T *` to `<compound-statement>`s.

### `<otherwise>`

Handles the rest of variants of a sum type, if the previous ones have been failed. [`match`](#match) with `otherwise` is by definition handles all variants, so exhaustiveness checking will succeed.

## Product types

```ebnf
<product-type>              = "record(" identifier "," { field }+ ");"
                            | "record(" identifier ");" ;
<field>                     = "field(" identifier "," type ")" ;
```

### `<product-type>`

The first alternative expands to:

```c
typedef struct <product-type> {
    <F1> <f1>;
    ///
    <Fm> <fm>;
} <product-type>;
```

The second is used to define an empty structure, which can be used, for instance, only to implement certain interfaces. It expands to:

```c
typedef struct <product-type> {
    Unit _;
} <product-type>;
```

### `<field>`

Expands to:

```
((<f1>)(<Fm>))
```

## Interfaces

```ebnf
<interface>                 = "interface(" identifier "," { fn-ptr }+ ");" ;
<interface-methods>         = "iMethods(" identifier "," identifier ")" ;

<impl>                      = "impl(" identifier "," identifier ");"
                            | "impl(" identifier "," identifier { "," impl-method }+ ");"
                            | "staticImpl(" identifier "," identifier { "," impl-method }+ ");" ;

<impl-method>               = "(" return-type ")" "(" identifier ")" "(" { param }* ")" "(" code ")" ;

<virtual-call>              = "vCall(" expr "," identifier { "," expr }*  ")" ;
<interface-method-ptr>      = "iMethodPtr(" expr "," identifier ")" ;
```

### `<interface>`

Defines an interface. The first parameter is a name of an interface, the second one is pointers to functions in the following form:

```
<return-type> (*<method-name>)(<params>);
...
```

Two type names are introduced: `<interface-name>` and `<interface-name>Mut`, holding a virtual table and a pointer to a immutable implementation & mutable implementation, respectively. Variables of these types are called __interface objects__.

### `<interface-methods>`

Expands to something accessible by the dot operator to call interface's methods, e.g.: `iMethods(MyInterface, MyImplementerType).myMethod(...)`. `myMethod` has exactly the same type as specified in `interface`.

### `<impl>`

The first alternative of `impl` declares the implementation, the second one defines. The definition makes the implementation visible till the end of a TU, since it's also a declaration. A declaration can be used to make an implementation visible from another TU, within which it has been defined.

`staticImpl` defines an implementation only for the current TU and does not have a declaration form.

All forms of `impl` and `staticImpl` generate a generic function `newIObj` of two types: an interface and its implementer. `newIObj` accepts a pointer of an implementer type.

### `<virtual-call>`

Calls a virtual method on an interface object.

### `<interface-method-ptr>`

`iMethodPtr(<interface-obj>, <method-name>)` expands to a function pointer of the provided method name within an interface object. The resulting pointer must have exactly the same type as specified in `interface`.

## Miscellaneous

```ebnf
<obj>                       = "obj(" value "," value-type ")" ;

<unit-type>                 = "Unit" ;
<unit-value>                = "unit" ;

<monomorphise>              = "P(" ( identifier | identifier { "," identifier }+ ) ")" ;
<force-semicolon>           = "POICA_FORCE_SEMICOLON"
```

### `<obj>`

Expands to a pointer to an [unnamed object] (`value-type *`) that is equal to `value`. `obj` is used to imitate recursive data structures, like trees.

[unnamed object]: https://en.cppreference.com/w/c/language/compound_literal

### `<unit-type>`, `<unit-value>`

`Unit` is a [unit type], i.e. a type that allows the only one value, `unit`, which is defined as follows:

```c
static const Unit unit;
```

[unit type]: https://en.wikipedia.org/wiki/Unit_type

### `<monomorphise>`

Concatenates all the provided identifiers, thereby producing a name of a monomorphised software entity. Example:

```
P(a, b, c) ==> abc
```

Note that even if we provide different types, this macro may produce the same identifier: `P(a, aa)` is the same as `P(aa, a)`. However, this behavior occurs almost never, and a compiler must generate a compilation error.

Another edge-case is that `P` doesn't handle special characters and whitespaces, for example, `int *`, `int (*fnPtr)(int, int)` and so on. Instead you can use `typedef`s:

```c
typedef int (*fnPtr)(int, int);
P(fnPtr, abc) ==> fnPtrabc
```

### `<force-semicolon>`

`POICA_FORCE_SEMICOLON` forces a user to put a semicolon after itself. One of its use cases is a semicolon after a data type definition:

```c
DefMyDataType(...);
```

See [`examples/generic_linked_list.c`](https://github.com/Hirrolot/poica/blob/master/examples/generic_linked_list.c) as an example.

## Cautions

 - Make sure that expressions of a sum type, passed to macros, produce no side effects and/or performs heavy computations. You'd better first place `<expr>` into a variable, and then pass this variable into `match` and other similar macros:

```c
MySumType var = <expr>;
match(var) { ... }
```

Do **NOT** do this:

```c
match(<cpu-bound-or-io-expr>) { ... }
```

 - All the generic types inherit the edge-cases of [`P`](#p).
