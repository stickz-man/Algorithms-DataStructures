#include "stringQueue.h"
#include <iostream>
using namespace std;

class stringQueue {
public:
    // Constructor and Destructor
    stringQueue(int capacity);
    ~stringQueue();

    // Queue operations
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const string& elem);
    string dequeue();

private:
    string* list;
    const int CAPACITY;
    int front;
    int back;
    int size;
};

// Constructor
stringQueue::stringQueue(int capacity) : list(new string[capacity]), 
    CAPACITY(capacity), front(0), back(0), size(0) {}

// Destructor
stringQueue::~stringQueue() {
    delete[] list;
}

// Check if the queue is empty
bool stringQueue::isEmpty() const {
    return size == 0;
}

// Check if the queue is full
bool stringQueue::isFull() const {
    return size == CAPACITY;
}

// Adds an element to the back of the queue
void stringQueue::enqueue(const string& elem) {
    if (!isFull()) {
        list[back] = elem;
        back = (back + 1) % CAPACITY; // Circular increment
        size++;
    } else {
        cout << "Error: stringQueue is full." << endl;
    }
}

// Removes and returns the element at the front of the queue
string stringQueue::dequeue() {
    if (!isEmpty()) {
        string dequeuedStr = list[front];
        front = (front + 1) % CAPACITY; // Circular increment
        size--;
        return dequeuedStr;
    } else {
        return "Error: Queue is empty!";
    }
}
