#include "king.h"

#include <memory>

#include "../board.h"
#include "../move.h"
#include "rook.h"

King::King(char colour, int rank, int file, Board *board, bool canCastle) : Piece{colour, rank, file, 'k', board, 1000}, canCastle{canCastle} {}

void King::executeWhenUndoed(Move &mv) {
    if (mv.loseCastleRightsMove) {
        canCastle = true;
    }
}

void King::executeWhenMoved(Move &mv) {
    if (canCastle) {
        mv.loseCastleRightsMove = true;
        canCastle = false;
    }
}

void King::getMoves(std::vector<Move> &moves, bool validateChecks) {
    int horiz[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int vert[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < 8; i++) {
        int newrank = rank + vert[i];
        int newfile = file + horiz[i];
        if (newrank >= 0 && newrank < 8 && newfile >= 0 && newfile < 8) {
            Piece *occupant = board->getSquare(newrank, newfile);
            addMoveIfValid(Move(this, rank, file, newrank, newfile, occupant, false, false, ' '), moves, validateChecks);
        }
    }
    if (canCastle && validateChecks && !board->isCheck(colour == 'B' ? 'W' : 'B')) {
        int castleRank = 0;
        if (colour == 'B') {
            castleRank = 7;
        }
        Rook *aRook = dynamic_cast<Rook *>(board->getSquare(castleRank, 0));
        Rook *hRook = dynamic_cast<Rook *>(board->getSquare(castleRank, 7));
        if (board->getSquare(castleRank, 5) == nullptr && board->getSquare(castleRank, 6) == nullptr && hRook != nullptr && hRook->getCanCastle()) {
            auto tempBoard = board->getBoardAfterMove(Move(this, rank, file, castleRank, 5, nullptr, false, false, ' '));
            if (!tempBoard->isCheck(colour == 'B' ? 'W' : 'B')) {
                addMoveIfValid(Move(this, rank, file, castleRank, 6, nullptr, false, true, ' '), moves, validateChecks);
            }
        }
        if (board->getSquare(castleRank, 3) == nullptr && board->getSquare(castleRank, 2) == nullptr &&
            board->getSquare(castleRank, 1) == nullptr && aRook != nullptr && aRook->getCanCastle()) {
            auto tempBoard = board->getBoardAfterMove(Move(this, rank, file, castleRank, 3, nullptr, false, false, ' '));
            if (!tempBoard->isCheck(colour == 'B' ? 'W' : 'B')) {
                addMoveIfValid(Move(this, rank, file, castleRank, 2, nullptr, false, true, ' '), moves, validateChecks);
            }
        }
    }
}

std::unique_ptr<Piece> King::clone(Board *board) const {
    auto ptr = std::make_unique<King>(*this);
    ptr->board = board;
    return ptr;
}
