#ifndef PLAYER_H
#define PLAYER_H

class Board;
class Move;

class StalemateException {};
class CheckmateException {};

class Player {
   public:
    virtual void makeMove(Board &board, char colour) = 0;
};

#endif