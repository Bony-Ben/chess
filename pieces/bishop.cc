#include "bishop.h"

#include "../board.h"
#include "../move.h"

Bishop::Bishop(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'b', board} {}

void Bishop::getMoves(std::vector<Move> &moves) {
    //check for legal moves in top right direction
    for (int i = rank + 1, j = file + 1; i < 8 && j < 8; i++, j++) {
        moves.emplace_back(*this, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    //check for legal moves in top left direction
    for (int i = rank + 1, j = file - 1; i < 8 && j >= 0; i++, j--) {
        moves.emplace_back(*this, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    //check for legal moves in bottom right direction
    for (int i = rank - 1, j = file + 1; i >= 0 && j < 8; i--, j++) {
        moves.emplace_back(*this, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
    //check for legal moves in bottom left direction
    for (int i = rank - 1, j = file - 1; i >= 0 && j >= 0; i--, j--) {
        moves.emplace_back(*this, i, j, board.getSquare(i, j), false, false, false);
        if (board.getSquare(i, j) != nullptr) {
            if (board.getSquare(i, j)->getColour() == colour) {
                moves.pop_back();
            }
            break;
        }
    }
}
