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