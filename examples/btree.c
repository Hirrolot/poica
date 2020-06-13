#include <poica.h>

#include <stdio.h>

// clang-format off
SUM(
    BTree,
    VARIANT(MkEmpty)
    VARIANT(MkLeaf OF int)
    VARIANT(MkNode OF MANY
        FIELD(left OF struct BTree *)
        FIELD(number OF int)
        FIELD(right OF struct BTree *)
    )
);
// clang-format on

void inc_btree(BTree *tree) {
    MATCH(tree) {
        CASE(MkEmpty) {
            return;
        }
        CASE(MkLeaf, number) {
            (*number)++;
        }
        CASE(MkNode, MANY(left, number, right)) {
            (*number)++;
            inc_btree(*left);
            inc_btree(*right);
        }
    }
}

int main(void) {
    // clang-format off
    inc_btree(OBJ(MkNode(
        OBJ(MkLeaf(123) OF BTree), 57, OBJ(MkLeaf(123) OF BTree)) OF BTree));
    
}
