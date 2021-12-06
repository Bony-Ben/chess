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
    pieces.push_back(std::make_unique<Knight>('W', 0, 1, *this));
    pieces.push_back(std::make_unique<Knight>('W', 0, 6, *this));
    pieces.push_back(std::make_unique<Knight>('B', 7, 1, *this));
    pieces.push_back(std::make_unique<Knight>('B', 7, 6, *this));
    pieces.push_back(std::make_unique<Bishop>('W', 0, 2, *this));
    pieces.push_back(std::make_unique<Bishop>('W', 0, 5, *this));
    pieces.push_back(std::make_unique<Bishop>('B', 7, 2, *this));
    pieces.push_back(std::make_unique<Bishop>('B', 7, 5, *this));
    pieces.push_back(std::make_unique<Queen>('W', 0, 3, *this));
    pieces.push_back(std::make_unique<Queen>('B', 7, 3, *this));
    pieces.push_back(std::make_unique<King>('W', 0, 4, *this));
    pieces.push_back(std::make_unique<King>('B', 7, 4, *this));
    // for (int i = 0; i < 8; i++) {
    //     pieces.push_back(std::make_unique<Pawn>('W', 1, i, *this));
    //     pieces.push_back(std::make_unique<Pawn>('B', 6, i, *this));
    // }
    updateBoard();
}

Board::Board(Board &board) {
    for (int i = 0; i < board.pieces.size(); i++) {
        pieces.push_back(board.pieces[i]->clone());
    }
    if (board.prevMove != nullptr) {
        prevMove = std::make_unique<Move>(*board.prevMove);
    }
    updateBoard();
}

Piece *Board::getSquare(int rank, int file) {
    return board[rank][file];
}

std::vector<Piece *> Board::getPieces() {
    std::vector<Piece *> pcs;
    for (int i = 0; i < (int)pieces.size(); i++) {
        if (!pieces[i]->isCaptured()) {
            pcs.push_back(pieces[i].get());
        }
    }
    return pcs;
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

std::vector<Move> Board::getMoves(char colour, bool validateChecks) const {
    std::vector<Move> ans;
    for (int i = 0; i < (int)pieces.size(); i++) {
        if (!pieces[i]->isCaptured() && pieces[i]->getColour() == colour && validateChecks) {
            std::cout << ans.size() << std::endl;
        }
        if (!pieces[i]->isCaptured() && pieces[i]->getColour() == colour) {
            pieces[i]->getMoves(ans, validateChecks);
        }
    }
    return ans;
}

void Board::makeMove(Move &mv) {
    if (mv.capturedPiece != nullptr) {
        mv.capturedPiece->setCaptured(true);
    }
    mv.piece->setRank(mv.newRank);
    mv.piece->setFile(mv.newFile);
    updateBoard();
    prevMove = std::make_unique<Move>(mv);
    if (mv.check) {
        std::cout << "Check!" << std::endl;
    }
}

Move Board::getPrevMove() {
    return *prevMove;
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    for (int i = 0; i < 8; i++) {
        out << 8 - i << "  ";
        for (int j = 0; j < 8; j++) {
            if (b.board[7 - i][j] == nullptr) {
                if ((7 - i + j) % 2 == 0) {
                    out << '_';
                } else {
                    out << ' ';
                }
            } else {
                out << *b.board[7 - i][j];
            }
            out << ' ';
        }
        out << std::endl;
    }
    out << std::endl;
    out << "   a b c d e f g h";
    return out;
}