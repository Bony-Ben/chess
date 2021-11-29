#ifndef _GOBSERVER_H_
#define _GOBSERVER_H_
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