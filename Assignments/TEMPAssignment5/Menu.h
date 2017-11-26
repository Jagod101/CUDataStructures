/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <sstream>
#include "BST.h"
#include "GenStack.h"

using namespace std;

class Menu {
  private:

  public:
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;

    //GenStack<Student> studentStack;
    //GenStack<Faculty> facultyStack;

    Menu();
    ~Menu();

    void readFile();
    void writeFile();

    void printMS(TreeNode<Student> *s);
    void printMF(TreeNode<Faculty> *f);

    void outputMS(TreeNode<Student> *s, string student);
    void outputMF(TreeNode<Faculty> *f, string faculty);

    TreeNode<Student>* getMSRoot();
    TreeNode<Faculty>* getMFRoot();

    void printMenu();
    void printAllStudents();
    void printAllFaculty();
    void printStudent();
    void printFaculty();
    void printAdvisor();
    void printAdvisee();

    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeAdvisor();
    void removeAdvisee();

    void rollback();

    void exit();
};
