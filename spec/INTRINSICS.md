## EBNF Grammar

```ebnf

(* Sum types introspection *)

<sum-introspect>            = "POICA_CHOICE_INTROSPECT(" identifier "," { variant }+ ")" ;

<variant-kind>              = "POICA_VARIANT_KIND(" variant ")" ;
<variant-name>              = "POICA_VARIANT_NAME(" variant ")" ;

<overload-on-variant>       = "POICA_OVERLOAD_ON_VARIANT(" identifier "," aux-data "," variant ")" ;

(* Product types introspection *)

<product-introspect>        = "POICA_RECORD_INTROSPECT(" identifier "," { field }+ ")" ;

<field-type>                = "POICA_FIELD_TYPE(" field ")" ;
<product-field-types-seq>   = "POICA_RECORD_FIELD_TYPES_SEQ(" { field }+ ")" ;
<product-field-types-tuple> = "POICA_RECORD_FIELD_TYPES_TUPLE(" { field }+ ")" ;

<field-name>                = "POICA_FIELD_NAME(" field ")" ;
<product-field-names-seq>   = "POICA_RECORD_FIELD_NAMES_SEQ(" { field }+ ")" ;
<product-field-names-tuple> = "POICA_RECORD_FIELD_NAMES_TUPLE(" { field }+ ")" ;
```

## Semantics

### `POICA_CHOICE_INTROSPECT`

Expands to:

```
<variant1>
...
<variantN>
```

And `<variant1>`, ..., `<variantN>` will then expand according to the [rules that variants expand](#variant-variantmany).

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
