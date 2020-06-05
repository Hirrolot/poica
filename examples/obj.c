#include "../src/obj.h"

typedef struct {
    int x, y;
} Point;

Point create_point(void) {
    return (Point){54, 367};
}

int main(void) {
    Point *point = OBJ(create_point() OF Point);
}
