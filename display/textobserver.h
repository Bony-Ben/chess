#ifndef _TOBSERVER_H_
#define _TOBSERVER_H_
#include "../board.h"
#include "observer.h"

class Board;

class TextObserver : public Observer {
    Board *board;

   public:
    TextObserver(Board *board);
    void notify() override;
    ~TextObserver();
};

#endif