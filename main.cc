#include <iostream>

#include "board.h"
#include "display/textobserver.h"
#include "game.h"
#include "players/human.h"
#include "players/level1.h"

int main() {
    Human white;
    Level1 black;
    Board board;
    TextObserver tobs{&board};
    Game game{board, white, black};
    game.play();
    return 0;
}