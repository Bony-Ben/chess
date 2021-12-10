#include <vector>

#include "piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece {
    bool canCastle;

   public:
    Rook(char colour, int rank, int file, Board *board, bool canCastle);
    void executeWhenMoved(Move &mv) override;
    void getMoves(std::vector<Move> &moves, bool validateChecks) override;
    bool getCanCastle();
    std::unique_ptr<Piece> clone(Board * board) const override;
};

#endif