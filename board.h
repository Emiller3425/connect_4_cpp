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

Board startingBoard(Board *);

#endif