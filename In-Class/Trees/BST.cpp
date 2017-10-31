#include <iostream>

using namespace std;

template <class T>
class TreeNode {
    private:

    public:
        int key;
        int value;
        int pos;

        TreeNode *left;
        TreeNode *right;

        TreeNode();
        TreeNode(int key, int value, int pos);
        ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode() {

}

template <class T>
TreeNode<T>::TreeNode(int k, int v, int p) {
    key = k;
    value = v;
    pos = p;
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode() {

}

template <class T>
class BST {
    private:
        TreeNode *root;

    public:
        BST(); //Constructor
        ~BST(); //Destructor

        int find(int key);
        int put(int key, int value);
        int erase(int key);
        int erase(int pos);

        void begin();
        void end();
};

template <class T>
BST<T>::BST() {
    root = NULL;
}

template <class T>
BST<T>::~BST() {

}

template <class T>
int BST<T>::find(int k) {
    TreeNode *curr = root;

    if(root == NULL) {
        return false;
    }
    else {
        while(curr->key != NULL) {
            if(k < curr->key) {
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
int BST<T>::put(int key, int value) {
    TreeNode *node = new TreeNode(key, value);

    TreeNode *curr = root;
    TreeNode *parent;

    if(root == NULL) {
        root = node;
    }
    else {
        while(true) {
            parent = curr;
            if(value < parent->key) {
                curr = curr->left;
                if(curr == NULL) {
                    parent->left = node;
                    break;
                }
            }
            else {
                curr = curr->right;
                if(curr == NULL) {
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class T>
int BST<T>::erase(int key) {
    
}

template <class T>
int BST<T>::erase(int pos) {
    
}

template <class T>
BST<T>::begin() {
    
}

template <class T>
BST<T>::end() {
    
}