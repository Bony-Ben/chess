#include "human.h"

#include <iostream>
#include <vector>

#include "../board.h"
#include "../move.h"

Move Human::makeMove(Board &board, char colour) {
    std::vector<Move> moves = board.getMoves(colour);
    int x;
    std::cin >> x;
    board.makeMove(moves[x % moves.size()]);
    return moves[x % moves.size()];
}
