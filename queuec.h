#ifndef QUEUEC_H
#define QUEUEC_H

#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    T* arr;     // pointer to array of elements
    int capacity;   // maximum number of elements that can be stored in the queue
    int front;      // index of the front element
    int rear;       // index of the rear element
    int count;      // current size of the queue

public:
    Queue() {
        arr = new T[1];
        capacity = 1;
        front = 0;
        rear = -1;
        count = 0;
    }

    
    Queue(int size) {
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free up the memory allocated for the array
   
    ~Queue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    
    bool isEmpty() {
        return count == 0;
    }

    // Function to check if the queue is full
    
    bool isFull() {
        return count == capacity;
    }

    // Function to add an element to the rear of the queue

    
    void push(const T& elem) {
        if (isFull()) {
            cout << "Queue overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = elem;
        count++;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            return T();
        }
        else
            return arr[front];
    }

    // Function to remove an element from the front of the queue and return its value
    
    T pop() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return T();     // default value for type T
        }
        T elem = arr[front];
        front = (front + 1) % capacity;
        count--;
        return elem;
    }
};

#endif
