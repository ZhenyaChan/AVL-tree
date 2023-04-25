template <class T>
class Queue {
    T* theQueue_;
    int capacity_;
    int used_;
    int front_;
    int back_;

    // function doubles capacity of the queue by creating bigger queue and copying data from old queue to the new bigger one
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
    // constructor
    Queue(){
        theQueue_ = new T[50];
        capacity_ = 50;
        used_ = 0;
        front_ = 0;
        back_ = 0;
    }

    // function adds the passed data to the back of the queue
    // if the queue is full, call grow() function
    // adds the data to the back of the queue using "back" index, increases the index and number of elements in the queue
    void enqueue(const T& data){
        if (used_ == capacity_) {
            grow();
        }
        theQueue_[back_] = data;
        back_ = (back_ + 1) % capacity_;
        used_++;
    }

    // function removes the oldest element of the queue (front of the queue) by changing "front" index of the array and decreasing number of elements in the queue
    void dequeue() {
        if (!isEmpty()) {
            used_--;
            front_ = (front_ + 1) % capacity_;
        }
    }

    // function returns the next element in the queue to be deleted (front of the queue) if the queue is not empty;
    // if queue is empty, then returns initial value of the T
    T front() const{
        if (!isEmpty()) {
            return theQueue_[front_];
        }
        return T{};
    }

    // function returns false if the queue is empty, otherwise returns true
    bool isEmpty() {
        return used_ == 0;
    }

    // destructor to deallocate the queue pointer
    ~Queue() {
        delete[] theQueue_;
    }
};