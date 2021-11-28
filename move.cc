#include "move.h"

Move::Move(Piece &piece, int rank, int file, Piece *captured, bool check, bool checkmate, bool stalemate) : piece{piece}, rank{rank}, file{file}, captured{captured}, check{check}, checkmate{checkmate}, stalemate{stalemate} {}