#include "level1.h"

#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "../board.h"
#include "../move.h"
#include "human.h"

void Level1::makeMove(Board &board, std::vector<Move> &moves, char colour) {
    std::string s;
    while (std::cin >> s) {
        if (s == "move") {
            board.makeMove(moves[rand() % moves.size()]);
            return;
        }
    }
    throw EndOfFileException{};    
}
