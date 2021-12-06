#include "move.h"

Move::Move(Piece *piece, int oldRank, int oldFile, int newRank, int newFile, Piece *capturedPiece, bool check, bool castle, bool promotion)
    : piece{piece}, oldRank{oldRank}, oldFile{oldFile}, newRank{newRank}, newFile{newFile}, capturedPiece{capturedPiece}, check{check}, castle{castle}, promotion{promotion} {}