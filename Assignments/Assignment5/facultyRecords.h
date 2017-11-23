/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include "DoublyLinkedList.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class FacultyRecords {
  private:
    void deserialize(string frSerialized);

  public:
    int frID;
    string name;
    string level;
    string department;
    DoublyLinkedList<int> *adviseeID;

    FacultyRecords();
    ~FacultyRecords();
    FacultyRecords(int frID_);
    FacultyRecords(int frID_, string name_, string level_, string department_);
    FacultyRecords(string frSerialized);

    string serialize();

    void addAdvisee(int frID);
    int removeAdvisee(int frID);
    bool containsAdvisee(int frID);

    bool operator == (const FacultyRecords &fr) {
      return(this->frID == fr.frID);
    }
    bool operator != (const FacultyRecords &fr) {
      return(this->frID != fr.frID);
    }
    bool operator <= (const FacultyRecords &fr) {
      return(this->frID <= fr.frID);
    }
    bool operator >= (const FacultyRecords &fr) {
      return(this->frID >= fr.frID);
    }
    bool operator < (const FacultyRecords &fr) {
      return(this->frID < fr.frID);
    }
    bool operator > (const FacultyRecords &fr) {
      return(this->frID > fr.frID);
    }

    friend ostream& operator << (ostream& output, const FacultyRecords &fr) {
      ListNode<int> *node = fr.adviseeID->front;

      output << "Faculty ID: " << fr.frID << endl;
      output << "Faculty Name: " << fr.name << endl;
      output << "Level: " << fr.level << endl;
      output << "Department: " << fr.department << endl;
      output << "Advisee IDs: ";

      //An Advisor can have MULTIPLE Advisee's, update node for printing
      if(node == NULL) {
        //All Advisors Have Advisee's, Error Catch Implementation if things mess up
        output << "None" << endl;
      }
      else {
        while(true) {
          output << node->data;
          if(node->next != NULL) {
            output << ", ";
            node = node->next;
          }
          else {
            break;
          }
        }
      }

      return output;
};
