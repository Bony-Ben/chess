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
    bool checkmate;
    bool stalemate;

    Move(Piece &piece, int oldRank, int oldFile,int newRank,int newFile, Piece *captured, bool check, bool checkmate, bool stalemate);
};

#endif