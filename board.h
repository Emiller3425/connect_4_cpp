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

std::string toArrayHorizontal(const Board &board);

std::string toArrayVertical(const Board &board);

std::string toArrayDiagonal(const Board &board);

std::string flipBoard(const Board &board);

int xInARow(int, int, std::string, const Board &board);

#endif