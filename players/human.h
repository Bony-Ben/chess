#include <string>

#include "player.h"

#ifndef HUMAN_H
#define HUMAN_H

class Board;
class Move;

class ResignException {};
class UndoException {};
class InputException {};
class EndOfFileException {};

class Human : public Player {
    std::vector<std::string> parseLine(std::string command);
    int parseRank(std::string temp);
    int parseFile(std::string temp);

   public:
    void makeMove(Board &board, std::vector<Move> &moves, char colour) override;
};

#endif