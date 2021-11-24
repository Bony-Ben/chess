#include "board.h"
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include <memory>

Board::Board()
{
    arr[0][0] = std::make_unique<Rook>('W', 0, 0, * this);
    arr[8][0] = std::make_unique<Rook>('W', 8, 0, * this);
}