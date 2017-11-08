#include <iostream>

using namespace std;

template <class T>
class TreeNode {
    private:

    public:
        T value;
        T key; //Key can be Value

        TreeNode *left;
        TreeNode *right;

        TreeNode();
        TreeNode(T key, T value);
        virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode() {
    key = 0;
    value = 0;
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, int v) {
    key = k;
    value = v;
    left = NULL;
    right = NULL;
}

template <class T>
virtual TreeNode<T>::~TreeNode() {
    //Build some character
}

template <class T>
class BST {
    private:
        TreeNode *root;

    public:
        BST(); //Constructor
        virtual ~BST(); //Destructor

        bool find(int value); //Contains
        void put(int value); //Insert
        bool erase(int value); //Delete

        TreeNode* getMin();
        TreeNode* getMax();
        TreeNode* getSuccessor(TreeNode *d); //TreeNode *d represents the node we are deleting

        void printTree();
        bool isEmpty();
};

template <class T>
BST<T>::BST() {
    root = NULL;
}

template <class T>
virtual BST<T>::~BST() {
    //Build character Once Again
    //Iterate and Delete
}

template <class T>
bool BST<T>::find(int value) {
    if(root == NULL) {
        return false;
    }
    else {
        TreeNode *curr = root;

        while(curr->key != value) {
            if(value < curr->key) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }

            if(curr == NULL) {
                return false;
            }
        }
        return true;
    }
}

template <class T>
void BST<T>::put(int value) {
    TreeNode *node = new TreeNode(value);

    if(root == NULL) {
        root = node;
    }
    else {
        TreeNode *curr = root;
        TreeNode *parent;

        while(true) {
            parent = curr;
            if(value < curr->key) {
                curr = curr->left;
                if(curr == NULL) {
                    parent->left = node;
                    break;
                }
            }
            else {
                if (value > curr->key) {
                    curr = curr->right;
                    if(curr == NULL) {
                        parent->right = node;
                        break;
                    }
                }
            }
        }
    }
}

template <class T>
bool BST<T>::erase(int value) {
    if(root == NULL) {
        return false;
    }

    TreeNode *curr = root;
    TreeNode *parent = root;
    bool isLeft = true;
    
    while(curr->key != value) {
        parent = curr;

        if(value < curr->key) {
            isLeft = true;
            curr = curr->left;
        }
        else {
            isLeft = false;
            curr = curr->right;
        }

        if(curr == NULL) {
            return false;
        }
    }
    //We have found the node we want to delete

    //Delete a Node with No Children
    if(curr->left == NULL && curr->right == NULL) {
        if(curr == root) {
            root = NULL;
        }
        else if(isLeft) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
    }
    //One Child (to the Left)
    else if(curr->right == NULL) {
        if(curr == root) {
            root = curr->left;
        }
        else if(isLeft) {
            parent->left = curr->left;
        }
        else {
            parent->right = curr->right;
        }
    }
    //One Child (to the Right)
    else if(curr->left == NULL) {
        if(curr == root) {
            root = curr->right;
        }
        else if(isLeft) {
            parent->left = curr->right;
        }
        else {
            parent->right = curr->right;
        }
    }
    //Two Children
    else {
        TreeNode *successor = getSuccessor(curr);

        if(curr == root) {
            root = successor;
        }
        else if(isLeft) {
            parent->left = successor;
        }
        else {
            parent->right = successor;
        }
        successor->left = curr->left;
    }
    return true;
}

template <class T>
TreeNode* BST<T>::getMin() {
    TreeNode* curr = root; //Start at root

    if(root == NULL) {
        return NULL;
    }

    while(curr->left != NULL) {
        curr = curr->left;
    }

    return curr;
}

template <class T>
TreeNode* BST<T>::getMax() {
    TreeNode* curr = root;

    if(root == NULL) {
        return NULL;
    }

    while(curr->right != NULL) {
        curr = curr->right;
    }

    return curr;
}

template <class T>
TreeNode* BST<T>::getSuccessor(TreeNode *d) {
    TreeNode *sp = d;
    TreeNode *successor = d;
    TreeNode *curr = d->right;

    while(curr != NULL) {
        sp = successor;
        successor = curr;
        curr = curr->left;
    }

    if(successor != d->right) {
        sp->left = successor->right;
        successor->right = d->right;
    }

    return successor;
}

template <class T>
void BST<T>::printTree() {

}