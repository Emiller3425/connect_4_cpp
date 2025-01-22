#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

struct Board {
    std::string grid;
    int winner;
    int nrows;
    int ncols;
    int numToWin;
    int pturn;
    int checkFull;

};

Board startingBoard(Board &);

void printBoard(const Board &board);

bool checkIfBoardIsFull(const Board &board);

Board playerTurn(Board &);

std::string toArrayHorizontal(Board*);

std::string toArrayVertical(Board*);

std::string toArrayDiag(Board*);

std::string flipBoard(Board*);

int xInARow(int, int, std::string, Board*);

#endif