#include "queen.h"

#include "../board.h"
#include "../move.h"

Queen::Queen(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'q', board} {}

void Queen::getMoves(std::vector<Move> &moves) {
    // check for legal moves in upper direction
    for (int i = rank + 1; i < 8; i++) {
        moves.emplace_back(*this, rank, file, i, file, board.getSquare(i, file), false, false, false);
        if (board.getSquare(i, file) != nullptr) {
            if (board.getSquare(i, file)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    // check for legal moves in lower direction
    for (int i = rank - 1; i >= 0; i--) {
        moves.emplace_back(*this, rank, file, i, file, board.getSquare(i, file), false, false, false);
        if (board.getSquare(i, file) != nullptr) {
            if (board.getSquare(i, file)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    // check for legal moves in right direction
    for (int i = file + 1; i < 8; i++) {
        moves.emplace_back(*this, rank, file, rank, i, board.getSquare(rank, i), false, false, false);
        if (board.getSquare(rank, i) != nullptr) {
            if (board.getSquare(rank, i)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    // check for legal moves in left direction
    for (int i = file - 1; i >= 0; i--) {
        moves.emplace_back(*this, rank, file, rank, i, board.getSquare(rank, i), false, false, false);
        if (board.getSquare(rank, i) != nullptr) {
            if (board.getSquare(rank, i)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    // check for legal moves in top right direction
    for (int i = rank + 1, j = file + 1; i < 8 && j < 8; i++, j++) {
        moves.emplace_back(*this, rank, file, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    // check for legal moves in top left direction
    for (int i = rank + 1, j = file - 1; i < 8 && j >= 0; i++, j--) {
        moves.emplace_back(*this, rank, file, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    // check for legal moves in bottom right direction
    for (int i = rank - 1, j = file + 1; i >= 0 && j < 8; i--, j++) {
        moves.emplace_back(*this, rank, file, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    // check for legal moves in bottom left direction
    for (int i = rank - 1, j = file - 1; i >= 0 && j >= 0; i--, j--) {
        moves.emplace_back(*this, rank, file, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
}
