#include "textobserver.h"

#include <iostream>

#include "../board.h"

TextObserver::TextObserver(Board *board) : board{board} {
    board->attach(this);
}

TextObserver::~TextObserver() {
    board->detach(this);
}

void TextObserver::notify() {
    std::cout << *board << std::endl;
}
