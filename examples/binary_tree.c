/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Hirrolot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <poica.h>

#include <stdio.h>

// clang-format off
ENUM(
    Tree,
    VARIANT(MkEmpty)
    VARIANT(MkLeaf, int)
    VARIANT_MANY(MkNode,
        FIELD(left, struct Tree *)
        FIELD(number, int)
        FIELD(right, struct Tree *)
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
        CASE_MANY(MkNode, (left, number, right)) {
            print_tree(*left);
            printf("%d\n", *number);
            print_tree(*right);
        }
    }
}

#define TREE(tree)                OBJ(tree, Tree)
#define NODE(left, number, right) TREE(MkNode(left, number, right))
#define LEAF(number)              TREE(MkLeaf(number))

int main(void) {
    const Tree *tree =
        NODE(NODE(LEAF(81), 456, NODE(LEAF(90), 7, LEAF(111))), 57, LEAF(123));

    /*
     * Output:
     * 81
     * 456
     * 90
     * 7
     * 111
     * 57
     * 123
     */
    print_tree(tree);
}

#undef TREE
#undef NODE
#undef LEAF
