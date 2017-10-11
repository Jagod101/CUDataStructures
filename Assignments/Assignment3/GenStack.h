/*
 Zach Jagoda
 Student ID: 2274813
 Student Email: jagod101@mail.chapman.edu
 CPSC 350-02

 Assignment 3: Syntax Checker
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <class T>
class GenStack {
    private:

    public:
        GenStack(int maxsize);
        ~GenStack();

        void push(T data);
        T pop();
        T peek();

        int isFull();
        int isEmpty();

        void increaseSize();

        int top;
        int max;

        T *myArray;
        T *tempArray;
};

template <class T>
GenStack<T>::GenStack(int maxsize) {
    myArray = new T[maxsize];
    max = maxsize;
    top = -1;
    tempArray = new T[max];
}

template <class T>
GenStack<T>::~GenStack() {
    delete []myArray;
    delete []tempArray;

    cout << "Object Destroyed\n" << endl;
}

template <class T>
void GenStack<T>::push(T data) {
    if (isFull() == 1) {
        increaseSize();
        push(data);
    }
    else {
        myArray[++top] = data;
    }
}

template <class T>
T GenStack<T>::pop() {
    if (isEmpty() == 1) {
        cout << "ERROR: current stack is empty\n" << endl;
        return 0;
    }
    else {
        return myArray[top--];
    }
}

template <class T>
T GenStack<T>::peek() {
    if (top == -1) {
        return 0;
    }
    else {
        return myArray[top];
    }
}

template <class T>
int GenStack<T>::isFull() {
    return (top == max-1);
}

template <class T>
int GenStack<T>::isEmpty() {
    return (top == -1);
}

template <class T>
void GenStack<T>::increaseSize() {
    tempArray = new T[max];

    for (int i = top; i > -1; --i) {
        tempArray[i] = myArray[i];
    }

    max += 1;
    myArray = new T[max];

    for (int i = top; i > -1; --i) {
        myArray[i] = tempArray[i];
    }
}
