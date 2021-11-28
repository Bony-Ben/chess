#include "level1.h"

#include <vector>

#include "../board.h"
#include "../move.h"

Move Level1::makeMove(Board &board, char colour) {
    std::vector<Move> moves = board.getMoves(colour);
    board.makeMove(moves[rand() % moves.size()]);
    return moves[rand() % moves.size()];
}
