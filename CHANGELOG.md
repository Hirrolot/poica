# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.4.0] - 2020-06-27
### Changed
 - Move the specification, changelog, code style, and contributing documents from the wiki into the file tree.
 - Make the `try` macro more convenient for handling `Res`: now it accepts `ok-type-1`, `ok-type-2`, and `err-type`.

### Added
 - `Res`, `DefRes`, `Ok`, `Err`, `isOk`, `isErr`
 - `Either`, `DefEither`, `Left`, `Right`, `isLeft`, `isRight`
 - `Maybe`, `DefMaybe`, `Just`, `Nothing`, `isJust`, `isNothing`
 - `Pair`, `DefPair`
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
