#include <string>
#include <vector>

#ifndef INPUT_H
#define INPUT_H

class InputException {};
std::vector<std::string> parseLine(std::string command);
int parseRank(std::string temp);
int parseFile(std::string temp);
char parsePiece(std::string temp);
char parseColour(std::string temp);

#endif