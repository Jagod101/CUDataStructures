/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include "Faculty.h"

using namespace std;

Faculty::Faculty() {

}

Faculty::~Faculty() {
  delete []adviseeArray;
}

Faculty::Faculty(int ID_, string name_, string level_, string department_) {
  ID = ID_;
  name = name_;
  level = level_;
  department = department_;

  adviseeArray = new int[5];
  numAdvisee = 0;
  maxSize = 5;

  for(int i = 0; i < 5; ++i) {
    adviseeArray[i] = -1;
  }
}

void Faculty::printFaculty() {
  cout << "Faculty ID:  " << id << ", ";
  cout << "Faculty Name: " << name << ", ";
  cout << "Level: " << level << ", ";
  cout << "Department: " << department << ", ";
  printAdvisee();
  cout << endl;
}

void Faculty::printAdvisee() {
  if(numAdvisee == 0) {
    cout << "None";
  }
  else {
    
  }
}

string Faculty::getDepartment() {
  return department;
}

void Faculty::getAdviseeID() {
  return numAdvisee;
}

void Faculty::addAdvisee(int ID) {

}

bool Faculty::removeAdvisee(int adviseeID) {

}

int Faculty::getSizeArray() {
  return maxSize;
}
