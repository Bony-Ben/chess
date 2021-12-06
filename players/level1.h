#include "player.h"

#ifndef LEVEL1_H
#define LEVEL1_H

class Board;

class Level1 : public Player {
   public:
    void makeMove(Board &board, char colour) override;
};

#endif