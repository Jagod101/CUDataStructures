#include <iostream>
#include "genstack.h"

using namespace std;

int main (int argc, char** argv) {
    genstack g(5);

    g.push("r");
    g.push("r");
    g.push("r");
    g.push("r");

    cout << "POP: " << g.pop() << endl;
    cout << "POP: " << g.pop() << endl;
    cout << "PEEK: " << g.peek() << endl;
    cout << "EMPTY: " << g.isEmpty() << endl;
    
    g.push("h");
    g.push("L");

    while(!g.isEmpty()) {
        cout << g.pop() << endl;
    }

    return 0;
}