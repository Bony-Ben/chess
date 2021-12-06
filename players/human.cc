#include "human.h"

#include <iostream>
#include <string>
#include <vector>

#include "../board.h"
#include "../move.h"

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
            
            if (startRank >= 0 && startRank <= 7 &&
                startFile >= 0 && startFile <= 7 &&
                endRank >= 0 && endRank <= 7 &&
                endFile >= 0 && endFile <= 7 &&
                board.getSquare(startRank, startFile) != nullptr) {

                std::vector<Move> moves;
                board.getSquare(startRank, startFile)->getMoves(moves, true);
                for (int i = 0; i < (int)moves.size(); i++) {
                    if (moves[i].newRank == endRank && moves[i].newFile == endFile) {
                        board.makeMove(moves[i]);
                        return;
                    }
                }
            }
            std::cout << "Invalid Move!" << std ::endl;
        }
    }
}
