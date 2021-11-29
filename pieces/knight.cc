#include "knight.h"

#include "../board.h"
#include "../move.h"

Knight::Knight(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'n', board} {}

void Knight::getMoves(std::vector<Move> &moves) {
}
