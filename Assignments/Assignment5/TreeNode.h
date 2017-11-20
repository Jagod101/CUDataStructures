/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>

using namespace std;

template <class T>
class TreeNode {
  private:

  public:
    T key; //Key can be Value, vice-versa

    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode();
    TreeNode(T key);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode() {
  key = 0;
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
virtual TreeNode<T>::~TreeNode() {
  delete left;
  delete right;
}
