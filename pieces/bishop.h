#include <vector>

#include "piece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop : public Piece {
   public:
    Bishop(char colour, int rank, int file, Board &board);
    void getMoves(std::vector<Move> &moves, bool validateChecks) override;
    std::unique_ptr<Piece> clone() const override;
};

#endif