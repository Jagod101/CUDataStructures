#include <iostream>
#include "genqueue.h"

using namespace std;

GenQueue::GenQueue(int maxSize) {
    myQueue = new char[maxSize]; //Dynamic Memory Allocation
    head = 0;
    tail = -1;
    max = maxSize;
    numElements = 0;
}

GenQueue::~GenQueue() {
    cout << "Object Destroyed" << endl;
}

GenQueue::insert(char data) {
    //Make All Necessary Checks

    //Circular Queue
    if(tail == max-1) {
        tail = -1;
    }
    
    myQueue[++tail] = data;
    ++numElements;
}

//Always Remove from the Front
GenQueue::remove() {
    char c = '\0';
    c = myQueue[head];
    ++head;

    //Circular Queue
    if(head == max) {
        head = 0;
    }

    --numElements;
    return c;
}

GenQueue::peek() {
    return myQueue[head];
}

GenQueue::isFull() {
    return (numElements = max);
}

GenQueue::isEmpty() {
    return (numElements = 0);
}

GenQueue::getSize() {
    return numElements;
}