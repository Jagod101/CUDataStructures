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
        int pos;

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
    if(root == NULL) {
        return false;
    }
}

template <class T>
int BST<T>::erase(int pos) {
    if(root == NULL) {
        return false;
    }
}

template <class T>
BST<T>::begin() {
    
}

template <class T>
BST<T>::end() {
    
}