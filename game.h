#include <memory>
#include <vector>

#include "board.h"
#include "moves/move.h"

#ifndef GAME_H
#define GAME_H

class Player;

class Game {
    Board &board;
    Player &white;
    Player &black;
    std::vector<std::unique_ptr<Move>> history;

   public:
    Game(Board &board, Player &white, Player &black);
    void play();
    void printResult();
};

#endif