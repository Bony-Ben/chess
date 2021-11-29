#include "queen.h"

#include "../board.h"
#include "../move.h"

Queen::Queen(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'q', board} {}

void Queen::getMoves(std::vector<Move> &moves) {
}
