#include "piece.h"

#include <cctype>

Piece::Piece(char colour, int rank, int file, char letter, Board &board) : colour{colour}, rank{rank}, file{file}, letter{letter}, board{board}, captured{false} {}

char Piece::toChar() const {
    return (colour == 'W') ? toupper(letter) : letter;
}

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

void Piece::setRank(int r) {
    rank = r;
}

void Piece::setFile(int f) {
    file = f;
}

void Piece::setCaptured(bool c) {
    captured = c;
}