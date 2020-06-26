## EBNF grammar

```ebnf
(* Sum types *)

sum-type                  = "choice(" identifier "," { variant }+ ");" ;
variant                   = "variant(" identifier ")"
                          | "variant(" identifier "," type ")"
                          | "variantMany(" identifier "," { field }+ ")" ;

variant-tag               = "variantTag(" expr ")" ;

match                     = "match(" expr ")" "{" { of compound-statement }+ "}" [ otherwise ] ;
matches                   = "matches(" expr "," identifier ")" ;

try                       = "try(" expr "," case-variant-name "," return-variant-name ");" ;

of                        = "of(" identifier ")"
                          | "of(" identifier "," identifier ")"
                          | "ofMany(" identifier ", (" { identifier }+  "))" ;
of-mut                    = "ofMut(" identifier ")"
                          | "ofMut(" identifier "," identifier ")"
                          | "ofManyMut(" identifier ", (" { identifier }+  "))" ;

otherwise                 = "otherwise" compound-statement ;

(* Product types *)

product-type              = "record(" identifier "," { field }+ ");" ;
field                     = "field(" identifier "," type ")" ;

(* Sum types introspection *)

sum-introspect            = "POICA_CHOICE_INTROSPECT(" identifier "," { variant }+ ")" ;

variant-kind              = "POICA_VARIANT_KIND(" variant ")" ;
variant-name              = "POICA_VARIANT_NAME(" variant ")" ;

overload-on-variant       = "POICA_OVERLOAD_ON_VARIANT(" identifier "," aux-data "," variant ")" ;

(* Product types introspection *)

product-introspect        = "POICA_RECORD_INTROSPECT(" identifier "," { field }+ ")" ;

field-type                = "POICA_FIELD_TYPE(" field ")" ;
product-field-types-seq   = "POICA_RECORD_FIELD_TYPES_SEQ(" { field }+ ")" ;
product-field-types-tuple = "POICA_RECORD_FIELD_TYPES_TUPLE(" { field }+ ")" ;

field-name                = "POICA_FIELD_NAME(" field ")" ;
product-field-names-seq   = "POICA_RECORD_FIELD_NAMES_SEQ(" { field }+ ")" ;
product-field-names-tuple = "POICA_RECORD_FIELD_NAMES_TUPLE(" { field }+ ")" ;

(* Built-in ADTs *)

def-maybe-type            = "DefMaybe(" type ");" ;
maybe-type                = "Maybe(" type ")" ;

def-either-type            = "DefEither(" left-type "," right-type ");" ;
either-type                = "Either(" left-type "," right-type  ")" ;

def-pair-type            = "DefPair(" fst-type "," snd-type ");" ;
pair-type                = "Pair(" fst-type "," snd-type  ")" ;

def-res-type            = "DefRes(" ok-type "," err-type ");" ;
res-type                = "Res(" ok-type "," err-type  ")" ;

(* Miscellaneous *)

obj                       = "obj(" value "," value-type ")" ;

unit-type                 = "Unit" ;
unit-value                = "unit" ;
```

## Semantics

### `choice`

Expands to:

```c
typedef struct <sum-name> {
    // Omitted...
} <sum-name>;

<value-constructors>
```

`<value constructors>` are pure functions that construct variants of `<sum-name>`. Their signatures depend on a kind of a variant:

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

### `variant`, `variantMany`

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

### `variantTag`

Expands to the value of an anonymous [plain C enumeration], designating a unique (among the variants of the sum type of `<expr>`) tag in `<expr>`.

This macro can be used to compare two variants, ignoring the inner data (see [`examples/compare_variants.c`](https://github.com/Hirrolot/poica/blob/master/examples/compare_variants.c)).

[plain C enumeration]: https://en.cppreference.com/w/c/language/enum

### `match`

Tests `<expr>` of a sum type for all variants of `<sum-type>`, one after another, starting from the first. If correspondence is found, executes `<compound-statement>` specified after the corresponding [`of`](#of), and then goes to the first statement after `match`.

If not all the variants are specified in `match`, a compiler should generate a warning. This is called _exhaustiveness checking_ (or _case analysis_).

### `matches`

Tests whether `<expr>` of a sum type corresponds to `<variant-type>`. Expands to a boolean expression.

### `try`

Expands to:

```c
match(<expr>) {
    of(<case-variant-name>, val) {
        return <return-variant-name>(*val);
    }
    otherwise {}
}
```

This macro is used to concisely pass an error upwards a program stack, or, if the result is successful, do nothing.

### `of`, `ofMany`

There are again several forms of this macro, each corresponds to a kind of a variant:

 - For `variant(<variant-name>)` use `of(<variant-name>)`.

 - For `variant(<variant-name>, <type>)` use `of(<variant-name>, <var>)`. `<var>` is of type `const <type> *` and is accessible in `<compound-statement>`.

 - For `variantMany(<variant-name>, field(<f1>, <F1>) ... field(<fm>, <Fm>))` use `ofMany(<variant-name>, (<f1>, ..., <fm>))`. `<f1>`, ..., `<fm>` are of types `const F1 *`, ..., `const Fm *`, respectively, and are accessible in `<compound-statement>`.

There exist mutable versions - `ofMut` and `ofManyMut`. The difference is that the mutable versions provide `T *` instead of `const T *` to `<compound-statement>`s.

### `otherwise`

Handles the rest of variants of a sum type, if the previous ones have been failed. [`match`](#match) with `otherwise` is by definition handles all variants, so exhaustiveness checking will succeed.

### `record`

Expands to:

```c
typedef struct <product-type> {
    <F1> <f1>;
    ///
    <Fm> <fm>;
} <product-type>;
```

### `field`

Expands to:

```
((<f1>)(<Fm>))
```

### `POICA_CHOICE_INTROSPECT`

Expands to:

```
<variant1>
...
<variantN>
```

And `<variant1>`, ..., `<variantN>` will then expand according to the [rules that variants expand](#variant).

### `POICA_VARIAND_KIND`, `POICA_VARIANT_NAME`

`POICA_VARIANT_KIND` expands to either `POICA_VARIANT_KIND_EMPTY`, `POICA_VARIANT_KIND_SINGLE`, or `POICA_VARIANT_KIND_MANY`, depending on a kind of a passed variant (see [the expansion rules of `variant`](#variant)).

`POICA_VARIANT_NAME` expands to the name of a variant.

### `POICA_OVERLOAD_ON_VARIANT`

The order of parameters:

 1) `<macro-name>` is a prefix of three user-provided macros.
 2) Any auxiliary data.
 3) A [variant](#variant), depending on which, `POICA_OVERLOAD_ON_VARIANT` expands to invocations of different user-provided macros

```
variant(<variant-name>)
--->
<macro-name>VARIANT_KIND_EMPTY(aux-data, <variant-name>)
```

```
variant(<variant-name>, <type>)
--->
<macro-name>VARIANT_KIND_SINGLE(aux-data, <variant-name>, <type>)
```

```
variantMany(<variant-name>, field(<f1>, <F1>) ... field(<fm>, <Fm>))
--->
<macro-name>VARIANT_KIND_MANY(aux-data, <variant-name>, field(<f1>, <F1>) ... field(<fm>, <Fm>))
```

### `POICA_RECORD_INTROSPECT`

Expands to:

```
<field1>
...
<fieldN>
```

And `<field1>`, ..., `<fieldN>` will then expand according to the [rules that fields expand](#field);

### `POICA_FIELD_TYPE`, `POICA_FIELD_NAME`

`POICA_FIELD_TYPE` expands to the type of a passed field, and `POICA_FIELD_NAME` expands to a name of a passed field.

### `POICA_RECORD_FIELD_TYPES_SEQ`, `POICA_RECORD_FIELD_TYPES_TUPLE`

`POICA_RECORD_FIELD_TYPES_SEQ` expands to:

```
(<F1>) ... (<Fm>)
```

`POICA_RECORD_FIELD_TYPES_TUPLE` expands to:

```
(<F1>, ..., <Fm>)
```

### `POICA_RECORD_FIELD_NAMES_SEQ`, `POICA_RECORD_FIELD_NAMES_TUPLE`

`POICA_RECORD_FIELD_NAMES_SEQ` expands to:

```
(<f1>) ... (<fm>)
```

`POICA_RECORD_FIELD_NAMES_TUPLE` expands to:

```
(<f1>, ..., <fm>)
```

### `obj`
Expands to a pointer to an [unnamed object] (`value-type *`) that is equal to `value`. `obj` is used to imitate recursive data structures, like trees.

[unnamed object]: https://en.cppreference.com/w/c/language/compound_literal

## Cautions

Make sure that expressions of a sum type, passed to macros, produce no side effects and/or performs heavy computations. You'd better first place `<expr>` into a variable, and then pass this variable into `match` and other similar macros:

```c
MySumType var = <expr>;
match(var) { ... }
```

Do **NOT** do this:

```c
match(<cpu-bound-or-io-expr>) { ... }
```
