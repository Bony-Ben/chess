#include "player.h"

#ifndef LEVEL4_H
#define LEVEL4_H

class Board;
class Move;

class Level4 : public Player {
    int MAX_DEPTH = 3;

    int minimax(Board &board, char turn, int depth);
    int evaluateMove(Move &mv);

   public:
    void makeMove(Board &board, std::vector<Move> &moves, char colour) override;
};

#endif