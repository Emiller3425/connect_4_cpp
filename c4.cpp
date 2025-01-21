#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include "board.h"

using namespace std;


/* TODO - make sure that requested column sizes are valid integers*/ 
int main(int argc, char* argv[]) {
    /// Define Board struct and inital variables
    struct Board board;
    board.pturn = 1;
    board.winner = -1;
    board.checkFull = 0;
    board.numToWin = 4;

    cout << "How many rows would you like?\n";
    cin >> board.nrows;
    cout << "How many columns would you like?\n";
    cin >> board.ncols;
    cout << "Rows: " << board.nrows << "\n" << "Columns : " << board.ncols << "\n";

    board = startingBoard(&board);

   // printBoard(&board);

   bool fullBoard = false;

   while(fullBoard == false) {

   board = playerTurn(&board);

   fullBoard = checkIfBoardIsFull(&board);

   }

    return 0;
}
