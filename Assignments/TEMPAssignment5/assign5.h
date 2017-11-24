/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
//#include "BST.h"

using namespace std;

class FileProcessing {
  private:
  public:
    BST<StudentRecords> masterStudent;
    BST<FacultyRecords> masterFaculty;

    FileProcessing();
    ~FileProcessing();

    void readFile();
    void writeFile();
}
