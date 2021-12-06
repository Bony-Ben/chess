#include "move.h"

#ifndef NMOVE_H
#define NMOVE_H

class Piece;

class NormalMove : public Move {
    Piece &piece;
    int oldRank;
    int oldFile;
    int newRank;
    int newFile;
    Piece *capturedPiece;

   public:
    NormalMove(Piece &piece, int oldRank, int oldFile, int newRank, int newFile, Piece *capturedPiece, bool check);

    Piece &getPiece();
    int getOldRank();
    int getOldFile();
    int getNewRank();
    int getNewFile();
    Piece *getCapturedPiece();

    virtual void makeMove(Board &board) override;
    virtual void undo(Board &board) override;
};

#endif