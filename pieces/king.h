#include <vector>

#include "piece.h"

#ifndef KING_H
#define KING_H

class King : public Piece {
    bool canCastle;

   public:
    King(char colour, int rank, int file, Board *board, bool canCastle);
    void executeWhenMoved(Move &mv) override;
    void executeWhenUndoed(Move &mv) override;
    void getMoves(std::vector<Move> &moves, bool validateChecks) override;
    bool getCanCastle();
    std::unique_ptr<Piece> clone(Board * board) const override;
};

#endif