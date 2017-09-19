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

        selectMode(); //Select Game Mode
        classicMode(); //Classic Game Mode
        donutMode(); //Donut Game Mode
        mirrorMode(); //Mirror Game Mode

        createBoard(); //Create Game Board
}
