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
  bool validInput = true;

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

    if(cin.fail() || input < 0 || input > 14) {
      cout << "Glitch Within the Matrix - Please Enter a Valid Menu Option \n" << endl;
      validInput = false;
      continue;
    }

    while (validInput == true) {
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
}

void Menu::printAllStudents() {

}

void Menu::printAllFaculty() {

}

void Menu::printStudent() {

}

void Menu::printFaculty() {

}

void Menu::printAdvisor() {

}

void Menu::printAdvisee() {

}

void Menu::addStudent() {

}

void Menu::deleteStudent() {

}

void Menu::addFaculty() {

}

void Menu::deleteFaculty() {

}

void Menu::changeAdvisor() {

}

void Menu::removeAdvisee() {

}

void Menu::rollback() {

}

void Menu::exit() {
  cout << "EXITING PROGRAM..." << endl;
}
