#include <iostream>

#include "board.h"
#include "game.h"
#include "players/human.h"

int main() {
    Human white;
    Human black;
    Board board;

    Game game{board, white, black};

    std::cout << board;

    return 0;
}