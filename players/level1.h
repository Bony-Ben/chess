#include "player.h"

#ifndef LEVEL1_H
#define LEVEL1_H

class Board;
class Move;

class Level1 : public Player {
   public:
    Move makeMove(Board &board, char colour) override;
};

#endif