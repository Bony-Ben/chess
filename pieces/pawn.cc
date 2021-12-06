#include "pawn.h"

#include "../board.h"
#include "../moves/move.h"

Pawn::Pawn(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'p', board} {}

void Pawn::getMoves(std::vector<std::unique_ptr<Move>> &moves) {
}
