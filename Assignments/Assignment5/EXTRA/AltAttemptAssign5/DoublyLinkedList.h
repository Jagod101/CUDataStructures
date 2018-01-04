/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>

using namespace std;

//<-----------------------------ListNode Class------------------------------->
template <class T>
class ListNode {
    public:
        T data;
        ListNode<T> *next;
        ListNode<T> *prev;

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

//<-------------------------DoublyLinkedList Class--------------------------->
template <class T>
class DoublyLinkedList {
    private:
        unsigned int size;
        ListNode<T> *back;

    public:
        ListNode<T> *front;

        DoublyLinkedList(); //Constructor
        ~DoublyLinkedList(); //Destructor

        void insertFront(T d);
        void insertBack(T d);

        T removeFront();
        T removeBack();

        T peekFront();
        T peekBack();

        bool find(T d); //Find Value within LinkedList
        bool remove(T d);

        bool isEmpty();

        unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    front = NULL;
    back = NULL;
    size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    ListNode<T> *temp = front;
    while(front->next != NULL) {
      temp = front->next;
      front->next = NULL;
      temp->prev = NULL;
      delete front;
      front = temp;
    }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d) {
    ListNode<T> *node = new ListNode<T>(d);

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
    ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d) {
    ListNode<T> *node = new ListNode<T>(d);

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
T DoublyLinkedList<T>::removeFront() {
    ListNode<T> *node = front;

    //Only Node in List
    if(front->next == NULL) {
        back = NULL;
    }
    //More than One
    else {
        front->next->prev = NULL;
        front = front->next;
    }

    T temp = node->data;
    node->next = NULL;
    delete node;
    --size;
    return temp;
}

template <class T>
T DoublyLinkedList<T>::removeBack() {
  ListNode<T> *node = back;

  //Only Node in List
  if(back->prev == NULL) {
      front = NULL;
  }
  //More than One
  else {
      back->prev->next = NULL;
      back = back->prev;
  }

  T temp = node->data;
  node->prev = NULL;
  delete node;
  --size;
  return temp;
}

template<class T>
T DoublyLinkedList<T>::peekFront() {
  return front->data;
}

template <class T>
T DoublyLinkedList<T>::peekBack() {
  return back->data;
}

template <class T>
bool DoublyLinkedList<T>::find(T d) {
  ListNode<T> *node = front;

  while(node != NULL) {
    if(node->data == d) {
      return true;
    }
    else {
      node = node->next;
    }
  }

  return false;
}

template <class T>
bool DoublyLinkedList<T>::remove(T d) {
    ListNode<T> *curr = front;

    while (curr != NULL) {
      if (curr->data == d) {
        if(curr == front) {
          removeFront();
          return true;
        }
        else if(curr == back) {
          removeBack();
          return true;
        }
        else {
          curr->prev->next = curr->next;
          curr->next->prev = curr->prev;
          delete curr;
          --size;
          return true;
        }
      }
      curr = curr->next;
    }
    return false;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() {
  return(size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize() {
  return size;
}
