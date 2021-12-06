#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Board;
class Move;

class Player {
    double score;

   public:
    virtual void makeMove(Board &board, std::vector<Move> &moves, char colour) = 0;
    double getScore() const { return score; };
    void addScore(double inc) { score += inc; };
};

#endif