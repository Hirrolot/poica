#ifndef POICA_UNIT_TYPE_H
#define POICA_UNIT_TYPE_H

typedef struct UnitType {
    char poica_p_untouched;
} UnitType;

inline static UnitType unit_type(void) {
    return (UnitType){.poica_p_untouched = '\0'};
}

#endif // POICA_UNIT_TYPE_H
