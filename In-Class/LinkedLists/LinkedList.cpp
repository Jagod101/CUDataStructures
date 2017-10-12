#include <iostream>

class ListNode {
    public:
        int data;
        ListNode *next;

        ListNode(); //Constructor
        ListNode(int data);
        ~ListNode(); //Destructor
};

ListNode::ListNode() {

}

ListNode::ListNode(int d) {
    data = d;
    next = NULL;
}

ListNode::~ListNode() {
    if(next != NULL) {
        delete next;
    }
}

class NaiveList {
    private: 
        unsigned int size; //Not going to be Negative
        ListNode *front;
        ListNode *back;

    public:
        NaiveList(); //Constructor
        ~NaiveList(); //Destructor

        void insertFront(int data); //Insert at the Front ONLY
        void insertBack(int d);
        int removeFront(); //Remove at the Front ONLY
        void printList(); //Prints Contents of LinkedList
        int deletePos(int pos); //Remove at Specified Position
        int find(int value); //Find Value within LinkedList

        unsigned int getSize();
        bool isEmpty(); //Checks to see if Empty
};

NaiveList::NaiveList() {

}

NaiveList::~NaiveList() {

}

void NaiveList::insertFront(int data) {
    ++size; //Increase size of LinkedList
    ListNode *node = new ListNode(data); //Creates a new Node

    //Update Pointers so new Node is Front
    node->next = front;
    front = node;
}

void NaiveList::insertBack(int d) {
    ++size;
    ListNode *node = new ListNode(d);

    if(front == NULL) {
        front = back;
    }
    else {
        back->next = node;
        back = node;
    }
}

int NaiveList::removeFront() {
    --size; //Decrement the size

    int temp = front->data; //Temp variable to store value before deletion
    ListNode *ft = front; //Temp front pointer
    front = front->next; //Re-assign front pointer

    ft->next = NULL; //Removes the node
    delete ft; //Deletes the temp pointer
    return temp;
}

void NaiveList::printList() {
    ListNode *curr = front; //To count nodes

    //Iterates through Nodes and prints each out until empty
    while(curr == true) {
        cout << curr->data << endl; //Prints out curr value in ListNode
        curr = curr->next; //Makes curr the next node 
    }
}

void NaiveList::deletePos(int pos) {
    int idx = 0;

    ListNode *curr = front;
    ListNode *prev = front;

    while(idx != pos) {
        prev = curr;
        curr = curr->next;
        ++idx;
    }

    //Found Position, Update Pointers
    prev->next = curr->next;
    curr->next = NULL;
    int d = curr->data;
    delete curr;

    size--;
    return d;
}

void NaiveList::find(int value) {
    int idx = -1; //idx -> index

    ListNode *curr = front;

    while(curr != NULL) { //start searching for the value
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