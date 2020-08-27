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

/*
 * The version of binary_tree.c, which uses malloc & free, instead of allocating
 * objects on a program stack.
 */

#include <poica.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clang-format off
choice(
    Tree,
    variant(Empty)
    variant(Leaf, int)
    variantMany(Node,
        field(left, struct Tree *)
        field(number, int)
        field(right, struct Tree *)
    )
);
// clang-format on

void print_tree(const Tree *tree) {
    match(*tree) {
        of(Empty) {
            return;
        }
        of(Leaf, number) {
            printf("%d\n", *number);
        }
        ofMany(Node, (left, number, right)) {
            print_tree(*left);
            printf("%d\n", *number);
            print_tree(*right);
        }
    }
}

Tree *alloc_tree(Tree tree) {
    Tree *res = malloc(sizeof(*res));
    assert(res);
    memcpy((void *)res, (const void *)&tree, sizeof(tree));
    return res;
}

void destroy_tree(Tree *tree) {
    match(*tree) {
        of(Empty) {
            return;
        }
        of(Leaf, number) {
            free(tree);
            return;
        }
        ofMany(Node, (left, number, right)) {
            destroy_tree(*left);
            destroy_tree(*right);
            free(tree);
        }
    }
}

#define TREE(tree)                alloc_tree(tree)
#define NODE(left, number, right) TREE(Node(left, number, right))
#define LEAF(number)              TREE(Leaf(number))

int main(void) {
    Tree *tree = NODE(NODE(LEAF(81), 456, NODE(LEAF(90), 7, LEAF(111))), 57, LEAF(123));

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
    destroy_tree(tree);
}
