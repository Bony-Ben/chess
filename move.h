#ifndef MOVE_H
#define MOVE_H

class Piece;

class Move {
    Piece &piece;
    int rank;
    int file;

   public:
    Move(Piece &piece, int rank, int file);
};

#endif