#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include "board.h"

using namespace std;

// Populates and prints out the starting board.
Board startingBoard(Board &board) {
    // Initialize the grid with '.' for all cells
    board.grid = string(board.nrows * board.ncols, '.');

    // Print column titles
    cout << "Initial Board:\n";
    for (int i = 0; i < board.ncols; i++) {
        cout << static_cast<char>(i + 65) << " ";
    }
    cout << "\n";

    // Print starting populated board
    for (int i = 0; i < board.nrows; i++){
        for (int ii = 0; ii < board.ncols; ii++) {
            int index = i * board.ncols + ii;
            if (index < board.grid.size()) {
            cout << board.grid[index] << " ";
            }
            else {
                cout << "Past Index Of Array";
            }
        }
        cout << "\n";
    }
    // Return Initial Blank Board
    return board;
}

// Prints the current board
void printBoard(const Board &board) {
    // print column names
    for (int i = 0; i < board.ncols; i++) {
        cout << static_cast<char>(i + 65) << " ";
    }
    cout << "\n";
    // print each location on the board
    for (int i = 0; i < board.nrows; i++){
        for (int ii = 0; ii < board.ncols; ii++) {
            int index = i * board.ncols + ii;
            if (index < board.grid.size()) {
            cout << board.grid[index] << " ";
            }
        }
        cout << "\n";
    }
    return;
}

// Cheks if the board is full, else its a tie
bool checkIfBoardIsFull(const Board &board) {
    for (int i = 0; i < board.nrows; i++) {
        for (int ii = 0; ii < board.ncols; ii++) {
            int index = i * board.ncols + ii;
            if (board.grid[index] == '.') {
                return false;
            }
        }
    }
    cout << "It's a tie.";
    return true;
}

/* TODO - block players from placing in columns outside of valid ones*/
Board playerTurn(Board &board) {

    // Variables for column input
    char playerTurn = '\0';
    int columnNumber = 0;
    bool chipPlaced = false;

    // Collect column input and get index to place
    while(!chipPlaced) {
        // Loop until we get a valid input for a column
        while(true) {
            if (playerTurn == '\0') {
                cout << "Player " << board.pturn << " what column would you like?";  
            }
            // Collect column
            cin >> playerTurn;
            // If input is a capital letter
            if (static_cast<int>(playerTurn) >= 65 && static_cast<int>(playerTurn) <= 90) {
                // check that it's a valid column
                if (static_cast<int>(playerTurn - 65) < board.ncols) {
                    break;
                } else {
                    cout << "Sorry I didn't get that, please enter a valid column\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    playerTurn = '\0';
                }
            // If input is a lowercase letter
            } else if (static_cast<int>(playerTurn) >= 97 && static_cast<int>(playerTurn) <= 122) {
                playerTurn -= 32;
                // check that it's a valid column
                if (static_cast<int>(playerTurn - 65) < board.ncols) {
                    break;
                } else {
                    cout << "Sorry I didn't get that, please enter a valid column\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    playerTurn = '\0';
                }
            // Otherwise the input is invalid
            } else {
                cout << "Sorry I didn't get that, please enter a valid column\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                playerTurn = '\0';
            }
        }

        // Handle token stacking
        for (int i = 0; i < board.nrows; i++) {
            // Grab column index
            columnNumber = static_cast<int>(playerTurn - 65);
            // Figure out grid index based on the row we are checking
            int index = (((board.ncols) * (board.nrows - 1)) + columnNumber) - (i * board.ncols);
                // there is already a token in this row for the selecetd column
                if(board.grid[index] == '.') {
                    // Place chip and update board
                    board.grid[index] = char(board.pturn + 48);
                    chipPlaced = true;
                    printBoard(board);
                    board.pturn = board.pturn % 2 + 1;
                    return board;
                } 
        }
        // Column is full
        cout << "Looks like that column is full\n";
        playerTurn = '\0';
    }
    return board;
}

std::string toArrayHorizontal(const Board &board) {
    string horizontals = "";
    // loop through rows
    for (int i = 0; i < board.nrows; i++) {
        // loop through columns
        for (int ii = 0; ii < board.ncols; ii++) {
            int index = i * board.ncols + ii;
            horizontals += (board.grid[index]);
        }
        horizontals += 'x';
    }
    return horizontals;
}

std::string toArrayVertical(const Board &board) {
    string verticals = "";
    // loops thorough columns
    for (int i = 0; i < board.nrows; i++) {
        // loop through rows
        for (int ii = 0; ii < board.ncols; ii++) {
            int index = ii * board.ncols + i;
            verticals += (board.grid[index]);
        }
        verticals += 'x';
    }
    return verticals;
}

std::string toArrayDiagonal(const Board &board) {
    string diagonals = "";

    // bottom right to top
    for (int i = board.nrows; i >= 0; i--) {
        for (int ii = 0; ii < board.nrows - i; ii++) {
            int index = (i * board.ncols + ii * board.ncols) + ii;
            diagonals += (board.grid[index]);
        }
        diagonals += 'x';
    }
    // top right to bottom right
    for (int i = board.ncols - 1; i > 0; i--) {
        for (int ii = 0; ii < board.ncols - i; ii++) {
            int index = i + ((board.ncols + 1) * ii);
            diagonals += (board.grid[index]);
        }
        diagonals += 'x';
    }
    return diagonals;
}

//flips the board across the horizontal pllane to grab the other diagonals
Board flipGrid(const Board &board) {
    Board flippedBoard = board;
    string flippedGrid = "";

    for (int i = 0; i < board.nrows; i++) {
        for (int ii = board.ncols-1; ii >= 0; ii--) {
            int index = (i * board.ncols + ii);
            flippedGrid += (board.grid[index]);
        }
    }
    flippedBoard.grid = flippedGrid;
    return flippedBoard;
}

// Checks if there is a winner
char checkWin(const std::string tokens) {
    // how many in a row for the player we are checking
    int consecutive = 0;
    // current token in the board we are looking at
    char currentToken = '\0';
    // What player we are evauluating consecutives for
    char playerChecking = '\0';
    for (int i = 0; i < tokens.length(); i++){
        currentToken = tokens[i];
        // If there's not a player token or if the row/column/diagonal has been looked through
        if (currentToken == 'x' || currentToken == '.') {
            consecutive = 0;
            playerChecking = '\0';
        // If theres a consecutive
        } else if (currentToken == playerChecking) {
            consecutive++;
        // A different player's token
        } else {
            playerChecking = currentToken;
            consecutive = 1;
        }
        // 4 in a row means you win 
        if (consecutive >= 4) {
            return playerChecking;
        }
    }
    // return \0 if theres currently not a winner
    return '\0';
}