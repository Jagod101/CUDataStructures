/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include "Student.h"

using namespace std;

Student::Student() {

}

Student::~Student() {

}

Student::Student(int ID_, string name_, string level_, string major_, double gpa_, int advisorID_) {
  ID = ID_;
  name = name_;
  level = level_;
  major = major_;
  gpa = gpa_;
  advisorID = advisorID_;
}

void Student::setAdvisor(int advisorID_) {
  advisorID = advisorID_;
}

int Student::getAdvisor() {
  return advisorID;
}

void Student::printStudent() {
  cout << "Student ID: " << ID << ", ";
  cout << "Student Name: " << name << ", ";
  cout << "Grade: " << grade << ", ";
  cout << "Major: " << major << ", ";
  cout << "GPA: " << gpa << ", ";
  cout << "Advisor ID: " << advisorID << endl;
}
