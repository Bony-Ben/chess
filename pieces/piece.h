#include <vector>

#include "../move.h"

#ifndef PIECE_H
#define PIECE_H

class Board;
class Piece {
   protected:
    char colour;
    int rank;
    int file;
    Board &board;
    bool captured;

   public:
    Piece(char colour, int rank, int file, Board &board);
    virtual void getMoves(std::vector<Move> &moves) const = 0;
    virtual char toChar() const = 0;
    char getColour() const;
    int getRank() const;
    int getFile() const;
    bool isCaptured() const;
};

#endif