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

//<--------------------LIST INTERFACE--------------------->
template <class T>
class DoublyLinkedList {
    private:
        unsigned int size;
        ListNode<T> *front;
        ListNode<T> *back;

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
    ListNode<T> *node = new ListNode(d);
    
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
    ListNode<T> *node = new ListNode(d);
    
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
    ListNode<T> *node = front;
    
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
    ListNode<T> *node = back;

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
    ListNode<T> *curr = front;

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
    
    ListNode<T> *curr = front;

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
    ListNode<T> *curr = front;
    
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