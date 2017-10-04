class ListNode {
    public:
        int data;
        ListNode* next;
        ListNode();
        ListNode(int data);
        ~ListNode();
};

ListNode::ListNode(int d) {
    data = d;
    next = NULL;
}

ListNode::~ListNode() {
    if(next != NULL) {
        delete next;
    }
}