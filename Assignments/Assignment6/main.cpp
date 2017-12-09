/*
Zachary Jagoda
Student ID: 2274813
Student Email: jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include "assign6.h"

using namespace std;

int main(int argc, char** argv) {
  Sorting s;

  //If no file was specified when running a.out
  if (argc < 2) {
      cout << "ERROR: Please Enter Valid File Input\n" << endl;
  }
  //If a file was specified when running a.out
  else if (argc >= 2) {
      string file = argv[1]; //set file equal to argv
      s.setFile(file);
  }

  return 0;
}
