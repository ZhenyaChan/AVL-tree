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

    // function performs left rotation towards passed Node A (A is parent, B is right child)
    void leftRotate(Node*& A) {
        Node* B = A->right_;
        Node* y = B->left_;
        B->left_ = A;
        A->right_ = y;
        A = B;
    }

    // function performs right rotation towards passed Node A (A is parent, B is left child)
    void rightRotate(Node*& A) {
        Node* B = A->left_;
        Node* y = B->right_;
        B->right_ = A;
        A->left_ = y;
        A = B;
    }

    // function used by printPreOrder()to print the nodes in the subtree with passed "subtree" Node as root node using "pre-order" traversal
    void printPreOrder(Node* subtree) const{
        if (subtree) {
            std::cout << subtree->data_ << " ";
            printPreOrder(subtree->left_);
            printPreOrder(subtree->right_);
        }
    }

    // function used by printInOrder()to print the nodes in the subtree with passed "subtree" Node as root node using "in-order" traversal
    void printInOrder(Node* subtree) const{
        if (subtree) {
            printInOrder(subtree->left_);
            std::cout << subtree->data_ << " ";
            printInOrder(subtree->right_);
        }
    }

    // function used by destructor ~AVL() to delete the nodes in the tree with passed root Node using "post-order" traversal    
    void destroy(Node* subtree) {
        if (subtree) {
            destroy(subtree->left_);
            destroy(subtree->right_);
            delete subtree;
        }
    }

    // function recursively checks if the passed two subtree root nodes and their subtrees are the same or not
    // returns true if they are the same, false otherwise
    bool isSame(const Node* left, const Node* right) const{
		bool rc;

		if (left == nullptr && right == nullptr) {
			rc = true;
		}
		else if (left && right) {
			if (left->data_ != right->data_) {
				rc = false;
			}
			else {
				rc = (isSame(left->left_, right->left_) && isSame(left->right_, right->right_));
			}
		}
		else {
			// one is nullptr and one is not
			rc = false;
		}

		return rc;
	}

    // function used by print() to print all nodes at same level
    void printLine(Node* subtree) const{

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

    // functions calls private printPreOrder() function to print all nodes in the AVL tree using pre-order traversal
    void printPreOrder() {
        printPreOrder(root_);
        std::cout << std::endl;
    }

    // functions calls private printInOrder() function to print all nodes in the AVL tree using in-order traversal
    void printInOrder() {
        printInOrder(root_);
        std::cout << std::endl;
    }

    // function prints how the tree looks like
    void print() {
        printLine(root_);
    }

    // function compares two trees if they are the same or not by calling private isSame() function
    bool operator==(const AVL& rhs) const{
		return isSame(root_, rhs.root_);
	}

    // functions calls private destroy() function to delete all nodes in the AVL tree using post-order traversal
    ~AVL() {
        destroy(root_);
    }
};