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
    int get_value() final;
    bool can_move(std::shared_ptr<Field> field_final) final;
    using Piece::Piece;
    void set_has_moved(bool has_moved);
};


#endif //POBI_PROJ_SZACHY_PAWN_H
