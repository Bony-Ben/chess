#ifndef PLAYER_H
#define PLAYER_H

class Board;
class Move;

class Player {
   public:
    virtual Move makeMove(Board &board, char colour) = 0;
};

#endif