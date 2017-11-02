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

//<----------------LIST IMPLEMENTATION-------------------->
template <class T>
class ListNode {
    private:

    public:
        T data;
        ListNode<T> *next;
        ListNode<T> *prev;

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