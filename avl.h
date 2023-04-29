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

        // constructor
        Node(const T& data=T{}, Node* left=nullptr, Node* right=nullptr){
            data_ = data;
            left_ = left;
            right_ = right;
            height_ = 1;
        }

        // function returns the height balance of this node
        int balance() const {
            int heightRight = (right_) ? right_->height_ : 0;
            int heightLeft = (left_) ? left_->height_ : 0;
            return heightRight - heightLeft;
        }

        // function updates the height of the node
        void updateHeight() {
            int heightRight = (right_) ? right_->height_ : 0;
            int heightLeft = (left_) ? left_->height_ : 0;
            height_ = 1 + (heightRight > heightLeft) ? heightRight : heightLeft;
        }
    };
    // pointer to the root of the avl-tree
    Node* root_;

    // function inserts data into the subtree with root "subtree"
    void insert(Node*& subtree, const T& data) {
        if (!subtree) {
            subtree = new Node(data);
        }
        else {
            // insert the data
            if (data < subtree->data_) {
                insert(subtree->left_, data);
            } else {
                insert(subtree->right_, data);
            }

            // fix the tree
            if (subtree->balance() == 2) {
                if (subtree->right_->balance() == -1) {
                    // double rotation
                    rightRotate(subtree->right_);
                    leftRotate(subtree);
                    subtree->right_->updateHeight();
                    subtree->left_->updateHeight();
                    subtree->updateHeight();
                }
                else {
                    // single rotation
                    leftRotate(subtree);
                    subtree->left_->updateHeight();
                    subtree->updateHeight();
                }
            } else if (subtree->balance() == -2) {
                if (subtree->right_->balance() == 1) {
                    // double rotation
                    leftRotate(subtree->left_);
                    rightRotate(subtree);
                    subtree->left_->updateHeight();
                    subtree->right_->updateHeight();
                    subtree->updateHeight();
                }
                else {
                    // single rotation
                    rightRotate(subtree);
                    subtree->right_->updateHeight();
                    subtree->updateHeight();
                }
            } else {
                subtree->updateHeight();
            }
        }
    }

    void leftRotate(Node*& A) {
        Node* B = A->right_;
        Node* y = B->left_;
        B->left_ = A;
        A->right_ = y;
        A = B;
    }

    void rightRotate(Node*& A) {
        Node* B = A->left_;
        Node* y = B->right_;
        B->right_ = A;
        A->left_ = y;
        A = B;
    }
public:
    // constructor to initialize avl-tree
    AVL() {
        root_ = nullptr;
    }

    // call private recursive insertion function to insert data into the AVL tree
    void insert(const T& data) {
        insert(root_, data);
    }

    void printInOrder() {

    }

    void printBreadthFirst() {

    }
};