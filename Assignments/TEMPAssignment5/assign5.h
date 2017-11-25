/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "BST.h"

using namespace std;

class FileProcessing {
  private:

  public:
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;

    FileProcessing();
    ~FileProcessing();

    void readFile();
    void writeFile();

    void printMS(TreeNode<Student> *s);
    void printMF(TreeNode<Faculty> *f);

    void outputMS(TreeNode<Student> *s, string student);
    void outputMF(TreeNode<Faculty> *f, string faculty);
};
