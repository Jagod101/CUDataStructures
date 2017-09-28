#include <iostream>
#include "genqueue.h"

using namespace std;

int main (int argc, char **argv) {
    GenQueue q(5);

    q.insert('k');
    q.insert('e');
    q.insert('c');
    q.insert('k');

    cout << "PEEK: " << q.peek() << endl;
    cout << "REMOVE: " << q.remove() << endl;
    cout << "PEEK: " << q.peek() << endl;
    cout << "EMPTY: " << q.empty() << endl;

    q.insert('r');
    q.insert('e');
    q.insert('n');
    q.insert('e');

    cout << "SIZE: " << q.getSize() << endl;

    while(!q.isEmpty()) {
        cout << "PRINT: " << g.remove() << endl;
    }

    cout << "SIZE: " << g.getSize() << endl;
}