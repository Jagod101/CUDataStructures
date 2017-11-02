/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar’s Office Simulation 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

//<------------------------QUEUE-------------------------->
template <class T>
class GenQueue {
    private:

    public: 
        GenQueue(int maxSize);
        ~GenQueue();

        void insert(T data);
        T remove();
        T peek();

        int isFull();
        int isEmpty();
        int getSize();

        int head;
        int tail;
        int max;

        DoublyLinkedList<T> myQueue;
};

template <class T>
GenQueue<T>::GenQueue(int maxSize) {
    DoublyLinkedList<T> myQueue = DoublyLinkedList<T>();
    max = maxSize;
    numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue() {
    //cout << "Object Destroyed" << endl;
}

template <class T>
void GenQueue<T>::insert(T data) {
    if(numElements == max) {
        cout << "Queue is Full" << endl;
    }
    else {
        myQueue.insertBack(data);
        ++numElements;
    }
}

template <class T>
T GenQueue<T>::remove() {
    if(numElements == 0) {
        cout << "Queue is Empty" << endl;
    }
    else {
        --numElements;
        return myQueue.removeFront();
    }
}

template <class T>
T GenQueue<T>::peek() {
    return myQueue[head];
}

template <class T>
int GenQueue<T>::isFull() {
    return (numElements = max);
}

template <class T>
int GenQueue<T>::isEmpty() {
    return (numElements = 0);
}

template <class T>
int GenQueue<T>::getSize() {
    return numElements;
}