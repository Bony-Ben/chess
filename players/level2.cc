#include "level2.h"

#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "../board.h"
#include "../inputparser.h"
#include "../move.h"
#include "human.h"

void Level2::makeMove(Board &board, std::vector<Move> &moves, char colour) {
    std::string s;
    while (std::getline(std::cin, s)) {
        try {
            std::vector<std::string> input = parseLine(s);
            if (input.size() == 0) {
                throw InputException{};
            }
            s = input.at(0);
            if (s == "move") {
                std::vector<Move> checksAndCaptures;
                for (int i = 0; i < (int)moves.size(); i++) {
                    if (moves[i].capturedPiece != nullptr || moves[i].check || moves[i].castle) {
                        checksAndCaptures.push_back(moves[i]);
                    }
                }
                if (checksAndCaptures.size() == 0) {
                    board.makeMove(moves[rand() % moves.size()]);
                } else {
                    board.makeMove(checksAndCaptures[rand() % checksAndCaptures.size()]);
                }
                return;
            } else {
                throw InputException{};
            }
        } catch (InputException i) {
            std::cout << "Invalid Input! Please try again." << std ::endl;
        }
    }
    throw EndOfFileException{};
}
