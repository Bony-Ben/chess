#include "rook.h"
#include <iostream>

#include "../board.h"
#include "../move.h"

Rook::Rook(char colour, int rank, int file, Board *board, bool canCastle) : Piece{colour, rank, file, 'r', board, 5}, canCastle{canCastle} {}

void Rook::executeWhenMoved(Move &mv){
    canCastle=false;
}

void Rook::getMoves(std::vector<Move> &moves, bool validateChecks) {
    //check for legal moves in upper direction
    for (int i = rank + 1; i < 8; i++) {
        addMoveIfValid(Move(this, rank, file, i, file, board->getSquare(i, file),  false, false, ' '), moves, validateChecks);
        if (board->getSquare(i, file) != nullptr) {
            break;
        }
    }
    //check for legal moves in lower direction
    for (int i = rank - 1; i >= 0; i--) {
        addMoveIfValid(Move(this, rank, file, i, file, board->getSquare(i, file),  false, false, ' '), moves, validateChecks);
        if (board->getSquare(i, file) != nullptr) {
            break;
        }
    }
    //check for legal moves in right direction
    for (int i = file + 1; i < 8; i++) {
        addMoveIfValid(Move(this, rank, file, rank, i, board->getSquare(rank, i),  false, false, ' '), moves, validateChecks);
        if (board->getSquare(rank, i) != nullptr) {
            break;
        }
    }
    //check for legal moves in left direction
    for (int i = file - 1; i >= 0; i--) {
        addMoveIfValid(Move(this, rank, file, rank, i, board->getSquare(rank, i),  false, false, ' '), moves, validateChecks);
        if (board->getSquare(rank, i) != nullptr) {
            break;
        }
    }
}

bool Rook::getCanCastle(){
    return canCastle;
}

std::unique_ptr<Piece> Rook::clone(Board * board) const {
    auto ptr = std::make_unique<Rook>(*this);
    ptr->board = board;
    return ptr;
}