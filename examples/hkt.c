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

// clang-format off
#define DefTree(f, t)                                                          \
    choice(                                                                    \
        P(Tree, f, t),                                                         \
        variantMany(                                                           \
            P(Branch, f, t),                                                   \
            field(data, t)                                                     \
            field(branches, P(f, P(Tree, f, t)))                               \
        )                                                                      \
        variant(P(Leaf, f, t), t)                                              \
    )

#define DefBinaryTree(t)                                                       \
    record(                                                                    \
        P(BinaryTree, t),                                                      \
        field(left, struct t *)                                                \
        field(right, struct t *)                                               \
    )

#define DefTreeTree(t)                                                         \
    record(                                                                    \
        P(TreeTree, t),                                                        \
        field(data, struct P(Tree, TreeTree, t) *)                             \
    )
// clang-format on

#define BinaryTree(t) P(Tree, BinaryTree, t)
#define TreeTree(t)   P(Tree, TreeTree, t)

#define BinaryTreeBranch(t, data, left, right)                                 \
    P(Branch, BinaryTree, t)                                                   \
    (data, (P(BinaryTree, P(Tree, BinaryTree, t))){left, right})

#define TreeTreeBranch(t, data, tree)                                          \
    P(Branch, TreeTree, t)                                                     \
    (data, (P(TreeTree, P(Tree, TreeTree, t))){tree})

DefBinaryTree(P(Tree, BinaryTree, int));
DefTree(BinaryTree, int);

DefTreeTree(P(Tree, TreeTree, int));
DefTree(TreeTree, int);

// TODO: fix this
// DefTree(TreeTree, TreeTree(TreeTree(int)));

int main(void) {
    BinaryTree(int) _456 = P(Leaf, BinaryTree, int)(456);
    BinaryTree(int) _759 = P(Leaf, BinaryTree, int)(759);

    BinaryTree(int) binary_tree = BinaryTreeBranch(int, 123, &_456, &_759);

    //   TreeTree(TreeTree(int)) _145 =
    //     P(Leaf, TreeTree, P(Tree, TreeTree, int))(759);

    // TreeTree(int) tree_tree = TreeTreeBranch(int, 33, &_145);
}
