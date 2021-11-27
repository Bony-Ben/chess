#include "board.h"

#include <memory>

#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"

Board::Board() {
    pieces.push_back(std::make_unique<Rook>('W', 0, 0, *this));
    pieces.push_back(std::make_unique<Rook>('B', 7, 0, *this));
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    return out;
}