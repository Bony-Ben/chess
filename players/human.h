#include "player.h"

#ifndef HUMAN_H
#define HUMAN_H

class Board;
class Move;

class Human : public Player {
   public:
    Move play(Board &board) override;
};

#endif