#include <memory>

#ifndef MOVE_H
#define MOVE_H

class Piece;

struct Move {
    Piece &piece;
    int rank;
    int file;
    Piece *captured;
    bool check;
    bool checkmate;
    bool stalemate;

    Move(Piece &piece, int rank, int file, Piece *captured, bool check, bool checkmate, bool stalemate);
};

#endif