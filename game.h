#include <memory>
#include <vector>

#include "board.h"
#include "move.h"

#ifndef GAME_H
#define GAME_H

class Player;

class Game {
    Board &board;
    Player &white;
    Player &black;
    char first;
    std::vector<Move> history;

   public:
    Game(Board &board, Player &white, Player &black, char first);
    void play();
    void printResult();
};

#endif