#include "game.h"

#include <iostream>

#include "move.h"
#include "players/player.h"

Game::Game(Board &board, Player &white, Player &black) : board{board}, white{white}, black{black} {}

void Game::play() {
    char turn = 'W';
    Player *p = &white;
    while (true) {
        std::cout << board << std::endl;
        history.push_back(p->makeMove(board, turn));
        board.setLastMove(&history.back());
        turn = (turn == 'W') ? 'B' : 'W';
        p = (p == &white) ? &black : &white;
    }
    std::cout << board << std::endl;
}