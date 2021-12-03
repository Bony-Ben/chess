#include "knight.h"

#include <iostream>

#include "../board.h"
#include "../move.h"

Knight::Knight(char colour, int rank, int file, Board &board) : Piece{colour, rank, file, 'n', board} {}

void Knight::getMoves(std::vector<Move> &moves) {
    int horiz[8] = {1, 1, 2, 2, -1, -1, -2, -2};
    int vert[8] = {2, -2, 1, -1, 2, -2, 1, -1};
    for (int i = 0; i < 8; i++) {
        int newrank = rank + vert[i];
        int newfile = file + horiz[i];
        if (newrank >= 0 && newrank < 8 && newfile >= 0 && newfile < 8) {
            Piece *occupant = board.getSquare(newrank, newfile);
            moves.emplace_back(*this, rank, file, newrank, newfile, occupant, false, false, false);
            if (occupant != nullptr) {
                if (occupant->getColour() == colour) {
                    moves.pop_back();
                }
            }
        }
    }
}
