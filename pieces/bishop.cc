#include "bishop.h"

#include "../board.h"
#include "../move.h"

Bishop::Bishop(char colour, int rank, int file, Board *board) : Piece{colour, rank, file, 'b', board} {}

void Bishop::getMoves(std::vector<Move> &moves, bool validateChecks) {
    //check for legal moves in top right direction
    for (int i = rank + 1, j = file + 1; i < 8 && j < 8; i++, j++) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j), false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
    //check for legal moves in top left direction
    for (int i = rank + 1, j = file - 1; i < 8 && j >= 0; i++, j--) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j), false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
    //check for legal moves in bottom right direction
    for (int i = rank - 1, j = file + 1; i >= 0 && j < 8; i--, j++) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j), false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
    //check for legal moves in bottom left direction
    for (int i = rank - 1, j = file - 1; i >= 0 && j >= 0; i--, j--) {
        addMoveIfValid(Move(this, rank, file, i, j, board->getSquare(i, j), false, false, false), moves, validateChecks);
        if (board->getSquare(i, j) != nullptr) {
            break;
        }
    }
}

std::unique_ptr<Piece> Bishop::clone(Board *board) const {
    auto ptr = std::make_unique<Bishop>(*this);
    ptr->board = board;
    return ptr;
}
