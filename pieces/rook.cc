#include "rook.h"

Rook::Rook(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, board} {}

void Rook::getMoves(std::vector<Move> &moves) {
}

char Rook::toChar() {
    if (colour == 'W') {
        return 'R';
    } else {
        return 'r';
    }
}