#include "graphicsobserver.h"

#include <iostream>
#include <string>

GraphicsObserver::GraphicsObserver(Board *board) : board{board} {
    w = new Xwindow(720, 720);
    bool white = true;
    for (int y = 0; y <= 630; y += 90) {
        for (int x = 0; x <= 630; x += 90) {
            if (!white) {
                w->fillRectangle(x, y, 90, 90);
            }
            white = !white;
        }
        white = !white;
    }
    int num_label = 8;
    char alph_label = 'A';
    for (int y = 45; y <= 640; y += 180) {
        w->drawString(10, y, std::to_string(num_label), Xwindow::Black);
        w->drawString(10, y + 90, std::to_string(num_label - 1), Xwindow::White);
        w->drawString(y, 710, std::string(1, alph_label), Xwindow::White);
        w->drawString(y + 90, 710, std::string(1, alph_label + 1), Xwindow::Black);
        num_label -= 2;
        alph_label += 2;
    }
    std::vector<Piece *> pieces = board->getPieces();
    for (auto p : pieces) {
        if ((p->getRank() % 2) != (p->getFile() % 2)) {
            w->drawString(p->getFile() * 90 + 45, (7 - p->getRank()) * 90 + 45, std::string(1, p->getLetter()), Xwindow::Black);
        } else {
            w->drawString(p->getFile() * 90 + 45, (7 - p->getRank()) * 90 + 45, std::string(1, p->getLetter()), Xwindow::White);
        }
    }
    board->attach(this);
}

GraphicsObserver::~GraphicsObserver() {
    delete w;
    board->detach(this);
}

void GraphicsObserver::notify() {
    bool white = true;
    for (int y = 0; y <= 630; y += 90) {
        for (int x = 0; x <= 630; x += 90) {
            if (white) {
                w->fillRectangle(x + 35, y + 35, 20, 20, Xwindow::White);
            } else {
                w->fillRectangle(x + 35, y + 35, 20, 20);
            }
            white = !white;
        }
        white = !white;
    }
    std::vector<Piece *> pieces = board->getPieces();
    for (auto p : pieces) {
        if ((p->getRank() % 2) != (p->getFile() % 2)) {
            w->drawString(p->getFile() * 90 + 45, (7 - p->getRank()) * 90 + 45, std::string(1, p->getLetter()), Xwindow::Black);
        } else {
            w->drawString(p->getFile() * 90 + 45, (7 - p->getRank()) * 90 + 45, std::string(1, p->getLetter()), Xwindow::White);
        }
    }
}