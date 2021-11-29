#include <vector>

#include "piece.h"

#ifndef KING_H
#define KING_H

class King : public Piece {
   public:
    King(char colour, int rank, int file, Board &board);
    void getMoves(std::vector<Move> &moves) override;
};

#endif