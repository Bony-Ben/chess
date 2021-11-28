#include "player.h"

#ifndef HUMAN_H
#define HUMAN_H

class Board;
class Move;

class ResignException {};
class UndoException {};

class Human : public Player {
   public:
    Move makeMove(Board &board, char colour) override;
};

#endif