#ifndef PLAYER_H
#define PLAYER_H

class Board;
class Move;

class Player
{
    char colour;
    Board &board;

public:
    virtual Move play() = 0;
};

#endif