#include "inputparser.h"
#include <sstream>

std::vector<std::string> parseLine(std::string command) {
    std::vector<std::string> input;
    std::string s;
    std::istringstream ss{command};
    while (ss >> s) {
        input.push_back(s);
    }
    return input;
}

int parseRank(std::string temp) {
    if (temp.length() != 2) {
        throw InputException{};
    }
    int diff = temp[1] - '1';
    if (diff >= 0 && diff <= 7) {
        return diff;
    }
    throw InputException{};
}

int parseFile(std::string temp) {
    if (temp.length() != 2) {
        throw InputException{};
    }
    int diff = temp[0] - 'a';
    if (diff >= 0 && diff <= 7) {
        return diff;
    }
    throw InputException{};
}

char parsePiece(std::string temp) {
    if (temp.length() != 1) {
        throw InputException{};
    }
    char c = tolower(temp[0]);
    if (c == 'p' || c == 'r' || c == 'b' || c == 'n' || c == 'q' || c == 'k') {
        return temp[0];
    }
    throw InputException{};
}

char parseColour(std::string temp) {
    if (temp.length() != 1) {
        throw InputException{};
    }
    if (temp[0] == 'W' || temp[0] == 'B') {
        return temp[0];
    }
    throw InputException{};
}