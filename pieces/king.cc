#include "king.h"

#include "../board.h"
#include "../move.h"

King::King(char colour, int rank, int file, Board *board) : Piece{colour, rank, file, 'k', board} {}

void King::executeWhenMoved(Move &mv){
    canCastle=false;
}

void King::getMoves(std::vector<Move> &moves, bool validateChecks) {
    int horiz[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int vert[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < 8; i++) {
        int newrank = rank + vert[i];
        int newfile = file + horiz[i];
        if (newrank >= 0 && newrank < 8 && newfile >= 0 && newfile < 8) {
            Piece *occupant = board->getSquare(newrank, newfile);
            addMoveIfValid(Move(this, rank, file, newrank, newfile, occupant,  false, false, false), moves, validateChecks);
        }
    }
}

std::unique_ptr<Piece> King::clone(Board * board) const {
    auto ptr = std::make_unique<King>(*this);
    ptr->board = board;
    return ptr;
}
