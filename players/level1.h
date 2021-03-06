#include "player.h"

#ifndef LEVEL1_H
#define LEVEL1_H

class Board;
class Move;

class Level1 : public Player {
   public:
    void makeMove(Board &board, std::vector<Move> &moves, char colour) override;
};

#endif