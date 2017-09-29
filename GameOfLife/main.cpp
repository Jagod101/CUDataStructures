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

    string inputFile;

    Game g;

    g.gameSettings(inputFile, boardLength, boardWidth);

    return 0;
}