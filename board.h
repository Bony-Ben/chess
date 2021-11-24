#include <memory>

#ifndef BOARD_H
#define BOARD_H

class Piece;

class Board
{
    std::unique_ptr<Piece> arr[8][8];
    Board();
};

#endif