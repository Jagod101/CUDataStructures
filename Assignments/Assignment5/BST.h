/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include <fstream>
#include "studentRecords.h"
#include "facultyRecords.h"

using namespace std;

//<-----------------------------TreeNode Class------------------------------->
template <class T>
class TreeNode {
  private:

  public:
    T key;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode();
    TreeNode(T key);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode() {
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k) {
  key = k;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode() {
  delete left;
  delete right;
}

//<-------------------------------BST Class-------------------------------->
template <class T>
class BST {
  private:
    TreeNode<T> *root;

  public:
    BST();
    virtual ~BST();

    bool contains(T value); //Checks if Contains
    T find(T value); //Find (same as Contain but different return type)
    void put(T value); //Insert
    bool erase(T k); //Delete

    T* getMin();
    T* getMax();
    TreeNode<T>* getSuccessor(TreeNode<T> *d); //TreeNode *d represents the node we are deleting

    void printNode(T value);
    void printRecursive(TreeNode<T> *node);
    void printTree();

    bool isEmpty();

    void serializeRecursive(ofstream &output, TreeNode<T> *node);

    void loadFile(string file);
    void writeFile(string file);
};

template <class T>
BST<T>::BST() {
  root = NULL;
}

template <class T>
BST<T>::~BST() {
  delete root;
}

template <class T>
bool BST<T>::contains(T value) {
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
T BST<T>::find(T value) {
  if(root == NULL) {
    return T();
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
        return T();
      }
    }
    return curr->key;
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
bool BST<T>::erase(T k) {
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
void BST<T>::printNode(T value) {
  if(root == NULL) {
    cout << "Node Not Found" << endl;
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
        cout << "Node Not Found" << endl;
      }
    }
    cout << curr->key;
  }
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
bool BST<T>::isEmpty() {
  return(root == NULL);
}

template <class T>
void BST<T>::serializeRecursive(ofstream &output, TreeNode<T> *node) {
  if(node == NULL) {
    return;
  }

  output << node->key.serialize() << endl;
  serializeRecursive(output, node->left);
  serializeRecursive(output, node->right);
}

template <class T>
void BST<T>::loadFile(string file) {
  ifstream input;
  string value;

  input.open(file.c_str());

  while(getline(input, value)) {
    T node = T(value);
    put(node);
  }

  input.close();
}

template <class T>
void BST<T>::writeFile(string file) {
  ofstream output;
  output.open(file.c_str(), ofstream::out | ofstream::trunc);
  serializeRecursive(output, root);
  output.close();
}

//<-----------------------------sTable Class------------------------------->
class sTable : public BST<StudentRecords> {
  private:

  public:
    bool replaceAdvisor(StudentRecords value) {
      if(root == NULL) {
        return false;
      }
      else {
        TreeNode<StudentRecords> *curr = root;

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

        curr->key.advisorID = value.advisorID;
        return true;
      }
    }
};

//<-----------------------------fTable Class------------------------------->
class fTable : public BST<FacultyRecords> {
  private:

  public:
    bool removeAdviseeID(FacultyRecords value, int adviseeID) {
      if(root == NULL) {
        return false;
      }
      else {
        TreeNode<FacultyRecords> *curr = root;

        while(curr->key != val) {
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

        curr->key.removeAdviseeID(adviseeID);
        }
      }
    }

    bool replaceAdvisee(FacultyRecords oldfrID, FacultyRecords newfrID, int srID) {
      if(root == NULL) {
        return false;
      }
      else {
        TreeNode<FacultyRecords> *curr = root;

        while(curr->key != oldfrID) {
          if(oldfrID < curr->key) {
            curr = curr->left;
          }
          else {
            curr = curr->right;
          }

          if(curr == NULL) {
            return false;
          }
        }

        curr->key.removeAdviseeID(srID);
        curr = root;

        while(curr->key != newfrID) {
          if(newfrID < curr->key) {
            curr = curr->left;
          }
          else {
            curr = curr->right;
          }

          if(curr == NULL) {
            return false;
          }
        }
        curr->key.addAdvisee(srID);
      }
    }

    void removeStudent(TreeNode<FacultyRecords> *node, int srID) {
      bool running = false;

      if(!running) {
        if(node == NULL) {
          return;
        }

        printRecursive(node->left);
        if(node->key.containsAdvisee(srID)) {
          running = true;
          cout << "Student with ID: " << srID << " is an Advisee (Remove Advisor)" << endl;
        }
        printRecursive(node->right);
      }
      else {
        return;
      }
    }
};
