//
// Created by Przemek on 30.12.2019.
//

#ifndef POBI_PROJ_SZACHY_BISHOP_H
#define POBI_PROJ_SZACHY_BISHOP_H


#include "Piece.h"

class Bishop : public Piece {
public:
    int get_value() final;
    bool can_move(std::shared_ptr<Field>) final;
    using Piece::Piece;
};


#endif //POBI_PROJ_SZACHY_BISHOP_H
