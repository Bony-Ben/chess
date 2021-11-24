#include "rook.h"

Rook::Rook(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, board} {}

std::vector<Move> Rook::getMoves() {
    std::vector<Move> ans;
    return ans;
}