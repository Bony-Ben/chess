#ifndef PLAYER_H
#define PLAYER_H

class Board;
class Move;

class Player {
   protected:
    char colour;

   public:
    virtual Move play(Board &board) = 0;
};

#endif