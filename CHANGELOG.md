# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.6.0] - unreleased

Now poica is rather a general-purpose programming language.

### Added
 - Interfaces: `interface`, `iMethods`, `impl`, `staticImpl`, `vCall`, `iMethodPtr`.
 - The second form of `record`: `record(MyRecord);`.
 - Check macro parameters for consistency (might result in false negatives) via the `POICA_ENABLE_ASSERTIONS` compile-time option.
 - Assertions: `POICA_ASSERT_ARE_FIELDS`, `POICA_ASSERT_IS_FIELD`, `POICA_ASSERT_ARE_VARIANTS`, `POICA_ASSERT_IS_VARIANT`.
 - `examples/interfaces.c`.

### Removed
 - `examples/message_passing.c`, because I don't want to depend on third-party libraries in the examples.
 - `examples/swap_registers.c`.

### Fixed
 - Introspection macros: `POICA_VARIANT_KIND`, `POICA_VARIANT_NAME`, `POICA_OVERLOAD_ON_VARIANT`, `POICA_FIELD_TYPE`, `POICA_FIELD_NAME`.

### Changed
 - Split the sources into the standard library and the language core.
 - The prefixed `camelCase`ed and `PascalCase`ed public macros are now defined unconditionally.

## [0.5.0] - 2020-07-18

Now poica is for [type-driven development], not only for ADTs & type instrospection.

[type-driven development]: https://blog.ploeh.dk/2015/08/10/type-driven-development/

### Added
 - `P` (a macro for polymorphism)
 - `POICA_FORCE_SEMICOLON`
 - `examples/hkt.c`, `examples/int_bool_ast.c`, `examples/dyn_dispatch.c`, `examples/generic_linked_list.c`

### Changed
 - Instead of `T(T1, ..., Tn)`, write `P(T, T1, ..., Tn)`.

### Fixed
 - Add prefixed versions `PoicaUnit` and `poicaUnit`.

### Removed
 - From the style guide that variants must be prefixed with `Mk`.

## [0.4.0] - 2020-06-27
### Changed
 - Move the specification, changelog, code style, and contributing documents from the wiki into the file tree.
 - Make the `try` macro more convenient for handling `Res`: now it accepts `ok-type-1`, `ok-type-2`, and `err-type`.

### Added
 - `Res`, `DefRes`, `Ok`, `Err`, `isOk`, `isErr`
 - `Either`, `DefEither`, `Left`, `Right`, `isLeft`, `isRight`
 - `Maybe`, `DefMaybe`, `Just`, `Nothing`, `isJust`, `isNothing`
 - `Pair`, `DefPair`
 - `examples/pair.c`, `examples/maybe.c`, `examples/either.c`
 - `Unit` (type)  and `unit` (a static constant value of type `Unit`)

### Removed
 - The wiki.

### Fixed
 - Don't generate an empty structure in `choice`, because empty structures are forbidden in C11.

## [0.3.0] - 2020-06-25
### Changed
 - Turn several public macros into `camelCase`:
   - `ENUM` -> `choice`
   - `VARIANT` -> `variant`
   - `VARIANT_MANY` -> `variantMany`
   - `MATCH` -> `match`
   - `MATCHES` -> `matches`
   - `TRY` -> `try`
   - `OF` -> `of`
   - `OF_MANY` -> `ofMany`
   - `DEFAULT` -> `otherwise`
   - `RECORD` -> `record`
   - `FIELD` -> `field`
   - `OBJ` -> `obj`

 - Add the `POICA_` prefix to the following macros:
   - `CHOICE_INTROSPECT`
   - `VARIANT_KIND`
   - `VARIANT_NAME`
   - `OVERLOAD_ON_VARIANT`
   - `RECORD_INTROSPECT`
   - `FIELD_TYPE`
   - `RECORD_FIELD_TYPES_SEQ`
   - `RECORD_FIELD_TYPES_TUPLE`
   - `RECORD_FIELD_NAMES_SEQ`
   - `RECORD_FIELD_NAMES_TUPLE`

 - `POICA_VARIANT_MANY` -> `POICA_VARIANT_KIND_MANY`, `POICA_VARIANT_SINGLE` -> `POICA_VARIANT_KIND_SINGLE`, `POICA_VARIANT_EMPTY` -> `POICA_VARIANT_KIND_EMPTY`

 - `ENUM_INTROSPECT` -> `CHOICE_INTROSPECT`

 - Don't accept pointers, accept values in `match`, `matches`, `try`.

### Added
 - Optional `POICA_USE_PREFIX`. Now it's possible to prefix all the public `cameelCase`ed macros: `match` -> `poicaMatch`, `try` -> `poicaTry`, etc.
 - `variantTag`
 - `ofMut` and `ofManyMut`
 - `examples/binary_tree_malloc.c` (see [issue #3](https://github.com/Hirrolot/poica/issues/3))

### Removed
 - cppcheck in CI, because it produces many false positives with the syntax.

## [0.2.0] - 2020-06-20
### Changed
 - `SUM` -> `ENUM`, and `PRODUCT` -> `RECORD` because these names are more common.

### Removed
 - `EXTRACT` and `EXTRACT_PTRS`, because the usual C syntax does almost the same job.
 - `OF`, `FROM`, and `MANY`, because they might be used in other projects.

## [0.1.0] - 2020-06-18
### Added
 - This project.
