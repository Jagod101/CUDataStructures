/*  Ashley Wood and Zachary Jagoda
    Student ID: 2271425 and Student ID: 2274813
    Student Emails: wood198@mail.chapman.edu jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)
*/

#include <iostream>
#include <fstream>

using namespace std;

class Game {
    private:
        string outputType;
        int countGen;
        string outString2;
        string outFileName;

    public:
        Game();
        ~Game();

        void selectSettings();
        void selectMode(int& boardLength, int& boardWidth, char**& board);
        
        //Game Modes (include File I/O)
        int mirrorMode(int boardLength, int boardWidth, char**& board);
        int donutMode(int boardLength, int boardWidth, char**& board);
        int classicMode(int boardLength, int boardWidth, char**& board);
        
        //Creates Board from File Import
        void createFileBoard(string inputfile);
        //Creates Board from Variables
        void createRandomBoard(int& boardLength, int& boardWidth);

        //Print Board out to Terminal
        void printOptions(string outputType, int countGen, char**& board, int boardLength, int boardWidth);
};
