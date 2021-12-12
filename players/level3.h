#include "player.h"

#ifndef LEVEL3_H
#define LEVEL3_H

class Board;
class Move;

class Level3 : public Player {
   public:
    void makeMove(Board &board, std::vector<Move> &moves, char colour) override;
};

#endif