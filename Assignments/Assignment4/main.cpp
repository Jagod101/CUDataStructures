#include <iostream>
#include "assign4.cpp"

using namespace std;

int main(int argc, char** argv) {
    //INSERT CONSTRUCTOR

    //If no file specified when running a.out
    if(argc < 2) {
        cout << "ERROR: Please Enter Valid File Input\n" << endl;
    }
    
    //If file is specified when running a.out
    else if(argc >= 2) {
        string file = argv[1];
        //INSERT METHOD CALL
    }
    return 0;
}