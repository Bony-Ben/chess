#include "king.h"

#include "../board.h"
#include "../move.h"

King::King(char colour, int rank, int file, Board *board) : Piece{colour, rank, file, 'k', board} {}

void King::getMoves(std::vector<Move> &moves, bool validateChecks) {
}

std::unique_ptr<Piece> King::clone(Board * board) const {
    auto ptr = std::make_unique<King>(*this);
    ptr->board = board;
    return ptr;
}
