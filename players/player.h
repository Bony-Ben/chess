#ifndef PLAYER_H
#define PLAYER_H

class Board;

class StalemateException {};
class CheckmateException {};

class Player {
    double score;

   public:
    virtual void makeMove(Board &board, char colour) = 0;
    double getScore() const { return score; };
    void addScore(double inc) { score += inc; };
};

#endif