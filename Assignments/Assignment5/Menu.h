/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include "BST.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

const string studentTable = "studentTable";
const string facultyTable = "facultyTable";

class Menu {
  private:
    sTable studentBST;
    fTable facultyBST;

  public:
    Menu();
    ~Menu();

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
