/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "facultyRecords.h"

FacultyRecords::FacultyRecords() {
  frID = -1;
	name = "";
	level = "";
	department = "";
	adviseeID = new DoublyLinkedList<int>();
}

FacultyRecords::~FacultyRecords() {
  delete adviseeID;
}

FacultyRecords::FacultyRecords(int frID_) {
  frID = frID_;
  name = "";
  level = "";
  department = "";
  adviseeID = new DoublyLinkedList<int>();
}

FacultyRecords::FacultyRecords(int frID_, string name_, string level_, string department_) {
  frID = frID_;
  name = name_;
  level = level_;
  department = department_;
  adviseeID = new DoublyLinkedList<int>();
}

FacultyRecords::FacultyRecords(string frSerialized) {
  adviseeID = new DoublyLinkedList<int>();
  deserialize(frSerialized);
}

string FacultyRecords::serialize() {
  ListNode<int> *node = adviseeID->front;

  ostringstream output;

  output << frID << ',' + name + ',' + level + ',' + department + ',';

  //An Advisor can have MULTIPLE Advisee's, update node for printing
  if(node == NULL) {
    //All Advisors Have Advisee's, Error Catch Implementation if things mess up
    output << ' ';
  }
  else {
    while(true) {
      output << node->data;
      if(node->next != NULL) {
        output << ',';
        node = node->next;
      }
      else {
        break;
      }
    }
  }

  return output.str();
}

void FacultyRecords::deserialize(string frSerialized) {
    string value;
    int counter = 0;

    stringstream input(frSerialized);

    while(getline(input, value, ',')) {
      //ID input
      if(counter == 0) {
        frID = atoi(value.c_str());
      }
      //Name Input
      else if(counter == 1) {
        name = value;
      }
      //Level Input
      else if(counter == 2) {
        level = value;
      }
      //Department Input
      else if(counter == 3) {
        department = value;
      }
      //Advisee Input
      else if(counter >= 4) {
        addAdvisee(atoi(value.c_str()));
      }
      counter++;
    }
}

void FacultyRecords::addAdvisee(int frID) {
  adviseeID->insertBack(frID);
}

int FacultyRecords::removeAdviseeID(int frID) {
  adviseeID->remove(frID);
}

bool FacultyRecords::containsAdvisee(int frID) {
  return(adviseeID->find(frID));
}
