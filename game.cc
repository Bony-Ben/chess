#include "game.h"

#include <iostream>
#include <string>

#include "move.h"
#include "players/player.h"

Game::Game(Board &board, Player &white, Player &black) : board{board}, white{white}, black{black} {}

//Players should not call board.getMoves(), instead they should use the moves provided to them.
void Game::play() {
    board.notifyObservers();

    char turn = 'W';
    std::string colour = "White";
    Player *player = &white;
    Player *opp = &black;

    while (true) {
        std::vector<Move> moves = board.getMoves(turn, true);

        if (moves.size() == 0) {
            if (history.size() > 0 && history.back().check) {
                std::cout << "Checkmate! " << colour << " loses! :(" << std::endl;
            } else {
                std::cout << "Stalemate!" << std::endl;
            }
            break;
        } else if (history.size() > 0 && history.back().check) {
            std::cout << "Check!" << std::endl;
        }

        player->makeMove(board, moves, turn);
        history.push_back(board.getPrevMove());
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
}

void Game::printResult() {
    std::cout << "Final Score:" << std::endl;
    std::cout << "White: " << white.getScore() << std::endl;
    std::cout << "Black: " << black.getScore() << std::endl;
}