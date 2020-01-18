//
// Created by premi on 13.01.2020.
//

#include "Player/Move.h"


Position Move::get_beg_pos() {
    return this->beg_position;
}

Position Move::get_end_pos() {
    return this->end_position;
}

Move::Move(Position beg_pos, Position end_pos) : beg_position(beg_pos), end_position(end_pos) {}