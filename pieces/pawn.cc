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

    // one step forwards
    if ((board->getSquare(rank + direction, file) == nullptr) && ((direction == -1 && rank > 1) || (direction == 1 && rank < 6))) {
        addMoveIfValid(Move(this, rank, file, rank + direction, file, nullptr, false, false, ' '), moves, validateChecks);
    }

    // first move- two steps forwards
    if (rank == firstMove && board->getSquare(rank + 2 * direction, file) == nullptr && board->getSquare(rank + direction, file) == nullptr) {
        addMoveIfValid(Move(this, rank, file, rank + 2 * direction, file, nullptr, false, false, ' '), moves, validateChecks);
    }

    // capturing
    if (direction == 1 && rank < 7) {
      if (file < 7 && board->getSquare(rank + 1, file + 1) != nullptr && board->getSquare(rank + 1, file + 1)->getColour() == 'B') {  // right
        if (rank == 6) {
          addMoveIfValid(Move(this, rank, file, rank + 1, file + 1, board->getSquare(rank + 1, file + 1), false, false, ' '), moves, validateChecks);
        } else {
          addMoveIfValid(Move(this, rank, file, rank + 1, file + 1, board->getSquare(rank + 1, file + 1), false, false, ' '), moves, validateChecks);
        }
      } 
      if (file > 0 && board->getSquare(rank + 1, file - 1) != nullptr && board->getSquare(rank + 1, file - 1)->getColour() == 'B') {  // left
        if (rank == 6) {
          addMoveIfValid(Move(this, rank, file, rank + 1, file - 1, board->getSquare(rank + 1, file - 1), false, false, ' '), moves, validateChecks);
        } else {
          addMoveIfValid(Move(this, rank, file, rank + 1, file - 1, board->getSquare(rank + 1, file - 1), false, false, ' '), moves, validateChecks);
        }
      }
      
    } 
    if (direction == -1 && rank > 0) {
      if (file > 0 && board->getSquare(rank - 1, file - 1) != nullptr && board->getSquare(rank - 1, file - 1)->getColour() == 'W') {  // left
        if (rank == 1) { // capture and promote
          addMoveIfValid(Move(this, rank, file, rank - 1, file - 1, board->getSquare(rank - 1, file - 1), false, false, ' '), moves, validateChecks);
        } else {
          addMoveIfValid(Move(this, rank, file, rank - 1, file - 1, board->getSquare(rank - 1, file - 1), false, false, ' '), moves, validateChecks);
        }
      } 
      if (file < 7 && board->getSquare(rank - 1, file + 1) != nullptr && board->getSquare(rank - 1, file + 1)->getColour() == 'W') {  // right
        if (rank == 1) { // capture and promote
          addMoveIfValid(Move(this, rank, file, rank - 1, file + 1, board->getSquare(rank - 1, file + 1), false, false, ' '), moves, validateChecks);
        } else {
          addMoveIfValid(Move(this, rank, file, rank - 1, file + 1, board->getSquare(rank - 1, file + 1), false, false, ' '), moves, validateChecks);
        }
      }
    }

    // promotion without capturing
    if (direction == -1 && rank == 1 && board->getSquare(rank - 1, file) == nullptr) {  // black promotion
      addMoveIfValid(Move(this, rank, file, rank - 1, file, board->getSquare(rank - 1, file), false, false, ' '), moves, validateChecks);
    } 
    if (direction == 1 && rank == 6 && (board->getSquare(rank + 1, file) == nullptr)) {  // white promotion
      addMoveIfValid(Move(this, rank, file, rank + 1, file, board->getSquare(rank + 1, file), false, false, ' '), moves, validateChecks);
    }

    // en passant:
    if (direction == -1 && rank == 3) { 
      Move prev = board->getPrevMove();
      if (file < 7 && board->getSquare(rank, file + 1) != nullptr && board->getSquare(rank, file + 1)->getColour() ==  'W') { // right
        if (prev.oldRank == 1 && prev.oldFile == file + 1 && (prev.piece->getLetter() == 'p' || prev.piece->getLetter() == 'P')) {
          addMoveIfValid(Move(this, rank, file, 2, file + 1, board->getSquare(rank, file + 1),  false, false, ' '), moves, validateChecks);
        }
      } 
      if (file > 0 && board->getSquare(rank, file - 1) != nullptr && board->getSquare(rank, file - 1)->getColour() ==  'W') { // left
        if (prev.oldRank == 1 && prev.oldFile == file - 1 && (prev.piece->getLetter() == 'p' || prev.piece->getLetter() == 'P')) {
          addMoveIfValid(Move(this, rank, file, 2, file - 1, board->getSquare(rank, file - 1),  false, false, ' '), moves, validateChecks);
        }
      }
    } 
    if (direction == 1 && rank == 4) {
      Move prev = board->getPrevMove();
      if (file < 7 && board->getSquare(rank, file + 1) != nullptr && board->getSquare(rank, file + 1)->getColour() ==  'B') { // right
        if (prev.oldRank == 6 && prev.oldFile == file + 1 && (prev.piece->getLetter() == 'p' || prev.piece->getLetter() == 'P')) {
          addMoveIfValid(Move(this, rank, file, 5, file + 1, board->getSquare(4, file + 1),  false, false, ' '), moves, validateChecks);
        }
      } 
      if (file > 0 && board->getSquare(rank, file - 1) != nullptr && board->getSquare(rank, file - 1)->getColour() ==  'B') { // left
        if (prev.oldRank == 6 && prev.oldFile == file - 1 && (prev.piece->getLetter() == 'p' || prev.piece->getLetter() == 'P')) {
          addMoveIfValid(Move(this, rank, file, 5, file - 1, board->getSquare(rank, file - 1),  false, false, ' '), moves, validateChecks);
        }
      }
    }

}

std::unique_ptr<Piece> Pawn::clone(Board *board) const {
    auto ptr = std::make_unique<Pawn>(*this);
    ptr->board = board;
    return ptr;
}
