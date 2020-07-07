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

// "branch" has kind * -> *, type has kind *.
// clang-format off
#define DefTreeG(branch, type)                                                 \
    choice(                                                                    \
        TreeG(branch, type),                                                   \
        variantMany(Branch(branch, type),                                      \
            field(data, type)                                                  \
            field(branches,                                                    \
                POICA_MONOMORPHISE(branch, TreeG(branch, type))                \
            )                                                                  \
        )                                                                      \
        variant(Leaf(branch, type), type))
// clang-format on

#define TreeG(branch, type)  POICA_MONOMORPHISE(TreeG, branch, type)
#define Branch(branch, type) POICA_MONOMORPHISE(Branch, branch, type)
#define Leaf(branch, type)   POICA_MONOMORPHISE(Leaf, branch, type)

// clang-format off
#define DefBinaryTree(type)                                                    \
    record(                                                                    \
        BinaryTree(type),                                                      \
        field(left, struct type *)                                             \
        field(right, struct type *)                                            \
    )
// clang-format on
#define BinaryTree(type) POICA_MONOMORPHISE(BinaryTree, type)

// clang-format off
#define DefWeirdTree(type)                                                     \
    record(                                                                    \
        WeirdTree(type),                                                       \
        field(text, const char *)                                              \
    )
// clang-format on
#define WeirdTree(type) POICA_MONOMORPHISE(WeirdTree, type)

DefBinaryTree(TreeG(BinaryTree, int));
DefTreeG(BinaryTree, int);

DefWeirdTree(TreeG(WeirdTree, int));
DefTreeG(WeirdTree, int);

void binary_tree(void) {
    TreeG(BinaryTree, int) _456_leaf = Leaf(BinaryTree, int)(456);
    TreeG(BinaryTree, int) _789_leaf = Leaf(BinaryTree, int)(789);

    TreeG(BinaryTree, int) binary_tree =
        Branch(BinaryTree, int)(123,
                                (BinaryTree(TreeG(BinaryTree, int))){
                                    &_456_leaf,
                                    &_789_leaf,
                                });
}

void weird_tree(void) {
    TreeG(WeirdTree, int) weird_tree_1 =
        Branch(WeirdTree, int)(123,
                               (WeirdTree(TreeG(WeirdTree, int))){
                                   .text = "Hey",
                               });
}

int main(void) {
    binary_tree();
    weird_tree();
}
