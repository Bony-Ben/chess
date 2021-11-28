#include "piece.h"

Piece::Piece(char colour, int rank, int file, Board &board) : colour{colour}, rank{rank}, file{file}, board{board}, captured{false} {}

char Piece::getColour() const {
    return colour;
}

int Piece::getRank() const {
    return rank;
}

int Piece::getFile() const {
    return file;
}

bool Piece::isCaptured() const {
    return captured;
}