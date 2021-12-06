#include "game.h"

#include <iostream>
#include <string>
#include <memory>

#include "moves/move.h"
#include "players/player.h"

Game::Game(Board &board, Player &white, Player &black) : board{board}, white{white}, black{black} {}

void Game::play() {
    board.notifyObservers();

    char turn = 'W';
    std::string colour = "White";
    Player *player = &white;
    Player *opp = &black;

    while (true) {
        player->makeMove(board, turn);
        history.push_back(std::make_unique<Move>(*board.getPrevMove()));
        if (turn == 'W') {
            turn = 'B';
            opp = player;
            player = &black;
            colour = "Black";
        } else {
            turn = 'W';
            opp = player;
            player = &white;
            colour = "White";
        }
    }
    printResult();
}

void Game::printResult() {
    std::cout << "Final Score:" << std::endl;
    std::cout << "White: " << white.getScore() << std::endl;
    std::cout << "Black: " << black.getScore() << std::endl;
}