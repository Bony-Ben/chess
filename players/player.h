#ifndef PLAYER_H
#define PLAYER_H

class Board;
class Move;

class Player {
    double score;

   public:
    virtual Move makeMove(Board &board, char colour) = 0;
    double getScore() const { return score; };
    void addScore(double inc) { score += inc; };
};

#endif