/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "Student.h"
#include "Faculty.h"
#ifndef included
#define included

using namespace std;

template <class T>
class TreeNode {
  private:

  public:
    int key;
    T* data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode();
    TreeNode(T* d, int k);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode() {
  key = -1;
  data = T();
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T* d, int k) {
  key = k;
  data = d;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode() {
  delete data;
  delete left;
  delete right;
}

//<-------------------------------BST Class-------------------------------->
template <class T>
class BST {
  private:
    TreeNode<T> *root;
    int size;

  public:
    BST();
    virtual ~BST();

    bool contains(T k); //Checks if Contains
    T* find(T k); //Find (same as Contain but different return type)
    void put(TreeNode<T> *node); //Insert

    TreeNode<T>* getSuccessor(TreeNode<T> *d); //TreeNode *d represents the node we are deleting
    bool erase(T k); //Delete

    T* getMin();
    T* getMax();

    void printRecursive(TreeNode<T> *node);
    void printTree();

    TreeNode<T>* getRoot();
    int getSize();
    bool isEmpty();
  };

  template <class T>
  BST<T>::BST() {
    root = NULL;
    size = 0;
  }

  template <class T>
  BST<T>::~BST() {

  }

  template <class T>
  bool BST<T>::contains(T k) {
    if(root == NULL) {
      return false;
    }

    TreeNode<T> *curr = root;

    while(curr->key != k) {
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

  template <class T>
  T* BST<T>::find(T k) {
    if(root == NULL) {
      return NULL;
    }

    if(contains(k)) {
      TreeNode<T> *curr = root;

      while(curr->key != k) {
        if(k < curr->key) {
          curr = curr->left;
        }
        else {
          curr = curr->right;
        }

        if(curr == NULL) {
          return T();
        }
      }
      return curr->data;
    }
    else {
      return NULL;
    }
  }

  template <class T>
  void BST<T>::put(TreeNode<T> *node) {
    if(root == NULL) {
      root = node;
    }
    else {
      TreeNode<T> *curr = root;
      TreeNode<T> *parent;

      while(true) {
        parent = curr;
        if(node->key < curr->key) {
          curr = curr->left;
          if(curr == NULL) {
              parent->left = node;
              break;
          }
        }
        else {
          if(node->key > curr->key) {
            curr = curr->right;
            if(curr == NULL) {
              parent->right = node;
              break;
            }
          }
        }
      }
    }
    ++size;
  }

  template <class T>
  TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *curr = d->right;

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
  bool BST<T>::erase(T k) {
    if(root == NULL) {
        return false;
    }

    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(curr->key != k) {
      parent = curr;

      if(k < curr->key) {
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
      TreeNode<T> *successor = getSuccessor(curr);

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
    --size;
    return true;
  }

  template <class T>
  T* BST<T>::getMin() {
    TreeNode<T> *curr = root; //Start at root

    if(root == NULL) {
      return NULL;
    }

    while(curr->left != NULL) {
      curr = curr->left;
    }

    return curr;
  }

  template <class T>
  T* BST<T>::getMax() {
    TreeNode<T> *curr = root;

    if(root == NULL) {
      return NULL;
    }

    while(curr->right != NULL) {
      curr = curr->right;
    }

    return curr;
  }

  template <class T>
  void BST<T>::printRecursive(TreeNode<T> *node) {
    if(node == NULL) {
      return;
    }

    printRecursive(node->left);
    cout << node->key << endl;
    printRecursive(node->right);
  }


  template <class T>
  void BST<T>::printTree() {
    printRecursive(root);
  }

  template <class T>
  TreeNode<T>* BST<T>::getRoot() {
    return root;
  }

  template <class T>
  int BST<T>::getSize() {
    return size;
  }

  template <class T>
  bool BST<T>::isEmpty() {
    return(size == 0);
  }

#endif
