#include <iostream>

#include "board.h"
#include "display/graphicsobserver.h"
#include "display/textobserver.h"
#include "game.h"
#include "players/human.h"
#include "players/level1.h"
#include "players/level2.h"

void setup(Board &board) {
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
            Piece *oldpiece = board.getSquare(rank, file);
            if (oldpiece != nullptr) {
                oldpiece->setCaptured(true);
            }
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
        }
    }
    std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
}

int main() {
    while (true) {
        std::string command;
        std::cin >> command;
        Board board;
        TextObserver tobs{&board};
        // GraphicsObserver gobs{&board};
        if (std::cin.eof()) {
            break;
        } else if (command == "game") {
            Level1 white;
            Human black;
            Game game{board, white, black, 'B'};
            game.play();
        } else if (command == "setup") {
            setup(board);
        }
    }
}