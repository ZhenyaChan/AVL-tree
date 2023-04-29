#include "avl.h"

int main (void) {
    AVL<int> tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(5);
    tree.insert(23);
    tree.insert(21);
    tree.insert(1);
    tree.insert(3);
    tree.printInOrder();
    tree.printBreadthFirst();
}