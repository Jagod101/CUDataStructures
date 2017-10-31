#include <iostream>

using namespace std;

//<----------------LIST IMPLEMENTATION-------------------->
template <class T>
class ListNode {
    private:

    public:
        T data;
        GenList *next;
        GenList *prev;

        ListNode(); //Constructor
        ListNode(T data);
        ~ListNode(); //Destructor
};

template <class T>
ListNode<T>::ListNode() {

}

template <class T>
ListNode<T>::ListNode(int d) {
    data = d;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::~ListNode() {
    next = NULL;
    prev = NULL;
}

//<--------------------LIST INTERFACE--------------------->
template <class T>
class DoublyLinkedList {
    private:
        unsigned int size;
        ListNode *front;
        ListNode *back;

    public:
        DoublyLinkedList(); //Constructor
        ~DoublyLinkedList(); //Destructor

        void insertFront(T data);
        void insertBack(T data);

        int removeFront();
        int removeBack();

        void printList();

        int deletePos(int pos);
        //Does int value need to be T value
        int find(int value);
        int remove(int key);

        bool insertAfter(int pos, int val);
        bool isEmpty();

        unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    size = 0;
    front = NULL;
    back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    //SOMETHING GOES HERE
}

template <class T>
void DoublyLinkedList<T>::insertFront(int d) {
    ListNode *node = new ListNode(d);
    
    if(size == 0) {
        back = node;
    }

    else {
        front->prev = node;
        node->next = front;
    }

    front = node;
    size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(int d) {
    ListNode *node = new ListNode(d);
    
    //Empty
    if(size == 0) {
        front = node;
    }
    //Not Empty
    else {
        back->next = node;
        node->prev = back;
    }

    back = node;
    ++size;
}

template <class T>
int DoublyLinkedList<T>::removeFront() {
    ListNode *node = front;
    
    //Only Node in List
    if(front->next == NULL) {
        back = NULL;
    }
    //More than One
    else {
        front->next->prev = NULL;
    }

    front = front->next;
    node->next = NULL;

    int temp = node->data;

    delete node;
    --size;
    return temp;
}

template <class T>
int DoublyLinkedList<T>::removeBack() {
    ListNode *node = back;

    //Only Node in List
    if(front->next == NULL) {
        front = back;
    }
    //More than One
    else {
        back->prev->next = NULL;
    }

    back = back->prev;
    node->prev = NULL;

    int temp = node->data;

    delete node;
    --size;
    return temp;
}

template <class T>
void DoublyLinkedList<T>::printList() {
    ListNode *curr = front;

    while(curr == true) {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

template <class T>
void DoublyLinkedList<T>::deletePos(int pos) {

}

template <class T>
void DoublyLinkedList<T>::find(int value) {
    int idx = -1;
    
    ListNode *curr = front;

    while(curr != NULL) {
        ++idx;

        if(curr->data == value) {
            break;
        }
        else
            curr = curr->next;
    }

    if(curr == NULL)
        idx = -1;
    return idx;

    //Should check for Nodes and other things (Add in own time)
}

template <class T>
int DoublyLinkedList<T>::remove(int key) {
    ListNode *curr = front;
    
    //Looks for Node
    while(curr->data != key) {
        curr = curr->next;

        if(curr == NULL) {
            return NULL;
        }
    }

    //Found Node
    if(curr == front) {
        front = curr->next;
    }
    else {
        curr->prev->next = curr->next;
    }

    if(curr == back) {
        back = curr->prev;
    }
    else {
        curr->next->prev = curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;

    int temp = curr->data;
    delete curr;
    --size;
    return temp;
}

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

        T *myQueue;
};

template <class T>
GenQueue<T>::GenQueue(int maxSize) {
    myQueue = new char[maxSize];
    head = 0;
    tail = -1;
    max = maxSize;
    numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue() {
    cout << "Object Destroyed" << endl;
}

template <class T>
void GenQueue<T>::insert(T data) {
    //ADD INSERT CHECKS

    //Circular Queue
    if(tail == max-1) {
        tail = -1;
    }
    
    myQueue[++tail] = data;
    ++numElements;
}

template <class T>
T GenQueue<T>::remove() {
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

//<--------------------WINDOWS----------------------->
template <class T>
class Windows {
    private:

    public:
        Windows(); //Constructor
        ~Windows();
}