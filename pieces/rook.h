#include <vector>
#include "piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece
{
public:
    Rook(char colour, int rank, int file, Board &board);
    std::vector<Move> getMoves();
};

#endif