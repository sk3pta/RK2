#include <iostream>
#include <random>


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


void symmetric(Tree *tree, std::vector<int> &out) {

    if (tree == nullptr) return;
    symmetric(tree->left, out);
    //std::cout << tree->value << " ";
    out.push_back(tree->value);
    symmetric(tree->right, out);

}

/*

int main() {

    std::vector<int> out;


    Tree *tree = new Tree {56, nullptr, nullptr};
    pushLeft(35, tree);
    pushRight(48  , tree);
    pushLeft(-35, tree->right);
    pushRight(69, tree->right);


    pushLeft(42, tree->left);
    pushRight(18, tree->left);

    pushLeft(-87, tree->left->right);
    pushRight(171, tree->left->right);


    pushLeft(250, tree->left->left);
    pushRight(1337, tree->left->left);


    symmetric(tree,out);
std::cout << "AA";
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
 */
