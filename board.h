#include <memory>
#include <vector>

#include "move.h"

#ifndef BOARD_H
#define BOARD_H

class Piece;

class Board {
    std::vector<std::unique_ptr<Piece>> pieces;

    std::vector<std::vector<Piece*>> getBoard();
    std::vector<Piece*> getBlackPieces();
    std::vector<Piece*> getWhitePieces();
    std::vector<Move> getBlackMoves();
    std::vector<Move> getWhiteMoves();

   public:
    Board();
};

#endif