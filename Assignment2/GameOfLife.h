/*  Zachary Jagoda
    Student ID: 2274813
    Student Email: jagod101@mail.chapman.edu
    CPSC 350-02
    Assignment 2 (The Game of Life)

*/

#include <iostream>

using namespace std;

class Game {
    private:

    public:
        Game(); //Constructor
        ~Game(); //Deconstructor

        void selectMode(); //Select Game Mode
        void classicMode(); //Classic Game Mode
        void donutMode(); //Donut Game Mode
        void mirrorMode(); //Mirror Game Mode

        void createBoard(); //Create Game Board
}
