#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include "board.h"

using namespace std;

// Populates and prints out the starting board.
Board startingBoard(Board *board) {
    // Initialize the grid with '.' for all cells
    board->grid = string(board->nrows * board->ncols, '.');

    // Print column titles
    cout << "Initial Board:\n";
    for (int i = 0; i < board->ncols; i++) {
        cout << static_cast<char>(i + 65) << " ";
    }
    cout << "\n";

    // Print starting populated board
    for (int i = 0; i < board->nrows; i++){
        for (int ii = 0; ii < board->ncols; ii++) {
            int index = i * board->ncols + ii;
            if (index < board->grid.size()) {
            cout << board->grid[index] << " ";
            }
            else {
                cout << "Past Index Of Array";
            }
        }
        cout << "\n";
    }
    // Return Initial Blank Board
    return *board;
}

// Prints the current board
void printBoard(Board *board) {
    // print column names
    for (int i = 0; i < board->ncols; i++) {
        cout << static_cast<char>(i + 65) << " ";
    }
    cout << "\n";
    // print each location on the board
    for (int i = 0; i < board->nrows; i++){
        for (int ii = 0; ii < board->ncols; ii++) {
            int index = i * board->ncols + ii;
            if (index < board->grid.size()) {
            cout << board->grid[index] << " ";
            }
            else {
                cout << "What the Fuck";
            }
        }
        cout << "\n";
    }
    return;
}

// Cheks if the board is full, else its a tie
bool checkIfBoardIsFull(Board *board) {
    for (int i = 0; i < board->nrows; i++) {
        for (int ii = 0; ii < board->ncols; ii++) {
            int index = i * board->ncols + ii;
            if (board->grid[index] == '.') {
                return false;
            }
        }
    }
    cout << "It's a tie.";
    return true;
}

/* TODO - block players from placing in columns outside of valid ones*/
Board playerTurn(Board *board) {

    // Variables for column input
    char playerTurn = '\0';
    int columnNumber = 0;
    bool chipPlaced = false;

    // Collect column input and get index to place
    while(!chipPlaced) {
        if (playerTurn == '\0') {
            cout << "Player " << board->pturn << " what column would you like?";  
        }
        cin >> playerTurn;
        for (int i = 0; i < board->nrows; i++) {
            columnNumber = static_cast<int>(playerTurn - 65);
            int index = (((board->ncols) * (board->nrows - 1)) + columnNumber) - (i * board->ncols);
                if(board->grid[index] != '.') {
                    // Do Nothing
                    ;
                } else if (index > board->grid.length()){
                    cout << "Column Full";
                    return *board;
                } else {
                    // Place chip and update board
                    board->grid[index] = char(board->pturn + 48);
                    chipPlaced = true;
                    printBoard(board);
                    board->pturn = board->pturn % 2 + 1;
                    return *board;
                    }
        }
        cout << "Looks like that column is full\n";
        playerTurn = '\0';
    }
}

std::string toArrayHorizontal(Board *board) {
    return "p";
}

std::string toArrayVertical(Board* *board) {
    return "p";
}

std::string toArrayDiag(Board* *board) {
    return "p";
}

// May have to change the return type for this
std::string flipBoard(Board* *board) {
    return "p";
}