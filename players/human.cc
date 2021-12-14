#include "human.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

#include "../board.h"
#include "../move.h"
#include "../inputparser.h"

void Human::makeMove(Board &board, std::vector<Move> &moves, char colour) {
    std::string colour_name;
    colour_name = (colour == 'W') ? "White" : "Black";
    std::string s;
    while (std::getline(std::cin, s)) {
        try {
            std::vector<std::string> input = parseLine(s);
            std::string command;
            if (input.size() == 0) {
                throw InputException{};
            }
            command = input.at(0);
            if (command == "move") {
                char promo = ' ';
                bool invalid = false;
                if (input.size() < 3) {
                    throw InputException{};
                }
                command = input.at(1);
                int startRank = parseRank(command);
                int startFile = parseFile(command);
                command = input.at(2);
                int endRank = parseRank(command);
                int endFile = parseFile(command);

                if (input.size() >= 4) {
                    command = input.at(3);
                    promo = command[0];
                    if (toupper(promo) != 'Q' && toupper(promo) != 'N' && toupper(promo) != 'B' && toupper(promo) != 'R') {
                      std::cout << "word " << promo << std::endl;
                      invalid = true;
                    }
                }
                if (!invalid) {
                  for (int i = 0; i < (int)moves.size(); i++) {
                    if (moves[i].oldRank == startRank && moves[i].oldFile == startFile && moves[i].newRank == endRank && moves[i].newFile == endFile) {
                        if ((input.size() < 4) || (input.size() >= 4 && moves[i].promotion == toupper(promo))) {
                          board.makeMove(moves[i]);
                          return;
                        }
                    }
                  }
                }
                std::cout << "Invalid Move!" << std ::endl;
                std::cout << colour_name << "'s turn: ";
            } else if (command == "resign") {
                throw ResignException{};
            } else {
                throw InputException{};
            }
        } catch (InputException i) {
            std::cout << "Invalid Input! Please try again." << std ::endl;
            std::cout << colour_name << "'s turn: ";
        }
    }
    throw EndOfFileException{};
}
