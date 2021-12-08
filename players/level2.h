#include "player.h"

#ifndef LEVEL2_H
#define LEVEL2_H

class Board;
class Move;

class Level2 : public Player {
   public:
    void makeMove(Board &board, std::vector<Move> &moves, char colour) override;
};

#endif