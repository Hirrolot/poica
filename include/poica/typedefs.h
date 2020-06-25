#ifndef POICA_TYPEDEFS_H
#define POICA_TYPEDEFS_H

#ifdef POICA_USE_PREFIX

typedef char *PoicaCharPtr;
typedef const char *PoicaConstCharPtr;

typedef int *PoicaIntPtr;
typedef const int *PoicaConstIntPtr;

typedef long *PoicaLongPtr;
typedef const long *PoicaConstLongPtr;

#else

typedef char *CharPtr;
typedef const char *ConstCharPtr;

typedef int *IntPtr;
typedef const int *ConstIntPtr;

typedef long *LongPtr;
typedef const long *ConstLongPtr;

#endif

#endif // POICA_TYPEDEFS_H
