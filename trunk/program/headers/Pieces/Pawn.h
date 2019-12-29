//
// Created by Przemek on 30.12.2019.
//

#ifndef POBI_PROJ_SZACHY_PAWN_H
#define POBI_PROJ_SZACHY_PAWN_H

#include "Piece.h"

class Pawn : public Piece{
private:
    bool has_moved = false;
public:
    int get_value();
    bool can_move(Field);

};


#endif //POBI_PROJ_SZACHY_PAWN_H
