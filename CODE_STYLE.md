# Code style

## Naming

| Naming | Software entities |
|--------|-------------------|
| `snake_case` | Procedures, files, variables |
| `PascalCase` | Types |
| `SCREAMING_CASE` | Macros |

Private stuff (except for files) has either `POICA_P` (for types and macros) or `poica_p` prefix (for procedures and variables). Variant names have the `Mk` prefix.

## Headers

Refer to [this document](http://www.umich.edu/~eecs381/handouts/CHeaderFileGuidelines.pdf) describing conventions for header files.

### Inclusion order

 1. Local headers;
 2. libc;
 3. Third-party libraries.

### New line separation
Logically different blocks of `#include` directives shall be separated by a new line, in particular, when including headers from different libraries.

### Example
```c
#include "my_a.h"
#include "my_b.h"
#include "my_c.h"

#include <stdbool.h>
#include <stdio.h>

#include <boost/preprocessor/array/push_front.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/remove.hpp>
#include <boost/preprocessor/slot/slot.hpp>

#include <some_other_library/memory.h>
#include <some_other_library/processor.h>

...
```
