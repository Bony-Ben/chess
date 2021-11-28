#include "game.h"

#include <iostream>

#include "move.h"
#include "players/player.h"

Game::Game(Board &board, Player &white, Player &black) : board{board}, white{white}, black{black} {}

void Game::play() {
    while (true) {
        std::cout << board << std::endl;
        history.push_back(white.makeMove(board, 'W'));
        std::cout << board << std::endl;
        history.push_back(black.makeMove(board, 'B'));
    }
    std::cout << board << std::endl;
}