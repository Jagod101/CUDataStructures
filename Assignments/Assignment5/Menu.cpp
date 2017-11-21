/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::printMenu() {
  int input;
  bool running = true;

  while (running) {
    cout << "<----------------- MENU ------------------>" << endl;
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
    cout << "\n" << "Please Select a Menu Option: ";

    cin >> input;

    if(!cin || input < 0 || input > 14) {
      cout << "Glitch Within the Matrix - Please Enter a Valid Menu Option \n" << endl;
      input = 0;
      continue;
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

  //go through the tree printing all the students in order

}

void Menu::printAllFaculty() {

  //go through the tree printing all the faculty in order

}

void Menu::printStudent() {

  //find student in tree
  //print their records from studentRecords

}

void Menu::printFaculty() {

  //find faculty member in tree
  //print their records from faculty facultyRecords

}

void Menu::printAdvisor() {

  //find faculty member in tree
  //print all their advisee's records from studentRecords

}

void Menu::printAdvisee() {

  //find student in the tree
  //print all their advisor's records from facultyRecords

}

void Menu::addStudent() {

  //add the student to the tree
  //record within studentRecords their new id NUMBER
  //record within studentRecords their faculty member

}

void Menu::deleteStudent() {

  //go into the tree
  //find the id NUMBER
  //delete the student from the tree and the facultyRecords

}

void Menu::addFaculty() {

  //add the faculty member to the tree
  //shift some students to the new member
  //record within facultyRecords and studentRecords these changes

}

void Menu::deleteFaculty() {

  //go into the tree
  //find the id NUMBER
  //delete the faculty member from the tree
  //shift the students to new advisers
  //record changes in studentRecords

}

void Menu::changeAdvisor() {

  //find the students id
  //go into records for that student and shift info to new Advisor
  //go into tree and move the student to new Advisor

}

void Menu::removeAdvisee() {

  //go into tree
  //find the student and move them to new advisor
  //change the records in studentRecords and facultyRecords

}

void Menu::rollback() {

}

void Menu::exit() {
  cout << "EXITING PROGRAM..." << endl;
}
