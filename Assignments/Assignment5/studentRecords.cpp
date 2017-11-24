/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "studentRecords.h"

StudentRecords::StudentRecords(){
  srID = -1;
  name = "";
  grade = "";
  major = "";
  gpa = -1.0;
  advisorID = -1;
}

StudentRecords::~StudentRecords(){

}

StudentRecords::StudentRecords(int srID_){
  srID = srID_;
  name = "";
  grade = "";
  major = "";
  gpa = -1.0;
  advisorID = -1;
}

StudentRecords::StudentRecords(int srID_, string name_, string grade_, string major_, double gpa_, int advisorID_){
  srID = srID_;
  name = name_;
  grade = grade_;
  major = major_;
  gpa = gpa_;
  advisorID = advisorID_;
}

StudentRecords::StudentRecords(string srSerialized){
  deserialize(srSerialized);
}

string StudentRecords::serialize(){
  ostringstream output;

  output << srID << ',' + name + ',' + grade + ',' + major + ',' << gpa << ',' << advisorID;
  return output.str();
}

void StudentRecords::deserialize(string srSerialized) {
  string value;
  int counter = 0;

  stringstream input(srSerialized);

  while(getline(input, value, ',')) {
    //ID input
    if(counter == 0) {
      srID = atoi(value.c_str());
    }
    //Name Input
    else if(counter == 1) {
      name = value;
    }
    //Grade Input
    else if(counter == 2) {
      grade = value;
    }
    //Major Input
    else if(counter == 3) {
      major = value;
    }
    //GPA Input
    else if(counter == 4) {
      gpa = atof(value.c_str());
    }
    //AdvisorID Input
    else if(counter == 5) {
      advisorID = atoi(value.c_str());
    }
    counter++;
  }
}
