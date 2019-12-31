//
// Created by Przemek on 30.12.2019.
//

#ifndef POBI_PROJ_SZACHY_ROOK_H
#define POBI_PROJ_SZACHY_ROOK_H


#include "Piece.h"

class Rook : public Piece{
public:
    int get_value() final;
    bool can_move(std::shared_ptr<Field>) final;
};


#endif //POBI_PROJ_SZACHY_ROOK_H
