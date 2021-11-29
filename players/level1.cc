#include "level1.h"

#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "../board.h"
#include "../move.h"

void Level1::makeMove(Board &board, char colour) {
    std::string s;
    while (std::cin >> s && s != "move") {
    }

    std::vector<Move> moves = board.getMoves(colour);
    board.makeMove(moves[rand() % moves.size()]);
}
