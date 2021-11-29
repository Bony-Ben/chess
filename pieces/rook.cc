#include "rook.h"

#include "../board.h"
#include "../move.h"

Rook::Rook(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'r', board} {}

void Rook::getMoves(std::vector<Move> &moves) {
    //check for legal moves in upper direction
    for (int i = rank + 1; i < 8; i++) {
        moves.emplace_back(*this, rank, file, i, file, board.getSquare(i, file), false, false, false);
        if (board.getSquare(i, file) != nullptr) {
            if (board.getSquare(i, file)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    //check for legal moves in lower direction
    for (int i = rank - 1; i >= 0; i--) {
        moves.emplace_back(*this, rank, file, i, file, board.getSquare(i, file), false, false, false);
        if (board.getSquare(i, file) != nullptr) {
            if (board.getSquare(i, file)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    //check for legal moves in right direction
    for (int i = file + 1; i < 8; i++) {
        moves.emplace_back(*this, rank, file, rank, i, board.getSquare(rank, i), false, false, false);
        if (board.getSquare(rank, i) != nullptr) {
            if (board.getSquare(rank, i)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    //check for legal moves in left direction
    for (int i = file - 1; i >= 0; i--) {
        moves.emplace_back(*this, rank, file, rank, i, board.getSquare(rank, i), false, false, false);
        if (board.getSquare(rank, i) != nullptr) {
            if (board.getSquare(rank, i)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
}
