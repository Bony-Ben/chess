#include <iostream>
#include <sstream>
#include <vector>

#include "board.h"
#include "display/graphicsobserver.h"
#include "display/textobserver.h"
#include "game.h"
#include "inputparser.h"
#include "players/human.h"
#include "players/level1.h"
#include "players/level2.h"
#include "players/level3.h"

void setup(Board &board, char &first) {
    std::cout << "~~~ Setup Mode ~~~" << std::endl;
    board.notifyObservers();
    std::string s;
    while (std::getline(std::cin, s)) {
        try {
            std::vector<std::string> input = parseLine(s);
            std::string command;
            if (input.size() == 0) {
                throw InputException{};
            }
            command = input.at(0);
            if (command == "done") {
                if (board.isValidBoard()) {
                    break;
                } else {
                    std::cout << "Sorry, your board is not in a valid state." << std::endl;
                }
            } else if (command == "+") {
                if (input.size() < 3) {
                    throw InputException{};
                }
                command = input.at(1);
                char piece = parsePiece(command);
                command = input.at(2);
                int rank = parseRank(command);
                int file = parseFile(command);
                board.deletePiece(rank, file);
                char colour;
                if (piece >= 'A' && piece <= 'Z') {
                    colour = 'W';
                    piece += ('a' - 'A');
                } else {
                    colour = 'B';
                }
                Piece *newpiece = board.addPiece(piece, colour);
                newpiece->setRank(rank);
                newpiece->setFile(file);
                board.updateBoard();
            } else if (command == "-") {
                if (input.size() < 2) {
                    throw InputException{};
                }
                command = input.at(1);
                int rank = parseRank(command);
                int file = parseFile(command);
                board.deletePiece(rank, file);
                board.updateBoard();
            } else if (command == "=") {
                if (input.size() < 2) {
                    throw InputException{};
                }
                command = input.at(1);
                char c = parseColour(command);
                first = c;
            } else {
                throw InputException{};
            }
        } catch (InputException i) {
            std::cout << "Invalid command. Please try again." << std::endl;
            continue;
        }
    }
    std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
}

std::unique_ptr<Player> createPlayer(std::string option) {
    if (option.substr(0, option.size() - 1) == "computer") {
        int level = option[option.size() - 1] - '0';
        if (level == 1) {
            return std::make_unique<Level1>();
        } else if (level == 2) {
            return std::make_unique<Level2>();
        } else if (level == 3) {
            return std::make_unique<Level3>();
        }
    } else if (option == "human") {
        return std::make_unique<Human>();
    }
    throw InputException{};
}

int main() {
    srand(time(0));
    Board board;
    TextObserver tobs{&board};
    GraphicsObserver gobs{&board};
    char first = 'W';
    double whiteScore = 0.0;
    double blackScore = 0.0;
    std::string command;
    std::cout << "Welcome to Chess!\nEnter 'game' to start playing, and enter 'setup' to customize your board." << std::endl;
    try {
        while (std::getline(std::cin, command)) {
            try {
                std::vector<std::string> input = parseLine(command);
                if (input.size() == 0) {
                    throw InputException{};
                }
                command = input.at(0);
                if (command == "game") {
                    if (input.size() < 3) {
                        throw InputException{};
                    }
                    std::unique_ptr<Player> white = createPlayer(input.at(1));
                    std::unique_ptr<Player> black = createPlayer(input.at(2));
                    Game game{board, *white, *black, first};
                    game.play(whiteScore, blackScore);
                    first = 'W';

                    board.detach(&tobs);
                    board.reset();
                    board.attach(&tobs);
                } else if (command == "setup") {
                    setup(board, first);
                } else if (command == "seed") {
                    if (input.size() < 2) {
                        throw InputException{};
                    }
                    std::string str_seed = input.at(1);
                    for (int i = 0; i < (int)str_seed.length(); i++) {
                        if (!isdigit(str_seed[i])) {
                            throw InputException{};
                        }
                    }
                    int seed = std::stoi(str_seed);
                    srand(seed);
                } else {
                    throw InputException{};
                }
            } catch (InputException i) {
                std::cout << "Invalid command. Please try again." << std::endl;
                continue;
            }
            std::cout << "Welcome to Chess!\nEnter 'game' to start playing, and enter 'setup' to customize your board." << std::endl;
        }
    } catch (EndOfFileException e) {
    }
    std::cout << "\nFinal Score:" << std::endl;
    std::cout << "White: " << whiteScore << std::endl;
    std::cout << "Black: " << blackScore << std::endl;
}