#include "player.h"

#ifndef HUMAN_H
#define HUMAN_H

class Board;
class Move;

class ResignException {};
class UndoException {};
class InputException {};
class EndOfFileException {};

class Human : public Player {
   public:
    void makeMove(Board &board, std::vector<Move> &moves, char colour) override;
};

#endif