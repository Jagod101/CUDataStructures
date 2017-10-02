#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "GameOfLife.h"

using namespace std;

int main () {
    Game g;

    int boardLength;
    int boardWidth;
    string file;
    
    g.gameSettings(file, boardLength, boardWidth);

    return 0;
}