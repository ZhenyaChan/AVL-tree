/************************************************************/
/*  To compile:                                             */
/*     g++ avl-main.cpp -std=c++0x                          */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/
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
    tree.print();
}