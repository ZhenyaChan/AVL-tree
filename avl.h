#include <iostream>
#include <iomanip>
#include "arrayqueue.h"

template <class T>
class AVL {
    struct Node {
        T data_;
        Node* left_;
        Node* right_;
        int height_;

        Node(const T& data=T{}, Node* left=nullptr, Node* right=nullptr){
            data_ = data;
            left_ = left;
            right_ = right;
            height_ = 1;
        }
    };

    Node* root_;
};