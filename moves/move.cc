#include "move.h"

Move::Move(bool check) : check{check} {};

bool Move::isCheck() {
    return check;
}