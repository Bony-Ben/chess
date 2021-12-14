#include <memory>

#ifndef MOVE_H
#define MOVE_H

class Piece;

class Move {
   public:
    Piece *piece;
    int oldRank;
    int oldFile;
    int newRank;
    int newFile;
    Piece *capturedPiece;
    bool check;
    bool castle;
    char promotion;

    Move(Piece *piece, int oldRank, int oldFile, int newRank, int newFile, Piece *capturedPiece, bool check, bool castle, char promotion);
};

#endif