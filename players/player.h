#ifndef PLAYER_H
#define PLAYER_H

class Board;
class Move;

class Player {
   public:
    virtual Move play(Board &board) = 0;
};

#endif