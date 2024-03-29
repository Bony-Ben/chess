#include "level4.h"

#include <stdlib.h>

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../board.h"
#include "../inputparser.h"
#include "../move.h"
#include "../pieces/king.h"
#include "../pieces/rook.h"

int Level4::minimax(Board &board, char colour, int depth) {
    if (depth > MAX_DEPTH) {
        return 0;
    }
    std::vector<Move> moves = board.getMoves(colour, true);
    if (moves.size() == 0) {
        if (board.getPrevMove()->check) {
            return -10000 + 50 * depth;
        } else {
            return 0;
        }
    }
    int bestMovePointValue = -10000;
    for (int i = 0; i < (int)moves.size(); i++) {
        board.makeMove(moves[i]);
        int movePointValue = evaluateMove(moves[i]) - minimax(board, colour == 'W' ? 'B' : 'W', depth + 1);
        board.undoMove(moves[i]);
        bestMovePointValue = std::max(bestMovePointValue, movePointValue);
    }
    return bestMovePointValue;
}

int Level4::evaluateMove(Move &mv) {
    int movePointValue = 0;
    if (mv.capturedPiece != nullptr) {
        movePointValue += mv.capturedPiece->getValue() * 2;
    }
    if (mv.check) {
        movePointValue += 1;
    }
    King *k = dynamic_cast<King *>(mv.piece);
    if (mv.castle) {
        movePointValue += 1;
    } else if (k != nullptr && k->getCanCastle()) {
        movePointValue -= 1;
    }
    if (mv.promotion != ' ') {
        if (mv.promotion == 'Q') {
            movePointValue += 18;
        } else if (mv.promotion == 'R') {
            movePointValue += 10;
        } else {
            movePointValue += 6;
        }
    }
    return movePointValue;
}

void Level4::makeMove(Board &board, std::vector<Move> &moves, char colour) {
    std::string s;
    while (std::getline(std::cin, s)) {
        try {
            std::vector<std::string> input = parseLine(s);
            if (input.size() == 0) {
                throw InputException{};
            }
            s = input.at(0);
            if (s == "move") {
                std::vector<Move> bestMoves;
                int bestMovePointValue = -10000;
                for (int i = 0; i < (int)moves.size(); i++) {
                    auto nextBoard = board.getBoardAfterMove(moves[i]);
                    int movePointValue = evaluateMove(moves[i]) - minimax(*nextBoard, colour == 'W' ? 'B' : 'W', 1);
                    if (movePointValue >= bestMovePointValue) {
                        if (movePointValue > bestMovePointValue) {
                            bestMovePointValue = movePointValue;
                            bestMoves.clear();
                        }
                        bestMoves.push_back(moves[i]);
                    }
                }
                // std::cout << 4 << " " << bestMovePointValue << std::endl;
                board.makeMove(bestMoves[rand() % bestMoves.size()]);
                return;

            } else {
                throw InputException{};
            }
        } catch (InputException i) {
            std::cout << "Invalid Input! Please try again." << std ::endl;
        }
    }
    throw EndOfFileException{};
}
