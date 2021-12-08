#include "level2.h"

#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "../board.h"
#include "../move.h"

void Level2::makeMove(Board &board, std::vector<Move> &moves, char colour) {
    std::string s;
    while (std::cin >> s && s != "move") {
    }

    std::vector<Move> checksAndCaptures;
    for (int i = 0; i < (int)moves.size(); i++) {
        if (moves[i].capturedPiece != nullptr || moves[i].check) {
            checksAndCaptures.push_back(moves[i]);
        }
    }
    if (checksAndCaptures.size() == 0) {
        board.makeMove(moves[rand() % moves.size()]);
    } else {
        board.makeMove(checksAndCaptures[rand() % checksAndCaptures.size()]);
    }
}
