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
        P(TreeG, branch, type),                                                \
        variantMany(P(Branch, branch, type),                                   \
            field(data, type)                                                  \
            field(branches,                                                    \
                P(branch, P(TreeG, branch, type))                              \
            )                                                                  \
        )                                                                      \
        variant(P(Leaf, branch, type), type))

#define DefBinaryTree(type)                                                    \
    record(                                                                    \
        P(BinaryTree, type),                                                   \
        field(left, struct type *)                                             \
        field(right, struct type *)                                            \
    )

#define DefWeirdTree(type)                                                     \
    record(                                                                    \
        P(WeirdTree, type),                                                    \
        field(text, const char *)                                              \
    )
// clang-format on

DefBinaryTree(P(TreeG, BinaryTree, int));
DefTreeG(BinaryTree, int);

DefWeirdTree(P(TreeG, WeirdTree, int));
DefTreeG(WeirdTree, int);

void binary_tree(void) {
    P(TreeG, BinaryTree, int) _456_leaf = P(Leaf, BinaryTree, int)(456);
    P(TreeG, BinaryTree, int) _789_leaf = P(Leaf, BinaryTree, int)(789);

    P(TreeG, BinaryTree, int)
    binary_tree =
        P(Branch, BinaryTree, int)(123,
                                   (P(BinaryTree, P(TreeG, BinaryTree, int))){
                                       &_456_leaf,
                                       &_789_leaf,
                                   });
}

void weird_tree(void) {
    P(TreeG, WeirdTree, int)
    weird_tree_1 =
        P(Branch, WeirdTree, int)(123,
                                  (P(WeirdTree, P(TreeG, WeirdTree, int))){
                                      .text = "Hey",
                                  });
}

int main(void) {
    binary_tree();
    weird_tree();
}
