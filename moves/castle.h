#include "move.h"

#ifndef CMOVE_H
#define CMOVE_H

class Castle : public Move {
    char colour;
    bool kingside;

   public:
    Castle(char colour, bool kingside, bool check);

    char &getColour();
    bool isKingside();

    void makeMove(Board &board) override;
    void undo(Board &board) override;
};

#endif