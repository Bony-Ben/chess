#include <memory>
#include <vector>

#include "display/subject.h"
#include "move.h"
#include "pieces/piece.h"

#ifndef BOARD_H
#define BOARD_H

class Board : public Subject {
    std::vector<std::unique_ptr<Piece>> pieces;

   public:
    Board();
    std::vector<std::vector<Piece *>> getBoard() const;
    std::vector<Piece *> getBlackPieces() const;
    std::vector<Piece *> getWhitePieces() const;
    std::vector<Move> getBlackMoves() const;
    std::vector<Move> getWhiteMoves() const;
    void makeMove(Move &mv);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif