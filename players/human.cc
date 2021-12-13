#include "human.h"

#include <iostream>
#include <sstream>
#include <vector>

#include "../board.h"
#include "../move.h"

std::vector<std::string> Human::parseLine(std::string command) {
    std::vector<std::string> input;
    std::string s;
    std::istringstream ss{command};
    while (ss >> s) {
        input.push_back(s);
    }
    return input;
}

int Human::parseRank(std::string temp) {
    if (temp.length() != 2) {
        throw InputException{};
    }
    int diff = temp[1] - '1';
    if (diff >= 0 && diff <= 7) {
        return diff;
    }
    throw InputException{};
}

int Human::parseFile(std::string temp) {
    if (temp.length() != 2) {
        throw InputException{};
    }
    int diff = temp[0] - 'a';
    if (diff >= 0 && diff <= 7) {
        return diff;
    }
    throw InputException{};
}

void Human::makeMove(Board &board, std::vector<Move> &moves, char colour) {
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
                if (input.size() < 3) {
                    throw InputException{};
                }
                command = input.at(1);
                int startRank = parseRank(command);
                int startFile = parseFile(command);
                command = input.at(2);
                int endRank = parseRank(command);
                int endFile = parseFile(command);
                for (int i = 0; i < (int)moves.size(); i++) {
                    if (moves[i].oldRank == startRank && moves[i].oldFile == startFile && moves[i].newRank == endRank && moves[i].newFile == endFile) {
                        board.makeMove(moves[i]);
                        return;
                    }
                }
                std::cout << "Invalid Move!" << std ::endl;
            } else if (command == "resign") {
                throw ResignException{};
            } else {
                throw InputException{};
            }
        } catch (InputException i) {
            std::cout << "Invalid Input! Please try again." << std ::endl;
        }
    }
    throw EndOfFileException{};
}
