#include <iostream>
#include <iomanip>

// forward declaration
template <class T>
class Queue;

template <class T>
class AVL {
    struct Node {
        T data_;
        Node* left_;
        Node* right_;

        Node(const T& data=T{}, Node* left=nullptr, Node* right=nullptr){
            data_ = data;
            left_ = left;
            right_ = right;
        }
    };

    Node* root_;
};


template <class T>
class Queue {
    T* theQueue_;
    int capacity_;
    int used_;
    int front_;
    int back_;

    void grow() {
        T* temp = new T[capacity_ * 2];
        int j;

        for (int i = 0, j = front_; i < used_; i++, j=(j+1)%capacity_) {
            temp[i] = theQueue_[j];
        }
        delete[] theQueue_;
        theQueue_ = temp;
        capacity_ = capacity_ * 2;
        front_ = 0;
        back_ = used_;
    }
public:
    Queue(){
        theQueue_ = new T[50];
        capacity_ = 50;
        used_ = 0;
        front_ = 0;
        back_ = 0;
    }

    void enqueue(const T& data){
        
    }
};