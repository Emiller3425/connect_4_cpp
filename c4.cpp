#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <limits>
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

    while (true) {
    cout << "How many rows would you like? (4-9)\n";
    cin >> board.nrows;
    if (std::cin.fail() || board.nrows < 4 || board.nrows > 9) {
        cout << "Sorry I didn't get that, please enter a valid amount of row\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        board.nrows = 0;
    } else {
        break;
    }
    }
     while (true) {
    cout << "How many columns would you like? (4-9)\n";
    cin >> board.ncols;
    if (std::cin.fail() || board.ncols < 4 || board.ncols > 9) {
        cout << "Sorry I didn't get that, please enter a valid amount of columns (4-9)\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        board.nrows = 0;
    } else {
        break;
    }
    }

    board = startingBoard(board);
    bool fullBoard = false;

    while(fullBoard == false) {
    // Update board with playerTurn
    board = playerTurn(board);
    // Get horizontals
    toArrayHorizontal(board);
    // Get verticals
    toArrayVertical(board);
    // Get diagonals
    toArrayDiagonal(board);
    // Check if board is full
    fullBoard = checkIfBoardIsFull(board);

    }

    return 0;
}
