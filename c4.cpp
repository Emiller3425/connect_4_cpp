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


    // Initialize the starting board
    startingBoard(board);

        while(true) {
        // Update board with playerTurn
        playerTurn(board);
        // Get horizontals
        toArrayHorizontal(board);
        // Get verticals
        toArrayVertical(board);
        // Get diagonals
        toArrayDiagonal(board);
        // flip grid to process other diagonals
        flipGrid(board);
        // Check if board is full
        if (checkIfBoardIsFull(board) == true) {
            cout << "It's a tie!";
            break;
        }

        // Check wins
        char horizontalCheck = checkWin(toArrayHorizontal(board));

        if (horizontalCheck != '\0') {
            cout << "Congrats Player " << horizontalCheck << ", you win!\n";
            break;
        }

        char verticalCheck = checkWin(toArrayVertical(board));

        if (verticalCheck != '\0') {
            cout << "Congrats Player " << verticalCheck << ", you win!\n";
            break;
        }

        char diagonalRightCheck = checkWin(toArrayDiagonal(board));

        if (diagonalRightCheck != '\0') {
            cout << "Congrats Player " << diagonalRightCheck << ", you win!\n";
            break;
        }

        char diagonalLeftCheck = checkWin(toArrayDiagonal(flipGrid(board)));

        if (diagonalLeftCheck != '\0') {
            cout << "Congrats Player " << diagonalLeftCheck << ", you win!\n";
            break;
        }
    }

    return 0;
}
