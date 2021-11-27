#ifndef _TOBSERVER_H_
#define _TOBSERVER_H_
#include "observer.h"

class Board;

class TextObserver : public Observer {
    Board *board;

   public:
    TextObserver(Board *Board);
    void notify() override;
    ~TextObserver();
};

#endif