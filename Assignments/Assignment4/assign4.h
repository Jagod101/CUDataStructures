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

//<--------------------WINDOWS----------------------->
template <class T>
class Windows {
    private:

    public:
        Windows(); //Constructor
        ~Windows();

        int windowData();
};

template <class T>
Windows<T>::Windows() {

}

template <class T>
Windows<T>::~Windows() {

}

template <class T>
int Windows<T>::windowData() {

    bool window[windowSize] = {true};

}
/*
Number of Windows stored in an Array
Boolean Array --> isOpen = true when no student at Window, isOpen = false when student is at Window
*/

//<-------------------STUDENTS----------------------->
template <class T>
class Students {
    private:

    public:
        Students();
        ~Students();

        int studentData();
        int meanTime();
        int medianTime();
        int longTime();
        int overTenTime();
};

template <class T>
Students<T>::Students() {

}

template <class T>
Students<T>::~Students() {
    
}

template <class T>
int Students<T>::studentData() {
    numStudents = new Array[studentSize];
    timeForStudents = new Array[studentTime];
}

template <class T>
int Students<T>::meanTime() {

}

template <class T>
int Students<T>::medianTime() {

}

template <class T>
int Student<T>::longTime() {

}

template <class T>
int Student<T>::overTenTime() {

}


//<--------------IMPORT SETTINGS--------------------->
template <class T>
class ImportSettings {
    private:

    public:
        ImportSettings();
        ~ImportSettings();

        int setVariables(string file);

        int timeOnClock = 0;
};

template <class T>
ImportSettings<T>::ImportSettings() {

}

template <class T>
ImportSettings<T>::~ImportSettings() {

}

template <class T>
int ImportSettings<T>::setVariables(string file) {
    string line;
    int lineNum = 1;

    ifstream inputStream;
    inputStream.open(file.c_str());

    while(getline(inputStream, line) != NULL) {        
        if(lineNum == 1) {
            windowSize = int(line);
        }
        else if (lineNum == 2) {
            timeOnClock = int(line);
        }
        else if (lineNum == 3) (
             numStudents = int(line);
        )
        else if (for(i = numStudents; i > 0; --i)) 
        {
        
        lineNum++;
        /*
        <-------------------FIGURE THIS SHIT OUT------------------->
        1) FIRST LINE = Number of Windows
        2) SECOND LINE = Time on Clock
        3) THIRD LINE = Number of Students (store in an Array)
        4) NEXT LINE(S) = Amount of Time for each Student (in respective order)
        5) NEXT LINE = New Time on Clock
        6) FOLLOWING LINE = New Number of Students
        7) CONSEQUENTIAL LINE(S) = Amount of Time for each Student (respectively)
        */
    }
}