#include <iostream>

class ListNode {
    public:
        int data;
        ListNode *next;
        ListNode *prev;

        ListNode(); //Constructor
        ListNode(int data);
        ~ListNode(); //Destructor
};

ListNode::ListNode() {

}

ListNode::ListNode(int d) {
    data = d;
    next = NULL;
    prev = NULL;
}

ListNode::~ListNode() {
    next = NULL;
    prev = NULL;
}

class DoublyLinkedList {
    private: 
        unsigned int size; //Not going to be Negative
        ListNode *front;
        ListNode *back;

    public:
        DoublyLinkedList(); //Constructor
        ~DoublyLinkedList(); //Destructor

        void insertFront(int data); //Insert at the Front ONLY
        void insertBack(int data);

        int removeFront(); //Remove at the Front ONLY
        int removeBack();

        void printList(); //Prints Contents of LinkedList

        int deletePos(int pos); //Remove at Specified Position
        int find(int value); //Find Value within LinkedList

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
    
}

int DoublyLinkedList::removeBack() {

}

void DoublyLinkedList::printList() {
    
}

void DoublyLinkedList::deletePos(int pos) {
    
}

void DoublyLinkedList::find(int value) {
    
}