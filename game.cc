#include "game.h"

#include <iostream>
#include <string>

#include "move.h"
#include "players/player.h"

Game::Game(Board &board, Player &white, Player &black, char first) : board{board}, white{white}, black{black}, first{first} {}

// Players should not call board.getMoves(), instead they should use the moves provided to them.
void Game::play(double &whiteScore, double &blackScore) {
    board.notifyObservers();
    char turn;
    std::string colour;
    Player *player, *opp;

    if (first == 'W') {
        turn = 'W';
        colour = "White";
        player = &white;
        opp = &black;
    } else {
        turn = 'B';
        colour = "Black";
        player = &black;
        opp = &white;
    }

    while (true) {
        std::vector<Move> moves = board.getMoves(turn, true);

        if (moves.size() == 0) {
            if (history.size() > 0 && history.back().check) {
                std::cout << "Checkmate! " << colour << " loses! :(" << std::endl;
                if (turn == 'W') {
                    blackScore += 1;
                } else {
                    whiteScore += 1;
                }
            } else {
                std::cout << "Stalemate!" << std::endl;
                blackScore += 0.5;
                whiteScore += 0.5;
            }
            break;
        } else if (history.size() > 0 && history.back().check) {
            std::cout << colour << " is in check!" << std::endl;
        }
        std::cout << colour << "'s turn: ";  // for debugging
        player->makeMove(board, moves, turn);
        history.push_back(board.getPrevMove());
        std::swap(player, opp);
        if (turn == 'W') {
            turn = 'B';
            colour = "Black";
        } else {
            turn = 'W';
            colour = "White";
        }
    }
    std::string temp;
    std::cin >> temp;
}
