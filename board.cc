#include "board.h"

#include <iostream>
#include <memory>

#include "move.h"
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

    updateBoard();
}

Piece *Board::getSquare(int rank, int file) {
    return board[rank][file];
}

void Board::updateBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }
    for (int i = 0; i < (int)pieces.size(); i++) {
        if (!pieces[i]->isCaptured()) {
            board[pieces[i]->getRank()][pieces[i]->getFile()] = pieces[i].get();
        }
    }
    notifyObservers();
}

std::vector<Move> Board::getMoves(char colour) const {
    std::vector<Move> ans;
    for (int i = 0; i < (int)pieces.size(); i++) {
        if (!pieces[i]->isCaptured() && pieces[i]->getColour() == colour) {
            pieces[i]->getMoves(ans);
        }
    }
    return ans;
}

void Board::makeMove(Move &mv) {
    if (mv.captured != nullptr) {
        mv.captured->setCaptured(true);
    }
    mv.piece.setRank(mv.newRank);
    mv.piece.setFile(mv.newFile);
    updateBoard();
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    for (int i = 0; i < 8; i++) {
        out << 8 - i << ' ';
        for (int j = 0; j < 8; j++) {
            if (b.board[7 - i][j] == nullptr) {
                if ((7 - i + j) % 2 == 0) {
                    out << '_';
                } else {
                    out << ' ';
                }
            } else {
                out << b.board[7 - i][j]->toChar();
            }
            out << ' ';
        }
        out << std::endl;
    }
    out << "  a b c d e f g h";
    return out;
}