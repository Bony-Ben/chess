#include "game.h"

#include <iostream>

#include "move.h"
#include "players/player.h"

Game::Game(Board &board, Player &white, Player &black) : board{board}, white{white}, black{black} {}

void Game::play() {
    board.notifyObservers();

    char turn = 'W';
    Player *p = &white;
    while (true) {
        history.push_back(p->makeMove(board, turn));
        turn = (turn == 'W') ? 'B' : 'W';
        p = (p == &white) ? &black : &white;
    }
}