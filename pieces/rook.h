#include <vector>

#include "piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece {
    bool canCastle;

   public:
    Rook(char colour, int rank, int file, Board *board);
    void getMoves(std::vector<Move> &moves, bool validateChecks) override;
    std::unique_ptr<Piece> clone(Board * board) const override;
};

#endif