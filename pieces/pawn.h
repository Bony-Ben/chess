#include <vector>

#include "piece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn : public Piece {
   public:
    Pawn(char colour, int rank, int file, Board &board);
    void getMoves(std::vector<Move> &moves, bool validateChecks) override;
    std::unique_ptr<Piece> clone() const override;
};

#endif