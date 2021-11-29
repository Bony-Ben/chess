#include <memory>

#ifndef MOVE_H
#define MOVE_H

class Piece;

struct Move {
    Piece &piece;
    int oldRank;
    int oldFile;
    int newRank;
    int newFile;
    Piece *captured;
    bool check;
    bool castle;
    bool promotion;

    Move(Piece &piece, int oldRank, int oldFile, int newRank, int newFile, Piece *captured, bool check, bool castle, bool promotion);
};

#endif