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

using namespace std;

class StudentRecords {
  private:
    void deserialize(string srSerialized);

  public:
    int srID;
    string name;
    string grade;
    string major;
    double gpa;
    int advisorID;

    StudentRecords();
    ~StudentRecords();

    StudentRecords(int srID_);
    StudentRecords(int srID_, string name_, string grade_, string major_, double gpa_, int advisorID_);
    StudentRecords(string srSerialized);
    string serialize();

    bool operator == (const StudentRecords &sr) {
      return(this->srID == sr.srID);
    }
    bool operator != (const StudentRecords &sr) {
      return(this->srID != sr.srID);
    }
    bool operator <= (const StudentRecords &sr) {
      return(this->srID <= sr.srID);
    }
    bool operator >= (const StudentRecords &sr) {
      return(this->srID >= sr.srID);
    }
    bool operator < (const StudentRecords &sr) {
      return(this->srID < sr.srID);
    }
    bool operator > (const StudentRecords &sr) {
      return(this->srID > sr.srID);
    }

    friend ostream& operator << (ostream& output, const StudentRecords &sr) {
      output << "Student ID: " << sr.srID << endl;
      output << "Student Name: " << sr.name << endl;
      output << "Grade: " << sr.grade << endl;
      output << "Major: " << sr.major << endl;
      output << "GPA: " << sr.gpa << endl;
      output << "Advisor ID: " << sr.advisorID << endl;
      return output;
    }
};
