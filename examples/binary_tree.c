#include <poica.h>

#include <stdio.h>

// clang-format off
SUM(
    Tree,
    VARIANT(MkEmpty)
    VARIANT(MkLeaf OF int)
    VARIANT(MkNode OF MANY
        FIELD(left OF struct Tree *)
        FIELD(number OF int)
        FIELD(right OF struct Tree *)
    )
);
// clang-format on

void print_tree(const Tree *tree) {
    MATCH(tree) {
        CASE(MkEmpty) {
            return;
        }
        CASE(MkLeaf, number) {
            printf("%d\n", *number);
        }
        CASE(MkNode, MANY(left, number, right)) {
            inc_tree(*left);
            printf("%d\n", *number);
            inc_tree(*right);
        }
    }
}

#define TREE(tree)                OBJ(tree OF Tree)
#define NODE(left, number, right) MkNode(TREE(left), number, TREE(right))
#define LEAF(number)              TREE(MkLeaf(number))

int main(void) {
    Tree tree =
        NODE(NODE(LEAF(81), 456, NODE(LEAF(90), 7, LEAF(111))), 57, LEAF(123));

    print_tree(&tree);
}

#undef TREE
#undef NODE
#undef LEAF
