#include "king.h"

#include "../board.h"
#include "../moves/move.h"

King::King(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'k', board} {}

void King::getMoves(std::vector<std::unique_ptr<Move>> &moves) {
}
