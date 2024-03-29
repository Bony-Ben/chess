#include <memory>
#include <vector>

#include "display/subject.h"
#include "move.h"
#include "pieces/piece.h"

#ifndef BOARD_H
#define BOARD_H

class Board : public Subject {
    std::vector<std::unique_ptr<Piece>> pieces;
    Piece *board[8][8];
    std::unique_ptr<Move> prevMove;
    bool silent = false;

   public:
    Board();
    Board(Board &board);
    void reset();
    void updateBoard();
    bool isValidBoard();
    bool isCheck(char colour);
    std::unique_ptr<Board> getBoardAfterMove(Move mv);
    void undoMove(Move &mv);
    void undoPrevMove();
    void setPrevMove(Move &mv);
    Move *getPrevMove();
    Piece *getSquare(int rank, int file);
    std::vector<Move> getMoves(char colour, bool validateChecks);
    std::vector<Piece *> getPieces();
    void makeMove(Move &mv);
    Piece *addPiece(char piece, char colour);
    void deletePiece(int rank, int file);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif