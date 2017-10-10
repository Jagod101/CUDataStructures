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

    public:
        NaiveList(); //Constructor
        ~NaiveList(); //Destructor

        void insertFront(int data); //Insert at the Front ONLY
        void printList(); //Prints Contents of LinkedList
        int removeFront(); //Remove at the Front ONLY
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