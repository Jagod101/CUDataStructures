/*
Ashley Wood and Zachary Jagoda
Student ID: 2271425 and Student ID: 2274813
Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
CPSC 350-02
*/

#include "Menu.h"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::printMenu() {
  string input;
  int numInput;
  bool triggered;
  bool running = true;

  while (running) {
    cout << "\n****************** MENU ******************" << endl;
    cout << 1 << ".  Print (all) Student Info (by ascending ID)" << endl;
    cout << 2 << ".  Print (all) Faculty Info (by ascending ID)" << endl;
    cout << 3 << ".  Print Student Info (by student ID)" << endl;
    cout << 4 << ".  Print Faculty Info (by faculty ID)" << endl;
    cout << 5 << ".  Print Advisor Info (by student ID)" << endl;
    cout << 6 << ".  Print Advisee Info (by faculty ID)" << endl;
    cout << 7 << ".  Add New Student" << endl;
    cout << 8 << ".  Delete Student (by student ID)" << endl;
    cout << 9 << ".  Add New Faculty" << endl;
    cout << 10 << ". Delete Faculty (by faculty ID)" << endl;
    cout << 11 << ". Change Advisor (by student ID and faculty ID)" << endl;
    cout << 12 << ". Remove Advisee (by student ID and faculty ID)" << endl;
    cout << 13 << ". Rollback" << endl;
    cout << 14 << ". Exit" << endl;
    cout << "\nPlease Select a Menu Option: ";

    cin >> input;

    try {
      numInput = atoi(input.c_str());

      if(numInput < 0 || numInput > 14) {
        cout << "Glitch Within the Matrix - Please Enter a Valid Menu Option \n" << endl;
        triggered = true;
        numInput = 15;
      }
    }
    catch(exception e) {
      triggered = false;
      numInput = 15;
    }

    switch(numInput) {
      case 1:
        printAllStudents();
        break;
      case 2:
        printAllFaculty();
        break;
      case 3:
        printStudent();
        break;
      case 4:
        printFaculty();
        break;
      case 5:
        printAdvisor();
        break;
      case 6:
        printAdvisee();
        break;
      case 7:
        addStudent();
        break;
      case 8:
        deleteStudent();
        break;
      case 9:
        addFaculty();
        break;
      case 10:
        deleteFaculty();
        break;
      case 11:
        changeAdvisor();
        break;
      case 12:
        removeAdvisee();
        break;
      case 13:
        rollback();
        break;
      case 14:
        exit();
        return;
      default:
        if(triggered == true) {
          continue;
        }
        else {
          cout << "Glitch Within the Matrix - Please Enter a Valid Menu Option \n" << endl;
          continue;
        }
    }
  }
}

//go through the tree printing all the students IN ORDER
void Menu::printAllStudents() {
  if(masterStudent.isEmpty()) {
    cout << "Student Database is Empty" << endl;
  }
  else {
    printMS(masterStudent.getRoot());
  }
}

//go through the tree printing all the faculty IN ORDER
void Menu::printAllFaculty() {
  if(masterFaculty.isEmpty()) {
    cout << "Faculty Database is Empty" << endl;
  }
  else {
    printMF(masterFaculty.getRoot());
  }
}

void Menu::printStudent() {
  string input;
  int srID;

  if(masterStudent.isEmpty()) {
    cout << "Student Database is Empty" << endl;
  }
  else {
    while(true) {
      cout << "Please Provide a Student ID: ";
      cin >> input;

      try {
        srID = atoi(input.c_str());

        if(masterStudent.contains(srID)) {
          masterStudent.find(srID);
          break;
        }
        else {
          cout << "Student ID: " << srID << "Does Not Exist Within Database" << endl;
        }
      }
      catch(exception e) {
        cout << "Please Enter Valid Input" << endl;
      }
    }
  }
}

void Menu::printFaculty() {
  string input;
  int frID;

  if(masterFaculty.isEmpty()) {
    cout << "Faculty Database is Empty" << endl;
  }
  else {
    while(true) {
      cout << "Please Provide a Faculty ID: ";
      cin >> input;

      try {
        frID = atoi(input.c_str());

        if(masterFaculty.contains(frID)) {
          masterFaculty.find(frID);
          break;
        }
        else {
          cout << "Faculty ID: " << frID << " Does Not Exist Within Database" << endl;
        }
      }
      catch(exception e) {
        cout << "Please Enter Valid Input" << endl;
      }
    }
  }
}

void Menu::printAdvisor() {
  string input;
  int srID;

  if(masterStudent.isEmpty()) {
    cout << "Student Database is Empty" << endl;
  }
  else {
    cout << "List of Students Within Database: " << endl;
    printMS(masterStudent.getRoot());

    while(true) {
      cout << "Please Provide a Student ID: ";
      cin >> input;

      try {
        srID = atoi(input.c_str());

        if(masterStudent.contains(srID)) {
          masterFaculty.find(masterStudent.find(srID)->getAdvisor());
          break;
        }
        else {
          cout << "Student ID: " << srID << " Does Not Exist Within Database" << endl;
        }
      }
      catch(exception e) {
        cout << "Please Enter Valid Input" << endl;
      }
    }
  }
}

void Menu::printAdvisee() {
  string input;
  int frID;

  if(masterFaculty.isEmpty()) {
    cout << "Faculty Database is Empty" << endl;
  }
  else {
    cout << "List of Faculty Within Database: " << endl;
    printMF(masterFaculty.getRoot());

    while(true) {
      cout << "Please Provide a Faculty ID: ";
      cin >> input;

      try {
        frID = atoi(input.c_str());

        if(masterFaculty.contains(frID)) {
          Faculty *faculty = masterFaculty.find(frID);

          for(int i = 0; i < faculty->getSizeArray(); ++i) {
            if(faculty->adviseeArray[i] != -1) {
              masterStudent.find(faculty->adviseeArray[i]);
            }
          }
          break;
        }
        else {
          cout << "Faculty ID: " << frID << " Does Not Exist Within Database" << endl;
        }
      }
      catch(exception e) {
        cout << "Please Enter Valid Input" << endl;
      }
    }
  }
}

void Menu::addStudent() {
  string input;

  goodID = false;
  srand(time(NULL));
  int srID = rand() % 4000 + 1000; // will generate a number between 1000 and 4999

  while(goodID == false){
    if(masterStudent.contains(srID) == false){
      goodID = true;
    }
    else {
      int srID = rand() % 4000 + 1000;
      goodID = false;
    }
  }

  cout << "New Students Generated ID: " << srID << endl;

  string name;
  cout << "New Student Name: ";
  cin >> name;

  string level;
  cout << "\nNew Student Grade: ";
  cin >> level;

  string major;
  cout << "\nNew Student Major: ";
  cin >> major;

  double gpa;
  while(true) {
    input = "";
    cout << "New Student GPA: ";
    cin >> input;

    try {
      gpa = atod(input);

      if(gpa > 5 || gpa < 0) {
        cout << "\nEnter GPA From 0-5" << endl;
      }
      else {
        break;
      }
    }
    catch(exception e) {
      cout << "Please Enter Valid Input" << endl;
    }
  }

  int advisorID;
  while(true) {
    input = "";
    cout << "New Student Advisor ID: ";
    cin >> input;

    try {
      advisorID = atoi(input);

      if(masterFaculty.contains(advisorID)) {
        Faculty *faculty = masterFaculty.find(advisorID);
        faculty->addAdvisee(srID);
        break;
      }
      else {
        input = "";
        cout << "\nFaculty ID: " << advisorID << " Does Not Exist Within Database" << endl;
        cout << "(Y/N) Would You Like a List of Faculty? ";
        cin >> input;

        if(input == "Y" || in[ut] == "Yes") {
          printAllFaculty();
        }
        else {
          continue;
        }
      }
    }
    catch(exception e) {
      cout << "Please Enter Valid Input" << endl;
    }
  }

  Student *student = new Student(srID, name, level, major, grade, advisorID);
  TreeNode<Student> *studentNode = new TreeNode<Student>(student, srID);
  masterStudent.put(studentNode);
}

void Menu::deleteStudent() {
/*
  int srID = 0;
  foundStudent = false;

  while(foundStudent == false){
    if(studentBST.isEmpty()) {
      cout << "Student Tree is Empty" << endl;
      return;
    }
    else {
      cout << "What student would you like to look for? (Give an ID number) ";
      cin >> srID;

      StudentRecords sr(srID);

      if(studentBST.contains(sr)) {

        FacultyRecords fr;

        foundStudent = true;

      }
      else {
        cout << "Student ID: " << srID << " Does Not Exist. Try a new ID." << endl;
      }
    }

    studentBST.erase(id);

    //delete the student from the facultyRecords
  }
  */
}

void Menu::addFaculty() {
  string input;

  //Generate Faculty ID
  goodID = false;
  srand(time(NULL));
  int frID = rand() % 5000 + 5000; // will generate a number between 5000 and 9999

  while(goodID == false){
    if(masterFaculty.contains(frID) == false){
      goodID = true;
    }
    else {
      int frID = rand() % 5000 + 5000;
      goodID = false;
    }
  }

  cout << "New Faculty ID: " << frID << endl;

  string name;
  cout << "New Faculty Name: ";
  cin >> name;

  string level;
  cout << "\nNew Faculty Level: ";
  cin >> level;

  string department;
  cout << "\nNew Faculty Department: ";
  cin >> department;

  Faculty *faculty = new Faculty(frID, name, level, department);

  //ADD ADVISEE SECTION
}

void Menu::deleteFaculty() {
/*
  int id = 0;

  cout << "What student would you like to look for? (Give an id number)" << endl;
  cin >> id;

  facultyBST.erase(id);

  //this might have to change bc we might have to create a copy of their records before
  //they are deleted so that we can have all their advisee's to shift

  //shift the students to new advisers
  //record changes in studentRecords
*/
}

void Menu::changeAdvisor() {
  string input;
  int srID = 0;
  int frID = 0;

  if(masterFaculty.isEmpty() || masterStudent.isEmpty()) {
    cout << "Student and/or Faculty Database is Empty" << endl;
  }
  else {
    cout << "List of Students Within Database: ";
    printMS(masterStudent.getRoot());

    while(true) {
      input = "";
      cout << "Please Provide a Student ID: ";
      cin >> input;

      try {
        srID = atoi(input);

        if(masterStudent.contains(srID)) {
          while(true) {
            input = "";
            cout << "Please Provide a Faculty ID: ";
            cin >> input;

            try {
              frID = atoi(input);

              if(masterFaculty.contains(frID)) {
                break;
              }
              else {
                cout << "Faculty ID: " << frID << " Does Not Exist Within Database" << endl;
              }
            }
            catch(exception e) {
              cout << "Please Provide Valid Input" << endl;
            }
          }
        }
        else {
          cout << "Student ID: " << srID << " Does Not Exist Within Database" << endl;
        }
      }
      catch(exception e) {
        cout << "Please Enter Valid Input" << endl;
      }
    }
    masterStudent.find(srID)->setAdvisor(frID);
    masterFaculty.find(frID)->addAdvisee(srID);
  }
}

void Menu::removeAdvisee() {
  /*int srID = 0;
  int frID = 0;
  bool idIsWrong = true;

  if(facultyBST.isEmpty()) {
    cout << "Faculty Tree is Empty" << endl;
    return;
  }

  cout << "\nWhat is the ID of the student you would like to remove?: ";
  cin >> srID;

  cout << "\nWhat is the ID of that students advisor?: ";
  cin >> frID;

  while(idIsWrong == true){
    StudentRecords sr(srID);
    studentRecords s_value = studentBST.find(sr);
    FacultyRecords f_value(s_value.advisorID);

    if (frID != f_value){
      cout << "\nThat advisor is not the advisor to the student you entered. Enter a different ID number: ";
      cin >> frID;
    } else {
      idIsWrong = false;
    }
  }

  facultyBST.removeAdviseeID(frID, srID);

  cout << "Choose a new Advisor for this student" << endl;
  printAllFaculty();

  cout << "What is the new Advisor's ID: ";
  cin >> frID;

  FacultyRecords newfrID(frID);

  if(facultyBST.contains(newfrID)) {
    sr.advisorID = frID;
    studentBST.replaceAdvisor(sr);
    facultyBST.replaceAdvisee(oldfrID, newfrID, srID);
  }
  else {
    cout << "Faculty ID: " << frID << " Does Not Exist" << endl;
  }
  */
}

void Menu::rollback() {

  //this will apply to undoing the following methods:
  //addStudent, addFaculty, deleteStudent, deleteFaculty, changeAdvisor, removeAdvisee
  //STACK no greater than 5 (5 versions of previous trees, ALL trees)
  //All five times within Rollback
  //Clear the stack after fifth time

}

void Menu::exit() {
  cout << "EXITING PROGRAM..." << endl;
}
