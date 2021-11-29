#include <vector>

#include "piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece {
   public:
    Knight(char colour, int rank, int file, Board &board);
    void getMoves(std::vector<Move> &moves) override;
};

#endif