#include <iostream>

#include "board.h"
#include "display/graphicsobserver.h"
#include "display/textobserver.h"
#include "game.h"
#include "players/human.h"
#include "players/level1.h"
#include "players/level2.h"

void setup(Board &board, char &first) {
    std::cout << "~~~ Setup Mode ~~~" << std::endl;
    board.notifyObservers();
    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "done") {
            if (board.isValidBoard()) {
                break;
            } else {
                std::cout << "Sorry, your board is not in a valid state." << std::endl;
            }
        } else if (command == "+") {
            char piece;
            char colour;
            std::cin >> piece;
            std::cin >> command;
            int rank = command[1] - '1';
            int file = command[0] - 'a';
            board.deletePiece(rank, file);
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
            std::cin >> command;
            int rank = command[1] - '1';
            int file = command[0] - 'a';
            board.deletePiece(rank, file);
            board.updateBoard();
        } else if (command == "=") {
            char c;
            std::cin >> c;
            first = c;
        }
    }
    std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
}

std::unique_ptr<Player> createPlayer() {
    std::string temp;
    std::cin >> temp;
    if (temp.substr(0, temp.size() - 1) == "computer") {
        int level = temp[temp.size() - 1] - '0';
        if (level == 1) {
            return std::make_unique<Level1>();
        } else if (level == 2) {
            return std::make_unique<Level2>();
        }
    }
    return std::make_unique<Human>();
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
    while (std::cin >> command) {
        if (command == "game") {
            std::unique_ptr<Player> white = createPlayer();
            std::unique_ptr<Player> black = createPlayer();

            Game game{board, *white, *black, first};
            game.play(whiteScore, blackScore);
            first = 'W';

            board.detach(&tobs);
            board.reset();
            board.attach(&tobs);
        } else if (command == "setup") {
            setup(board, first);
        }
        std::cout << "Welcome to Chess!\nEnter 'game' to start playing, and enter 'setup' to customize your board." << std::endl;
    }
    std::cout << "Final Score:" << std::endl;
    std::cout << "White: " << whiteScore << std::endl;
    std::cout << "Black: " << blackScore << std::endl;
}