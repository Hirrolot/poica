#ifndef POICA_LANG_UNIT_H
#define POICA_LANG_UNIT_H

typedef struct PoicaUnit {
    char poica_p_untouched;
} PoicaUnit;

static const PoicaUnit poicaUnit;

#ifndef POICA_USE_PREFIX

typedef PoicaUnit Unit;
#define unit poicaUnit

#endif

#endif // POICA_LANG_UNIT_H
