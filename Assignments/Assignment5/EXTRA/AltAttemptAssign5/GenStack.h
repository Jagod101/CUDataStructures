/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>

using namespace std;

template <class T>
class GenStack {
  private:

  public:
    GenStack();
    ~GenStack();

    void push(T d);
    T pop();
    T peek();

    bool isEmpty();

    T *rbStack;
};

template <class T>
GenStack<T>::GenStack() {
  rbStack = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack() {
  delete rbStack;
}

template <class T>
void GenStack<T>::push(T d) {
  rbStack->insertFront(d);
}

template <class T>
T GenStack<T>::pop() {
  return rbStack->removeFront();
}

template <class T>
T GenStack<T>::peek() {
  if(isEmpty()) {
    cout << "Stack is Empty" << endl;
  }
  else {
    return rbStack->peekFront();
  }
}

template <class T>
bool GenStack<T>::isEmpty() {
  return rbStack->isEmpty();
}
