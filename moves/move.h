#ifndef MOVE_H
#define MOVE_H

class Board;

class Move {
    bool check;

   public:
    Move(bool check);
    bool isCheck();
    virtual void makeMove(Board &board) = 0;
    virtual void undo(Board &board) = 0;
};

#endif