#include <memory>

#include "board.h"

#ifndef GAME_H
#define GAME_H

class Player;

class Game {
    Board board;
    std::unique_ptr<Player> white;
    std::unique_ptr<Player> black;
};

#endif