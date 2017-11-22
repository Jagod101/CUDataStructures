/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "studentRecords.h"

StudentRecords::StudentRecords(){
  id = -1;
  name = "";
  grade = "";
  major = "";
  gpa = -1.0;
  advisorID = -1;
}

StudentRecords::~StudentRecords(){

}

StudentRecords::StudentRecords(int id_){
  id = id_;
  name = "";
  grade = "";
  major = "";
  gpa = -1.0;
  advisorID = -1;
}

StudentRecords::StudentRecords(int id, string name, string grade, string major, double gpa, int advisorID){

}

StudentRecords::StudentRecords(string srSerialized){

}

string StudentRecords::serialize(){

}
