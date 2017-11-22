/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>

using namespace std;

template <class T>
class ListNode {
    public:
        T data;
        ListNode *next;
        ListNode *prev;

        ListNode(); //Constructor
        ListNode(T d);
        ~ListNode(); //Destructor
};

template <class T>
ListNode<T>::ListNode() {
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d) {
    data = d;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::~ListNode() {

}

template <class T>
class DoublyLinkedList {
    private:
        unsigned int size;
        ListNode *front;
        ListNode *back;

    public:
        DoublyLinkedList(); //Constructor
        ~DoublyLinkedList(); //Destructor

        void insertFront(T d);
        void insertBack(T d);

        T removeFront();
        T removeBack();

        void printList(); //Prints Contents of LinkedList

        T deletePos(int pos); //Remove at Specified Position
        int find(int value); //Find Value within LinkedList
        int remove(int key);

        bool inserAfter(int pos, int val);
        bool isEmpty(); //Checks to see if Empty

        unsigned int getSize();
};

DoublyLinkedList::DoublyLinkedList() {
    size = 0;
    front = NULL;
    back = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
    //build some character and research it
}

void DoublyLinkedList::insertFront(int d) {
    ListNode *node = new ListNode(d);

    //Empty
    if(size == 0) {
        back = node;
    }
    //Not Empty
    else {
        front->prev = node;
        node->next = front;
    }

    front = node;
    size++;
}

void DoublyLinkedList::insertBack(int d) {
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

int DoublyLinkedList::removeFront() {
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

int DoublyLinkedList::removeBack() {

}

void DoublyLinkedList::printList() {

}

void DoublyLinkedList::deletePos(int pos) {

}

void DoublyLinkedList::find(int value) {

}

int DoublyLinkedList::remove(int key) {
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
