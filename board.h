#include <memory>
#include <vector>

#include "display/subject.h"
#include "move.h"
#include "pieces/piece.h"

#ifndef BOARD_H
#define BOARD_H

class Board : public Subject {
    std::vector<std::unique_ptr<Piece>> pieces;
    Piece *board[8][8];
    std::unique_ptr<Move>prevMove;

    void updateBoard();

   public:
    Board();
    Move getPrevMove();
    Piece *getSquare(int rank, int file);
    std::vector<Move> getMoves(char colour) const;
    void makeMove(Move &mv);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif