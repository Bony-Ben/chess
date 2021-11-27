#include <memory>
#include <vector>

#include "board.h"
#include "move.h"

#ifndef GAME_H
#define GAME_H

class Player;

class Game {
    Board board;
    std::unique_ptr<Player> white;
    std::unique_ptr<Player> black;
    std::vector<Move> history;
};

#endif