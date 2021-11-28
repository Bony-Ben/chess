#include <iostream>

#include "board.h"
#include "game.h"
#include "players/human.h"
#include "players/level1.h"

int main() {
    Human white;
    Level1 black;
    Board board;
    Game game{board, white, black};
    game.play();
    return 0;
}