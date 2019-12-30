//
// Created by Przemek on 30.12.2019.
//

#ifndef POBI_PROJ_SZACHY_KING_H
#define POBI_PROJ_SZACHY_KING_H


#include "Piece.h"

class King : public Piece{
public:
    int get_value()  final;
    bool can_move(Field) final;
};


#endif //POBI_PROJ_SZACHY_KING_H
