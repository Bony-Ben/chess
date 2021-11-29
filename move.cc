#include "move.h"

Move::Move(Piece &piece, int oldRank, int oldFile, int newRank, int newFile, Piece *captured, bool check, bool checkmate, bool stalemate)
    : piece{piece}, oldRank{oldRank}, oldFile{oldFile}, newRank{newRank}, newFile{newFile}, captured{captured}, check{check}, checkmate{checkmate}, stalemate{stalemate} {}

Move::Move(const Move &mv) : piece{mv.piece}, oldRank{mv.oldRank}, oldFile{mv.oldFile}, newRank{mv.newRank}, newFile{mv.newFile}, captured{mv.captured}, check{mv.check}, checkmate{mv.checkmate}, stalemate{mv.stalemate} {}