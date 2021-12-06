#include "pawn.h"

#include "../board.h"
#include "../move.h"

Pawn::Pawn(char colour, int rank, int file, Board *board) : Piece{colour, rank, file, 'p', board} {}

void Pawn::getMoves(std::vector<Move> &moves, bool validateChecks) {
}

std::unique_ptr<Piece> Pawn::clone(Board * board) const {
    auto ptr = std::make_unique<Pawn>(*this);
    ptr->board = board;
    return ptr;
}
