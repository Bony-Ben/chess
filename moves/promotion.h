#include "normalmove.h"

#ifndef PMOVE_H
#define PMOVE_H

class Piece;

class Promotion : public NormalMove {
    Piece &promotedPiece;

   public:
    Promotion(Piece &piece, int oldRank, int oldFile, int newRank, int newFile, Piece *capturedPiece, bool check, Piece &promotedPiece);

    Piece &getPromotedPiece();
    void makeMove(Board &board) override;
    void undo(Board &board) override;
};

#endif