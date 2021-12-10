#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Board;
class Move;

class Player {
   public:
    virtual void makeMove(Board &board, std::vector<Move> &moves, char colour) = 0;
};

#endif