#include "piece.h"

#include <cctype>
#include <iostream>

Piece::Piece(char colour, int rank, int file, char letter, Board &board) : colour{colour}, rank{rank}, file{file}, letter{letter}, board{board}, captured{false} {}

std::ostream &operator<<(std::ostream &out, const Piece &p) {
    out << (char)((p.colour == 'W') ? toupper(p.letter) : p.letter);
    return out;
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