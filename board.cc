#include "board.h"

#include <iostream>
#include <memory>
#include <string>

#include "move.h"
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"

Board::Board() {
    reset();
}

void Board::reset() {
    prevMove = std::unique_ptr<Move>{};
    pieces.clear();

    pieces.push_back(std::make_unique<Rook>('W', 0, 0, this, true));
    pieces.push_back(std::make_unique<Rook>('W', 0, 7, this, true));
    pieces.push_back(std::make_unique<Rook>('B', 7, 0, this, true));
    pieces.push_back(std::make_unique<Rook>('B', 7, 7, this, true));
    pieces.push_back(std::make_unique<Knight>('W', 0, 1, this));
    pieces.push_back(std::make_unique<Knight>('W', 0, 6, this));
    pieces.push_back(std::make_unique<Knight>('B', 7, 1, this));
    pieces.push_back(std::make_unique<Knight>('B', 7, 6, this));
    pieces.push_back(std::make_unique<Bishop>('W', 0, 5, this));
    pieces.push_back(std::make_unique<Bishop>('W', 0, 2, this));
    pieces.push_back(std::make_unique<Bishop>('B', 7, 2, this));
    pieces.push_back(std::make_unique<Bishop>('B', 7, 5, this));
    pieces.push_back(std::make_unique<Queen>('W', 0, 3, this));
    pieces.push_back(std::make_unique<Queen>('B', 7, 3, this));
    pieces.push_back(std::make_unique<King>('W', 0, 4, this, true));
    pieces.push_back(std::make_unique<King>('B', 7, 4, this, true));
    for (int i = 0; i < 8; i++) {
        pieces.push_back(std::make_unique<Pawn>('W', 1, i, this));
        pieces.push_back(std::make_unique<Pawn>('B', 6, i, this));
    }
    updateBoard();
}

Board::Board(Board &board) {
    for (int i = 0; i < (int)board.pieces.size(); i++) {
        pieces.push_back(board.pieces[i]->clone(this));
    }
    if (board.prevMove != nullptr) {
        prevMove = std::make_unique<Move>(*board.prevMove);
    }
    updateBoard();
}

bool Board::isValidBoard() {
    for (int i = 0; i < 8; i++) {
        if (dynamic_cast<Pawn *>(board[0][i]) != nullptr || dynamic_cast<Pawn *>(board[7][i]) != nullptr) {
            return false;
        }
    }
    int whiteKingCount = 0;
    int blackKingCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (dynamic_cast<King *>(board[i][j]) != nullptr) {
                if (board[i][j]->getColour() == 'W') {
                    whiteKingCount++;
                } else {
                    blackKingCount++;
                }
            }
        }
    }
    return whiteKingCount == 1 && blackKingCount == 1 && !isCheck('W') && !isCheck('B');
}

bool Board::isCheck(char colour) {
    std::vector<Move> moves = getMoves(colour, false);
    for (int i = 0; i < (int)moves.size(); i++) {
        if (dynamic_cast<King *>(moves[i].capturedPiece) != nullptr) {
            return true;
        }
    }
    return false;
}

std::unique_ptr<Board> Board::getBoardAfterMove(Move mv) {
    auto tempBoard = std::make_unique<Board>(*this);
    mv.piece = tempBoard->getSquare(mv.oldRank, mv.oldFile);
    if (mv.capturedPiece != nullptr) {
        mv.capturedPiece = tempBoard->getSquare(mv.capturedPiece->getRank(), mv.capturedPiece->getFile());
    }
    tempBoard->makeMove(mv);
    return tempBoard;
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
        if (!pieces[i]->isCaptured() && pieces[i]->getColour() == colour) {
            pieces[i]->getMoves(ans, validateChecks);
        }
    }
    return ans;
}

void Board::undoPrevMove() {
    Move &mv = *prevMove;

    if (mv.capturedPiece != nullptr) {
        mv.capturedPiece->setCaptured(false);
    }
    mv.piece->setRank(mv.oldRank);
    mv.piece->setFile(mv.oldFile);
    mv.piece->executeWhenUndoed(mv);

    if (mv.promotion != ' ') {
        pieces.pop_back();
        mv.piece->setCaptured(false);
    }

    if (mv.castle) {
        Piece *rook;
        if (mv.newFile == 6) {
            rook = board[mv.newRank][5];
            rook->setFile(7);
        } else if (mv.newFile == 2) {
            rook = board[mv.newRank][3];
            rook->setFile(0);
        }
        rook->executeWhenUndoed(mv);
    }

    updateBoard();
}

void Board::makeMove(Move &mv) {
    if (mv.capturedPiece != nullptr) {
        mv.capturedPiece->setCaptured(true);
    }
    mv.piece->setRank(mv.newRank);
    mv.piece->setFile(mv.newFile);
    mv.piece->executeWhenMoved(mv);

    if (mv.promotion != ' ') {
        if (mv.promotion == 'Q') {
            pieces.push_back(std::make_unique<Queen>(mv.piece->getColour(), mv.piece->getRank(), mv.piece->getFile(), this));
        } else if (mv.promotion == 'B') {
            pieces.push_back(std::make_unique<Bishop>(mv.piece->getColour(), mv.piece->getRank(), mv.piece->getFile(), this));
        } else if (mv.promotion == 'N') {
            pieces.push_back(std::make_unique<Knight>(mv.piece->getColour(), mv.piece->getRank(), mv.piece->getFile(), this));
        } else {
            pieces.push_back(std::make_unique<Rook>(mv.piece->getColour(), mv.piece->getRank(), mv.piece->getFile(), this, false));
        }
        mv.piece->setCaptured(true);
    }

    if (mv.castle) {
        Piece *rook;
        if (mv.newFile == 6) {
            rook = board[mv.newRank][7];
            rook->setFile(5);
        } else if (mv.newFile == 2) {
            rook = board[mv.newRank][0];
            rook->setFile(3);
        }
        rook->executeWhenMoved(mv);
    }

    prevMove = std::make_unique<Move>(mv);
    updateBoard();
}

Piece *Board::addPiece(char piece, char colour) {
    if (piece == 'r') {
        pieces.push_back(std::make_unique<Rook>(colour, 0, 0, this, false));
    } else if (piece == 'n') {
        pieces.push_back(std::make_unique<Knight>(colour, 0, 0, this));
    } else if (piece == 'b') {
        pieces.push_back(std::make_unique<Bishop>(colour, 0, 0, this));
    } else if (piece == 'q') {
        pieces.push_back(std::make_unique<Queen>(colour, 0, 0, this));
    } else if (piece == 'k') {
        pieces.push_back(std::make_unique<King>(colour, 0, 0, this, false));
    } else {
        pieces.push_back(std::make_unique<Pawn>(colour, 0, 0, this));
    }
    return pieces.back().get();
}

void Board::deletePiece(int rank, int file) {
    int count = 0;
    for (auto &p : pieces) {
        if (!p->isCaptured() && p->getRank() == rank && p->getFile() == file) {
            pieces.erase(pieces.begin() + count);
            break;
        }
        count++;
    }
}

Move &Board::getPrevMove() {
    return *prevMove;
}

void Board::setPrevMove(Move &mv) {
    prevMove = std::make_unique<Move>(mv);
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