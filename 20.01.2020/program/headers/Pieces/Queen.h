//
// Created by Przemek on 30.12.2019.
//

#ifndef POBI_PROJ_SZACHY_QUEEN_H
#define POBI_PROJ_SZACHY_QUEEN_H


#include "Piece.h"

class Queen : public Piece {
public:
    int get_value() final;
    bool can_move(std::shared_ptr<Field> field_final) final;
    using Piece::Piece;
};


#endif //POBI_PROJ_SZACHY_QUEEN_H
