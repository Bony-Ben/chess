#include "piece.h"

#include <cctype>
#include <iostream>
#include <memory>

#include "../board.h"
#include "../move.h"
#include "king.h"

Piece::Piece(char colour, int rank, int file, char letter, Board *board, int value) : colour{colour}, rank{rank}, file{file}, letter{letter}, board{board}, value{value}, captured{false} {}

void Piece::executeWhenMoved(Move &mv) {}

void Piece::addMoveIfValid(Move mv, std::vector<Move> &moves, bool validateChecks) {
    if (mv.capturedPiece != nullptr && colour == mv.capturedPiece->colour) {
        return;
    }
    if (!validateChecks) {
        moves.push_back(mv);
        return;
    }
    auto tempBoard = board->getBoardAfterMove(mv);

    bool whiteCheck = tempBoard->isCheck('W');
    bool blackCheck = tempBoard->isCheck('B');

    if (colour == 'W' && !blackCheck) {
        mv.check = whiteCheck;
        moves.push_back(mv);
    } else if (colour == 'B' && !whiteCheck) {
        mv.check = blackCheck;
        moves.push_back(mv);
    }
}

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

char Piece::getLetter() const {
    return (colour == 'W') ? toupper(letter) : letter;
}

bool Piece::isCaptured() const {
    return captured;
}

int Piece::getValue() const {
    return value;
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