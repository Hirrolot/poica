#ifndef POICA_UNIT_TYPE_H
#define POICA_UNIT_TYPE_H

typedef struct UnitType {
    bool poica_p_untouched;
} UnitType;

inline static UnitType unit_type(void) {
    return (UnitType){.poica_p_untouched = true};
}

#endif // POICA_UNIT_TYPE_H
