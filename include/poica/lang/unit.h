#ifndef POICA_LANG_UNIT_H
#define POICA_LANG_UNIT_H

#ifdef POICA_USE_PREFIX

typedef struct PoicaUnit {
    char poica_p_untouched;
} PoicaUnit;

static const PoicaUnit poicaUnit;

#else

typedef struct Unit {
    char poica_p_untouched;
} Unit;

static const Unit unit;

#endif // POICA_LANG_USE_PREFIX

#endif // POICA_LANG_UNIT_H
