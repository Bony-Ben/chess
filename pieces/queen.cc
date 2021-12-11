#include "queen.h"

#include "../board.h"
#include "../move.h"

Queen::Queen(char colour, int rank, int file, Board *board) : Piece{colour, rank, file, 'q', board, 9} {}

void Queen::getMoves(std::vector<Move> &moves, bool validateChecks) {
    // check for legal moves in upper direction
    for (int i = rank + 1; i < 8; i++) {
        addMoveIfValid(Move(this, rank, file, i, file, board->getSquare(i, file),  false, false, false), moves, validateChecks);
        if (board->getSquare(i, file) != nullptr) {
            break;
        }
    }
    // check for legal moves in lower direction
    for (int i = rank - 1; i >= 0; i--) {
        addMoveIfValid(Move(this, rank, file, i, file, board->getSquare(i, file),  false, false, false), moves, validateChecks);
        if (board->getSquare(i, file) != nullptr) {
            break;
        }
    }
    // check for legal moves in right direction
    for (int i = file + 1; i < 8; i++) {
        addMoveIfValid(Move(this, rank, file, rank, i, board->getSquare(rank, i),  false, false, false), moves, validateChecks);
        if (board->getSquare(rank, i) != nullptr) {
            break;
        }
    }
    // check for legal moves in left direction
    for (int i = file - 1; i >= 0; i--) {
        addMoveIfValid(Move(this, rank, file, rank, i, board->getSquare(rank, i),  false, false, false), moves, validateChecks);
        if (board->getSquare(rank, i) != nullptr) {
            break;
        }
    }
    // check for legal moves in top right direction
    for (int i = rank + 1, j = file + 1; i < 8 && j < 8; i++, j++) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j),  false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
    // check for legal moves in top left direction
    for (int i = rank + 1, j = file - 1; i < 8 && j >= 0; i++, j--) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j),  false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
    // check for legal moves in bottom right direction
    for (int i = rank - 1, j = file + 1; i >= 0 && j < 8; i--, j++) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j),  false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
    // check for legal moves in bottom left direction
    for (int i = rank - 1, j = file - 1; i >= 0 && j >= 0; i--, j--) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j),  false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
}

std::unique_ptr<Piece> Queen::clone(Board * board) const {
    auto ptr = std::make_unique<Queen>(*this);
    ptr->board = board;
    return ptr;
}
