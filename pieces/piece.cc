#include "piece.h"

Piece::Piece(char colour, int rank, int file, Board &board) : colour{colour}, rank{rank}, file{file}, board{board} {}