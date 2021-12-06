#include <vector>

#include "piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece {
   public:
    Knight(char colour, int rank, int file, Board &board);
    void getMoves(std::vector<Move> &moves, bool validateChecks) override;
    std::unique_ptr<Piece> clone() const override;
};

#endif