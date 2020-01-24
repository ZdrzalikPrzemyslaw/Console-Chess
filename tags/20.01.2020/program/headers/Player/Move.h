//
// Created by premi on 13.01.2020.
//

#ifndef POBI_PROJ_SZACHY_MOVE_H
#define POBI_PROJ_SZACHY_MOVE_H

#include "Position.h"
#include <memory>

class Field;

class Move {
private:
    Position beg_position;
    Position end_position;
public:
    Position get_beg_pos();

    Position get_end_pos();

    Move(Position beg_pos, Position end_pos);
};




#endif //POBI_PROJ_SZACHY_MOVE_H
