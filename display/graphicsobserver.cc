#include "graphicsobserver.h"

#include <iostream>
#include <string>

GraphicsObserver::GraphicsObserver(Board *board) : board{board} {
    w = new Xwindow(720, 720);
    bool white = true;
    for (int y = 0; y <= 630; y += 90) {
        for (int x = 0; x <= 630; x += 90) {
            if (white) {
                w->fillRectangle(x, y, 90, 90, Xwindow::White);
            } else {
                w->fillRectangle(x, y, 90, 90);
            }
            white = !white;
        }
        white = !white;
    }
    board->attach(this);
}

GraphicsObserver::~GraphicsObserver() {
    delete w;
    board->detach(this);
}

void GraphicsObserver::notify() {
    std::vector<Piece *> pieces = board->getPieces();
    for (auto p : pieces) {
        w->drawString(p->getFile() * 90 + 45, (7 - p->getRank()) * 90 + 45, std::string(1, p->getLetter()));
    }
}