#include <vector>

#include "piece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen : public Piece {
   public:
    Queen(char colour, int rank, int file, Board &board);
    void getMoves(std::vector<Move> &moves) override;
};

#endif