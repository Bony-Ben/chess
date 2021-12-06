#include "rook.h"
#include <iostream>

#include "../board.h"
#include "../move.h"

Rook::Rook(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'r', board} {}

void Rook::getMoves(std::vector<Move> &moves, bool validateChecks) {
    //check for legal moves in upper direction
    for (int i = rank + 1; i < 8; i++) {
        Move x=Move(this, rank, file, i, file, board.getSquare(i, file),  false, false, false);
        addMoveIfValid(Move(this, rank, file, i, file, board.getSquare(i, file),  false, false, false), moves, validateChecks);
        if (board.getSquare(i, file) != nullptr) {
            break;
        }
    }
    //check for legal moves in lower direction
    for (int i = rank - 1; i >= 0; i--) {
        addMoveIfValid(Move(this, rank, file, i, file, board.getSquare(i, file),  false, false, false), moves, validateChecks);
        if (board.getSquare(i, file) != nullptr) {
            break;
        }
    }
    //check for legal moves in right direction
    for (int i = file + 1; i < 8; i++) {
        addMoveIfValid(Move(this, rank, file, rank, i, board.getSquare(rank, i),  false, false, false), moves, validateChecks);
        if (board.getSquare(rank, i) != nullptr) {
            break;
        }
    }
    //check for legal moves in left direction
    for (int i = file - 1; i >= 0; i--) {
        addMoveIfValid(Move(this, rank, file, rank, i, board.getSquare(rank, i),  false, false, false), moves, validateChecks);
        if (board.getSquare(rank, i) != nullptr) {
            break;
        }
    }
}

std::unique_ptr<Piece> Rook::clone() const {
    return std::make_unique<Rook>(*this);
}