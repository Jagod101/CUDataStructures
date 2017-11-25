/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "Menu.h"

using namespace std;

int main(int argc, char** argv) {
  Menu m;

  m.readFile();
  m.printMenu();
  m.writeFile();
  
  return 0;
}
