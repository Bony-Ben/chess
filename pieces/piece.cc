#include "piece.h"

#include <cctype>
#include <iostream>

#include "../board.h"
#include "../move.h"
#include "king.h"

Piece::Piece(char colour, int rank, int file, char letter, Board *board) : colour{colour}, rank{rank}, file{file}, letter{letter}, board{board}, captured{false} {}

void Piece::addMoveIfValid(Move mv, std::vector<Move> &moves, bool validateChecks) {
    if (mv.capturedPiece != nullptr && colour == mv.capturedPiece->colour) {
        return;
    }
    if (!validateChecks) {
        moves.push_back(mv);
        return;
    }

    Board tempBoard = *board;
    Move tempMove = mv;
    tempMove.piece = tempBoard.getSquare(mv.oldRank, mv.oldFile);
    if (mv.capturedPiece != nullptr) {
        tempMove.capturedPiece = tempBoard.getSquare(mv.capturedPiece->rank, mv.capturedPiece->file);
    }
    tempBoard.makeMove(tempMove);

    //std::cout << tempBoard << std::endl;

    std::vector<Move> whiteMoves = tempBoard.getMoves('W', false);
    bool whiteCheck = false;
    for (int i = 0; i < (int)whiteMoves.size(); i++) {
        if (dynamic_cast<King *>(whiteMoves[i].capturedPiece) != nullptr) {
            whiteCheck = true;
            break;
        }
    }

    std::vector<Move> blackMoves = tempBoard.getMoves('B', false);
    bool blackCheck = false;
    for (int i = 0; i < (int)blackMoves.size(); i++) {
        if (dynamic_cast<King *>(blackMoves[i].capturedPiece) != nullptr) {
            blackCheck = true;
            break;
        }
    }

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

void Piece::setRank(int r) {
    rank = r;
}

void Piece::setFile(int f) {
    file = f;
}

void Piece::setCaptured(bool c) {
    captured = c;
}