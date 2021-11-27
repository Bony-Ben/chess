#include <memory>
#include <vector>

#include "display/subject.h"
#include "move.h"

#ifndef BOARD_H
#define BOARD_H

class Piece;

class Board : public Subject {
    std::vector<std::unique_ptr<Piece>> pieces;

   public:
    Board();
    std::vector<std::vector<Piece *>> getBoard();
    std::vector<Piece *> getBlackPieces();
    std::vector<Piece *> getWhitePieces();
    std::vector<Move> getBlackMoves();
    std::vector<Move> getWhiteMoves();
    void makeMove(Move &mv);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif