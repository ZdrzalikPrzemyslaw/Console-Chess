//
// Created by Przemek on 29.12.2019.
//

#ifndef POBI_PROJ_SZACHY_FIELD_H
#define POBI_PROJ_SZACHY_FIELD_H

#include "Position.h"

struct Position;
class Piece;

class Field {
private:
    Position position;
public:
    Position get_position();
    Field(int, int);
    Piece get_piece();
    void set_piece(Piece);
    bool is_taken();
};


#endif //POBI_PROJ_SZACHY_FIELD_H
