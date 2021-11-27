#include <memory>

#ifndef MOVE_H
#define MOVE_H

class Piece;

class Move {
    Piece &piece;
    int rank;
    int file;
    Piece *captured;
    bool check;
    bool checkmate;

   public:
    Move(Piece &piece, int rank, int file, Piece *captured, bool check, bool checkmate);
};

#endif