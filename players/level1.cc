#include "level1.h"

#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "../board.h"
#include "../inputparser.h"
#include "../move.h"

void Level1::makeMove(Board &board, std::vector<Move> &moves, char colour) {
    std::string colour_name;
    colour_name = (colour == 'W') ? "White" : "Black";
    std::string s;
    while (std::getline(std::cin, s)) {
        try {
            std::vector<std::string> input = parseLine(s);
            if (input.size() == 0) {
                throw InputException{};
            }
            s = input.at(0);
            if (s == "move") {
                board.makeMove(moves[rand() % moves.size()]);
                return;
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
