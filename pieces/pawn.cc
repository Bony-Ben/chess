#include "pawn.h"

#include "../board.h"
#include "../move.h"

Pawn::Pawn(char colour, int rank, int file, Board *board) : Piece{colour, rank, file, 'p', board, 1} {}

void Pawn::getMoves(std::vector<Move> &moves, bool validateChecks) {
    int direction = -1;
    int firstMove = 6;
    if (colour == 'W') {
        direction = 1;
        firstMove = 1;
    }

    // std::cout << rank << " " << file << std::endl;

    // one step forwards
    if ((board->getSquare(rank + direction, file) == nullptr) && ((direction == -1 && rank > 0) || (direction == 1 && rank < 7))) {
        addMoveIfValid(Move(this, rank, file, rank + direction, file, nullptr, false, false, false), moves, validateChecks);
    }

    // first move- two steps forwards
    if (rank == firstMove && board->getSquare(rank + 2 * direction, file) == nullptr && board->getSquare(rank + direction, file) == nullptr) {
        addMoveIfValid(Move(this, rank, file, rank + 2 * direction, file, nullptr, false, false, false), moves, validateChecks);
    }

    // capturing
    if (direction == 1 && rank < 7) {
        if (file < 7 && board->getSquare(rank + 1, file + 1) != nullptr && board->getSquare(rank + 1, file + 1)->getColour() == 'B') {  // right
            addMoveIfValid(Move(this, rank, file, rank + 1, file + 1, board->getSquare(rank + 1, file + 1), false, false, false), moves, validateChecks);
        } 
        if (file > 0 && board->getSquare(rank + 1, file - 1) != nullptr && board->getSquare(rank + 1, file - 1)->getColour() == 'B') {  // left
            addMoveIfValid(Move(this, rank, file, rank + 1, file - 1, board->getSquare(rank + 1, file - 1), false, false, false), moves, validateChecks);
        }
    } 
    if (direction == -1 && rank > 0) {
        if (file < 7 && board->getSquare(rank - 1, file - 1) != nullptr && board->getSquare(rank - 1, file - 1)->getColour() == 'W') {  // left
            addMoveIfValid(Move(this, rank, file, rank - 1, file - 1, board->getSquare(rank - 1, file - 1), false, false, false), moves, validateChecks);
        } 
        if (file > 0 && board->getSquare(rank - 1, file + 1) != nullptr && board->getSquare(rank - 1, file + 1)->getColour() == 'W') {  // right
            addMoveIfValid(Move(this, rank, file, rank - 1, file + 1, board->getSquare(rank - 1, file + 1), false, false, false), moves, validateChecks);
        }
    }

    // promotion
    if (direction == -1 && file == 0) {  // black promotion

    } 
    if (direction == 1 && file == 7) {  // white promotion
    }

    // en passant: TODO
}

std::unique_ptr<Piece> Pawn::clone(Board *board) const {
    auto ptr = std::make_unique<Pawn>(*this);
    ptr->board = board;
    return ptr;
}
