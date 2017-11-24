/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include <time.h>
#include "studentRecords.h"
#include "facultyRecords.h"
#include "Menu.h"

using namespace std;

Menu::Menu() {
  struct stat buffer;

  //Check for studentTable, if the file exists load it
  if(stat(studentTable.c_str(), &buffer) == 0) {
    studentBST.loadFile(studentTable);
  }
  //Check for facultyTable, if the file exists load it
  if(stat(facultyTable.c_str(), &buffer) == 0) {
    facultyBST.loadFile(facultyTable);
  }
}

Menu::~Menu() {

}

void Menu::printMenu() {
  int input;
  bool running = true;

  while (running) {
    cout << "\n****************** MENU ******************" << endl;
    cout << 1 << ".  Print (all) Student Info (by ascending ID)" << endl;
    cout << 2 << ".  Print (all) Faculty Info (by ascending ID)" << endl;
    cout << 3 << ".  Print Student Info (by student ID)" << endl;
    cout << 4 << ".  Print Faculty Info (by faculty ID)" << endl;
    cout << 5 << ".  Print Advisor Info (by student ID)" << endl;
    cout << 6 << ".  Print Advisee Info (by faculty ID)" << endl;
    cout << 7 << ".  Add New Student" << endl;
    cout << 8 << ".  Delete Student (by student ID)" << endl;
    cout << 9 << ".  Add New Faculty" << endl;
    cout << 10 << ". Delete Faculty (by faculty ID)" << endl;
    cout << 11 << ". Change Advisor (by student ID and faculty ID)" << endl;
    cout << 12 << ". Remove Advisee (by student ID and faculty ID)" << endl;
    cout << 13 << ". Rollback" << endl;
    cout << 14 << ". Exit" << endl;
    cout << "\nPlease Select a Menu Option: ";

    try {
      cin >> atoi(input);

      if(input < 0 || input > 14) {
        cout << "Glitch Within the Matrix - Please Enter a Valid Menu Option \n" << endl;
        input = 15;
      }
    }
    catch(exception e) {
      cout << "Glitch Within the Matrix - Please Enter a Valid Menu Option \n" << endl;
      input = 15;
    }

    switch(input) {
      case 1:
        printAllStudents();
        break;
      case 2:
        printAllFaculty();
        break;
      case 3:
        printStudent();
        break;
      case 4:
        printFaculty();
        break;
      case 5:
        printAdvisor();
        break;
      case 6:
        printAdvisee();
        break;
      case 7:
        addStudent();
        break;
      case 8:
        deleteStudent();
        break;
      case 9:
        addFaculty();
        break;
      case 10:
        deleteFaculty();
        break;
      case 11:
        changeAdvisor();
        break;
      case 12:
        removeAdvisee();
        break;
      case 13:
        rollback();
        break;
      case 14:
        exit();
        return;
      default:
        continue;
    }
  }
}

void Menu::printAllStudents() {
  //go through the tree printing all the students IN ORDER
  if(studentBST.isEmpty()) {
    cout << "Student Tree is Empty" << endl;
  }
  else {
    studentBST.printTree();
  }
}

void Menu::printAllFaculty() {
  //go through the tree printing all the faculty IN ORDER
  if(facultyBST.isEmpty()) {
    cout << "Faculty Tree is Empty" << endl;
  }
  else {
    facultyBST.printTree();
  }
}

void Menu::printStudent() {
  int srID = 0;

  if(studentBST.isEmpty()) {
    cout << "Student Tree is Empty" << endl;
  }
  else {
    cout << "What student would you like to look for? (Give an ID number)" << endl;
    cin >> srID;

    StudentRecords sr(srID);

    if(studentBST.contains(sr)) {
      studentBST.printNode(sr);
    }
    else {
      cout << "Student Tree Does NOT Contain Student ID: " << srID << endl;
    }
  }
}

void Menu::printFaculty() {
  int frID = 0;

  if(facultyBST.isEmpty()) {
    cout << "Faculty Tree is Empty" << endl;
  }
  else {
    cout << "What faculty member would you like to look for? (Give an id number)" << endl;
    cin >> frID;

    FacultyRecords fr(frID);

    if(facultyBST.contains(fr)) {
      facultyBST.printNode(fr);
    }
    else {
      cout << "Faculty Tree Does NOT Contain Faculty ID: " << frID << endl;
    }
  }
}

void Menu::printAdvisor() {
  int srID = 0;

  if(studentBST.isEmpty()) {
    cout << "Student Tree is Empty" << endl;
  }
  else {
    cout << "Please Provide a Student ID: ";
    cin >> srID;

    StudentRecords sr(srID);
    StudentRecords value = studentBST.find(sr);

    if(value.id >= 0) {
      FacultyRecords fr(value.advisorID);

      if(facultyBST.find(fr)) {
        facultyBST.printNode(fr);
      }
      else {
        cout << "Faculty Tree Does NOT Contain Faculty ID: " << fr << endl;
      }
    }
    else {
      cout << "Student ID: " << srID << " Not Found" << endl;
    }
  }
}

void Menu::printAdvisee() {
  int frID = 0;

  if(facultyBST.isEmpty()) {
    cout << "Faculty Tree is Empty" << endl;
  }
  else {
    cout << "Please Provide a Faculty ID: ";
    cin >> frID;

    FacultyRecords fr(frID);
    FacultyRecords value = facultyBST.find(fr);

    if(value.id >= 0) {
      ListNode<int> *node = value.adviseeID->front;

      if(node == NULL) {
        cout << value.name << " Has No Advisees" << endl;
      }
      else {
        while(true) {
          StudentRecords sr;
          sr.id = node->data;

          StudentRecords student = studentBST.find(sr);
          cout << student.id << " | " << student.name << " | " << student.grade << " | " << student.major << " | " << student.gpa << endl;

          if(node->next != NULL) {
            node = node->next;
          }
          else {
            break;
          }
        }
      }
    }
    else {
      cout << "Faculty ID: " << frID << " Not Found" << endl;
    }
  }
}

void Menu::addStudent() {
  //Generate Student ID
  goodID = false;
  srand(time(NULL));
  int srID = rand() % 4000 + 1000; // will generate a number between 1000 and 4999

  while(goodID == false){
    if (studentBST.contains(srID) == false){
        goodID = true;
    } else {
        int srID = rand() % 4000 + 1000;
        goodID = false;
    }
  }

  cout << "Student's ID: " << srID << endl;

  string name;
  cout << "What is this student's name? ";
  cin >> name;

  string grade;
  cout << "\nWhat is this student's grade level? ";
  cin >> grade;

  string major;
  cout << "\nWhat is this student's major? ";
  cin >> major;

  double gpa;
  cout << "\nWhat is this student's GPA? ";
  cin >> gpa;

  int advisorID;
  cout << "\nWhat is this student's advisor's ID? (If unknown leave blank. Hit enter.) ";
  cin >> advisorID;

  //If Blank Input No Advisor Set, Default to 0
  if(advisorID.isEmpty()) {
    advisorID = -1;
  }

  FacultyRecords fr(advisorID);

  bool checkAdvisor = false;

  while(checkAdvisor = false) {
    if(advisorID == -1) {
      cout << "It appears you didn't enter an ID, try picking from the list of Faculty below: " << endl;
      printAllFaculty();
      cout << "What is this student's advisor's ID? ";
      cin >> advisorID;
      FacultyRecords fr(advisorID);
    }
    else if(!facultyBST.contains(fr)) {
      cout << "\nFaculty ID: " << advisorID << " Does Not Exist" << endl;
      cout << "What is this student's advisor's ID? ";
      cin >> advisorID;
      FacultyRecords fr(advisorID);
    }
    else {
      checkAdvisor = true;
    }
  }

  StudentRecords sr(id, name, grade, major, gpa, advisorID);
  studentBST.put(sr);


  //record within facultyRecords to their new advisor

}

void Menu::deleteStudent() {

  int srID = 0;
  foundStudent = false;

  while(foundStudent == false){
    if(studentBST.isEmpty()) {
      cout << "Student Tree is Empty" << endl;
      return;
    }
    else {
      cout << "What student would you like to look for? (Give an ID number) ";
      cin >> srID;

      StudentRecords sr(srID);

      if(studentBST.contains(sr)) {

        FacultyRecords fr;

        foundStudent = true;

      }
      else {
        cout << "Student ID: " << srID << " Does Not Exist. Try a new ID." << endl;
      }
    }

    studentBST.erase(id);

    //delete the student from the facultyRecords
  }
}

void Menu::addFaculty() {

  string answer = "";
  bool anotherStudent = true;
  int srID;

  //Generate Faculty ID
  goodID = false;
  srand(time(NULL));
  int frID = rand() % 5000 + 5000; // will generate a number between 5000 and 9999

  while(goodID == false){
    if (facultyBST.contains(frID) == false){
        goodID = true;
    } else {
        int frID = rand() % 5000 + 5000;
        goodID = false;
    }
  }

  cout << "New Faculty ID: " << frID;

  cout << "\nWhat is this faculty member's name? ";
  cin >> name;

  cout << "\nWhat is this faculty member's level? (lecturer, assistant prof, associate prof, etc...) ";
  cin >> level;

  cout << "\nWhat is this faculty member's department? ";
  cin >> department;

  FacultyRecords fr(id, name, level, department);

  while(anotherStudent == true){
    cout << "You are about to TRANSFER a Student to this NEW Advisor" << endl;
    cout << "Here is a list of Faculty Members: " << endl;

    printAllFaculty();
    printAdvisee();

    cout << "What is the ID of the student you would like to transfer? " << endl;
    cin >> srID;

    StudentRecords sr(srID);
    StudentRecords value = studentBST.find(sr);
    FacultyRecords oldfrID(value.advisorID);

    studentBST.replaceAdvisor(sr);
    facultyBST.removeAdviseeID(oldfrID, srID);
    facultyBST.addAdvisee(frID, srID);

    cout << "Would you like to move another student to this new advisor? (yes or no)" << endl;
    cin >> answer;

    if(answer == "yes" || answer == "Yes"){
      continue;
    } else if (answer == "no" || answer == "No"){
      anotherStudent = false;
    } else {
      cout << "Please enter either yes or no" << endl;
    }
  }
  facultyBST.put(fr);
}

void Menu::deleteFaculty() {

  int id = 0;

  cout << "What student would you like to look for? (Give an id number)" << endl;
  cin >> id;

  facultyBST.erase(id);

  //this might have to change bc we might have to create a copy of their records before
  //they are deleted so that we can have all their advisee's to shift

  //shift the students to new advisers
  //record changes in studentRecords

}

void Menu::changeAdvisor() {
  int srID = 0;
  int frID = 0;

  if(studentBST.isEmpty()) {
    cout << "Student Tree is Empty" << endl;
    return;
  }
  else {
    cout << "What is the student's ID: ";
    cin >> srID;

    StudentRecords sr(srID);
    StudentRecords value = studentBST.find(sr);
    FacultyRecords oldfrID(value.advisorID);

    cout << "Here is a list of Faculty Members: " << endl;
    printAllFaculty();

    cout << "What is the new Faculty ID: ";
    cin >> frID;

    FacultyRecords newfrID(frID);

    if(facultyBST.contains(newfrID)) {
      sr.advisorID = frID;
      studentBST.replaceAdvisor(sr);
      facultyBST.replaceAdvisee(oldfrID, newfrID, srID);
    }
    else {
      cout << "Faculty ID: " << frID << " Does Not Exist" << endl;
    }
  }

}

void Menu::removeAdvisee() {
  int srID = 0;
  int frID = 0;
  bool idIsWrong = true;

  if(facultyBST.isEmpty()) {
    cout << "Faculty Tree is Empty" << endl;
    return;
  }

  cout << "\nWhat is the ID of the student you would like to remove?: ";
  cin >> srID;

  cout << "\nWhat is the ID of that students advisor?: ";
  cin >> frID;

  while(idIsWrong == true){
    StudentRecords sr(srID);
    studentRecords s_value = studentBST.find(sr);
    FacultyRecords f_value(s_value.advisorID);

    if (frID != f_value){
      cout << "\nThat advisor is not the advisor to the student you entered. Enter a different ID number: ";
      cin >> frID;
    } else {
      idIsWrong = false;
    }
  }

  facultyBST.removeAdviseeID(frID, srID);

  cout << "Choose a new Advisor for this student" << endl;
  printAllFaculty();

  cout << "What is the new Advisor's ID: ";
  cin >> frID;

  FacultyRecords newfrID(frID);

  if(facultyBST.contains(newfrID)) {
    sr.advisorID = frID;
    studentBST.replaceAdvisor(sr);
    facultyBST.replaceAdvisee(oldfrID, newfrID, srID);
  }
  else {
    cout << "Faculty ID: " << frID << " Does Not Exist" << endl;
  }
}

void Menu::rollback() {

  //this will apply to undoing the following methods:
  //addStudent, addFaculty, deleteStudent, deleteFaculty, changeAdvisor, removeAdvisee
  //STACK no greater than 5 (5 versions of previous trees, ALL trees)
  //All five times within Rollback
  //Clear the stack after fifth time

}

void Menu::exit() {
  cout << "EXITING PROGRAM..." << endl;
}
