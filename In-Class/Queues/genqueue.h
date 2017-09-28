#include <iostream>

class GenQueue {
    public:
            GenQueue(int maxSize);
            ~GenQueue();
            
            void insert(char data);
            char remove();
            char peek();

            int isFull();
            int isEmpty();

            int head;
            int tail;
            int max;

            int numElements;

            int getSize();

            char myQueue;
}