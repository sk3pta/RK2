#include <iostream>
#include <random>
#include <ctime>

struct Tree {
    int value = 0;
    struct Tree *parent = nullptr;
    struct Tree *left = nullptr;
    struct Tree *right = nullptr;
};


void pushLeft(int value, Tree *pTree) {
    pTree->left = new Tree;
    pTree->left->value = value;
    pTree->left->parent = pTree;
}

void pushRight(int value, Tree *pTree) {
    pTree->right = new Tree;
    pTree->right->value = value;
    pTree->right->parent = pTree;
}


void symmetric(Tree *tree) {
    if (tree == nullptr) return;
    symmetric(tree->left);
    std::cout << tree->value << " ";
    symmetric(tree->right);

}


int main() {
    srandom(time(nullptr));
    Tree *tree = new Tree{static_cast<int>(-100 + random() % 200), nullptr, nullptr};

    pushLeft(static_cast<int>(-100 + random() % 200), tree);
    pushRight(static_cast<int>(-100 + random() % 200), tree);
    pushLeft(static_cast<int>(-100 + random() % 200), tree->right);
    pushRight(static_cast<int>(-100 + random() % 200), tree->right);


    pushLeft(static_cast<int>(-100 + random() % 200), tree->left);
    pushRight(static_cast<int>(-100 + random() % 200), tree->left);

    pushLeft(static_cast<int>(-100 + random() % 200), tree->left->right);
    pushRight(static_cast<int>(-100 + random() % 200), tree->left->right);


    pushLeft(static_cast<int>(-100 + random() % 200), tree->left->left);
    pushRight(static_cast<int>(-100 + random() % 200), tree->left->left);

    symmetric(tree);


}
