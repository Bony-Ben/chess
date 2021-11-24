#include <vector>
#include "../move.h"

#ifndef PIECE_H
#define PIECE_H

class Board;
class Piece
{
    char colour;
    int rank;
    int file;
    Board &board;

public:
    Piece(char colour, int rank,int file, Board &board);
    virtual std::vector<Move> getMoves() = 0;
};

#endif