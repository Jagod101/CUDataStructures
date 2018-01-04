/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include "Member.h"

using namespace std;

Member::Member() {

}

Member::~Member() {

}

void Member::setID(int value) {
  ID = value;
}

int Member::getID() {
  return ID;
}

string Member::getName() {
  return name;
}

string Member::getLevel() {
  return level;
}
