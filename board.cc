#include "board.h"

#include <iostream>
#include <memory>

#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"

Board::Board() {
    pieces.push_back(std::make_unique<Rook>('W', 0, 0, *this));
    pieces.push_back(std::make_unique<Rook>('W', 0, 7, *this));
    pieces.push_back(std::make_unique<Rook>('B', 7, 0, *this));
    pieces.push_back(std::make_unique<Rook>('B', 7, 7, *this));
}

std::vector<std::vector<Piece *>> Board::getBoard() const {
    std::vector<std::vector<Piece *>> ans(8);
    for (int i = 0; i < 8; i++) {
        ans[i] = std::vector<Piece *>(8);
    }
    for (int i = 0; i < (int)pieces.size(); i++) {
        ans[pieces[i]->getRank()][pieces[i]->getFile()] = pieces[i].get();
    }
    return ans;
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    std::vector<std::vector<Piece *>> board = b.getBoard();
    for (int i = 0; i < 8; i++) {
        out << 8 - i << ' ';
        for (int j = 0; j < 8; j++) {
            if (board[7 - i][j] == nullptr) {
                if ((7 - i + j) % 2 == 0) {
                    out << '_';
                } else {
                    out << ' ';
                }
            } else {
                out << board[7 - i][j]->toChar();
            }
            out << ' ';
        }
        out << std::endl;
    }
    out << "  a b c d e f g h";
    return out;
}