#include "level3.h"

#include <stdlib.h>

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../board.h"
#include "../inputparser.h"
#include "../move.h"

void Level3::makeMove(Board &board, std::vector<Move> &moves, char colour) {
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
                    int movePointValue = 0;
                    if (moves[i].capturedPiece != nullptr) {
                        movePointValue += moves[i].capturedPiece->getValue();
                    }
                    if (moves[i].check || moves[i].castle || moves[i].promotion != ' ') {
                        movePointValue += 1;
                    }
                    auto nextBoard = board.getBoardAfterMove(moves[i]);
                    std::vector<Move> oppMoves = nextBoard->getMoves(colour == 'W' ? 'B' : 'W', true);
                    if (oppMoves.size() == 0) {
                        if (moves[i].check) {
                            board.makeMove(moves[i]);
                            return;
                        } else if (bestMovePointValue <= 0) {
                            if (bestMovePointValue < 0) {
                                bestMovePointValue = 0;
                                bestMoves.clear();
                            }
                            bestMoves.push_back(moves[i]);
                            continue;
                        }
                    }
                    int maxOppMovePointValue = -10000;
                    for (int j = 0; j < (int)oppMoves.size(); j++) {
                        int oppMovePointValue = oppMoves[j].capturedPiece == nullptr ? 0 : oppMoves[j].capturedPiece->getValue();
                        maxOppMovePointValue = std::max(maxOppMovePointValue, oppMovePointValue);
                    }
                    if (movePointValue - maxOppMovePointValue >= bestMovePointValue) {
                        if (movePointValue - maxOppMovePointValue > bestMovePointValue) {
                            bestMovePointValue = movePointValue - maxOppMovePointValue;
                            bestMoves.clear();
                        }
                        bestMoves.push_back(moves[i]);
                    }
                }
                // std::cout << 3 << " " << bestMovePointValue << std::endl;
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
