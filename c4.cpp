#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include "board.h"

using namespace std;

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

    for (int i = 0; i < board.nrows; i++) {
        for (int ii = 0; ii < board.ncols; ii++) {
            cout << ". ";
        }
        cout << "\n";
    }

    board = startingBoard(&board);

    return 0;
}