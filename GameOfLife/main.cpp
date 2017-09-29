#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "GameOfLife.h"

using namespace std;

int main (int argc, char** argv) {
    int boardLength;
    int boardWidth;

    string file;

    Game g;

    g.gameSettings(file, boardLength, boardWidth);

    return 0;
}