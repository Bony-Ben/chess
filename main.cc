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
    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "done") {
            break;
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

int main() {
    Board board;
    TextObserver tobs{&board};
    char first = 'W';
    // GraphicsObserver gobs{&board};
    while (true) {
        std::string command;
        std::cin >> command;
        if (std::cin.eof()) {
            break;
        } else if (command == "game") {
            Level1 white;
            Human black;
            Game game{board, white, black, first};
            game.play();
            first = 'W';
        } else if (command == "setup") {
            setup(board, first);
        }
    }
}