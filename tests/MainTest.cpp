#include "../symmetrictree.cpp"
#include "gtest/gtest.h"


TEST(Tree, Empty) {
    std::vector<int> expected_out = {0};
    std::vector<int> out;
    Tree *tree = new Tree{};
    symmetric(tree, out);
    EXPECT_EQ(expected_out, out);
}


TEST(Tree, element_right) {
    std::vector<int> expected_out = {0, 1};
    std::vector<int> out;
    Tree *tree = new Tree{};
    pushRight(1, tree);
    symmetric(tree, out);
    EXPECT_EQ(expected_out, out);
}

TEST(Tree, FullTree) {
    std::vector<int> out;
    std::vector<int> expected_out = {250, 42, 1337, 35, -87, 18, 171, 56, -35, 48, 69};
    srandom(time(nullptr));
    Tree *tree = new Tree{56, nullptr, nullptr};

    pushLeft(35, tree);
    pushRight(48, tree);

    pushLeft(-35, tree->right);
    pushRight(69, tree->right);

    pushLeft(42, tree->left);
    pushRight(18, tree->left);

    pushLeft(-87, tree->left->right);
    pushRight(171, tree->left->right);

    pushLeft(250, tree->left->left);
    pushRight(1337, tree->left->left);

    symmetric(tree, out);
    EXPECT_EQ(expected_out, out);

}