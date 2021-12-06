#include "human.h"

#include <iostream>
#include <string>
#include <vector>

#include "../board.h"
#include "../moves/move.h"

void Human::makeMove(Board &board, char colour) {
    std::string s;
    while (std::cin >> s) {
        if (s == "move") {
            std::cin >> s;
            int startRank = s[1] - '1';
            int startFile = s[0] - 'a';
            std::cin >> s;
            int endRank = s[1] - '1';
            int endFile = s[0] - 'a';

            std::vector<std::unique_ptr<Move>> moves;
            board.getSquare(startRank, startFile)->getMoves(moves);
            for (int i = 0; i < (int)moves.size(); i++) {
                if (moves[i].newRank == endRank && moves[i].newFile == endFile) {
                    board.makeMove(moves[i]);
                    return;
                }
            }
            std::cout << "Invalid Move!" << std ::endl;
        }
    }
}
