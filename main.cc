#include <iostream>

#include "board.h"
#include "display/graphicsobserver.h"
#include "display/textobserver.h"
#include "game.h"
#include "players/human.h"
#include "players/level1.h"
#include "players/level2.h"

int main() {
    Level2 white;
    Human black;
    Board board;
    TextObserver tobs{&board};
    GraphicsObserver gobs{&board};
    Game game{board, white, black};
    game.play();
    return 0;
}