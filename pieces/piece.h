#include <vector>

#include "../move.h"

#ifndef PIECE_H
#define PIECE_H

class Board;
class Piece {
   protected:
    char colour;
    int rank;
    int file;
    char letter;
    Board *board;
    bool captured;

    void addMoveIfValid(Move mv, std::vector<Move> &moves, bool validateChecks);

   public:
    Piece(char colour, int rank, int file, char letter, Board *board);
    virtual void getMoves(std::vector<Move> &moves, bool validateChecks) = 0;
    char getColour() const;
    int getRank() const;
    int getFile() const;
    char getLetter() const;
    bool isCaptured() const;

    void setRank(int r);
    void setFile(int f);
    void setCaptured(bool c);
    virtual std::unique_ptr<Piece> clone(Board * board) const = 0;
    friend std::ostream &operator<<(std::ostream &out, const Piece &p);
};

#endif