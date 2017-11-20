/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>

template <class T>
class BST {
  private:
    TreeNode<T> *root;
  public:
    BST();
    virtual ~BST();

    T find(T value); //Contains
    void put(T value); //Insert
    bool erase(T value); //Delete

    TreeNode<T>* getMin();
    TreeNode<T>* getMax();
    TreeNode<T>* getSuccessor(TreeNode<T> *d); //TreeNode *d represents the node we are deleting

    void printTree();
    void printNode(T value);
    bool isEmpty();
};

template <class T>
BST<T>::BST() {
  root = NULL;
}

template <class T>
virtual BST<T>::~BST() {
  delete root;
}

template <class T>
T BST<T>::find(T value) {
  if(root == NULL) {
    return false;
  }
  else {
    TreeNode<T> *curr = root;

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
void BST<T>::put(T value) {
  TreeNode<T> *node = new TreeNode<T>(value);

  if(root == NULL) {
    root = node;
  }
  else {
    TreeNode<T> *curr = root;
    TreeNode<T> *parent;

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
bool BST<T>::erase(T value) {
  if(root == NULL) {
      return false;
  }

  TreeNode<T> *curr = root;
  TreeNode<T> *parent = root;
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
  return true;
}

template <class T>
TreeNode<T>* BST<T>::getMin() {
  TreeNode<T>* curr = root; //Start at root

  if(root == NULL) {
    return NULL;
  }

  while(curr->left != NULL) {
    curr = curr->left;
  }

  return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMax() {
  TreeNode<T>* curr = root;

  if(root == NULL) {
    return NULL;
  }

  while(curr->right != NULL) {
    curr = curr->right;
  }

  return curr;
}
