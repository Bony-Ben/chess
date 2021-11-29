#include "move.h"

Move::Move(Piece &piece, int oldRank, int oldFile, int newRank, int newFile, Piece *captured, bool check, bool castle, bool promotion)
    : piece{piece}, oldRank{oldRank}, oldFile{oldFile}, newRank{newRank}, newFile{newFile}, captured{captured}, check{check}, castle{castle}, promotion{promotion} {}