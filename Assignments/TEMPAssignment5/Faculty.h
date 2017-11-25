/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "DoublyLinkedList.h"
#include "Member.h"
#ifndef included
#define included

using namespace std;

class Faculty : public Member {
  private:

  public:
    string department;

    unsigned int numAdvisee;
    unsigned int maxSize;

    int *adviseeArray;

    Faculty();
    ~Faculty();
    Faculty(int ID, string name_, string level_, string department_);

    void printFaculty();
    void printAdvisee();

    string getDepartment();

    int getAdviseeID();
    void addAdvisee(int ID);
    bool removeAdvisee(int adviseeID);

    int getSizeArray();

    bool operator == (const Faculty &f) {
      return(this->ID == f.ID);
    }
    bool operator != (const Faculty &f) {
      return(this->ID != f.ID);
    }
    bool operator <= (const Faculty &f) {
      return(this->ID <= f.ID);
    }
    bool operator >= (const Faculty &f) {
      return(this->ID >= f.ID);
    }
    bool operator < (const Faculty &f) {
      return(this->ID < f.ID);
    }
    bool operator > (const Faculty &f) {
      return(this->ID > f.ID);
    }

    friend ostream& operator << (ostream& output, const Faculty &f) {
      output << "Faculty ID: " << f.ID << endl;
      output << "Faculty Name: " << f.name << endl;
      output << "Level: " << f.level << endl;
      output << "Department: " << f.department << endl;
      output << "Advisee IDs: ";
      /*if(f == NULL) {
        //All Advisors Have Advisee's, Error Catch Implementation if things mess up
        output << "None" << endl;
      }
      else {
        while(true) {
          output << f->data;
          if(f->next != NULL) {
            output << ", ";
            f = f->next;
          }
          else {
            break;
          }
        }
      }*/

      return output;
    }
};

#endif
