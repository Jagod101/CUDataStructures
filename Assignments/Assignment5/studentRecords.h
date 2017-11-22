/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include <string>


using namespace std;

class StudentRecords {

  private:

  public:
    int id;
    string name;
    string grade;
    string major;
    double gpa;
    int advisorID;

    StudentRecords();
    ~StudentRecords();

    StudentRecords(int id);
    StudentRecords(int id, string name, string level, string grade, double gpa, int advisorID);
    StudentRecords(string srSerialized);
    string serialize();

    bool operator == (const StudentRecords &s) {
      return(this->id == s.id);
    }
    bool operator != (const StudentRecords &s) {
      return(this->id != s.id);
    }
    bool operator <= (const StudentRecords &s) {
      return(this->id <= s.id);
    }
    bool operator >= (const StudentRecords &s) {
      return(this->id >= s.id);
    }
    bool operator < (const StudentRecords &s) {
      return(this->id < s.id);
    }
    bool operator > (const StudentRecords &s) {
      return(this->id > s.id);
    }

    //Add Weird friend thing
};
