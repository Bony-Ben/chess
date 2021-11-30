#ifndef _GOBSERVER_H_
#define _GOBSERVER_H_
#include "../board.h"
#include "observer.h"
#include "window.h"

class Board;

class GraphicsObserver : public Observer {
    Board *board;
    Xwindow *w;

   public:
    GraphicsObserver(Board *board);
    void notify() override;
    ~GraphicsObserver();
};

#endif