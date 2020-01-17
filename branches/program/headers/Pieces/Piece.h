//
// Created by Przemek on 29.12.2019.
//

#ifndef POBI_PROJ_SZACHY_PIECE_H
#define POBI_PROJ_SZACHY_PIECE_H
#include "memory"
class Field;

const int pawn_value = 1;
const int knight_value = 3;
const int bishop_value = 3;
const int rook_value = 5;
const int queen_value = 9;
const int king_value = SHRT_MAX;


class Piece {
private:
    bool is_white;
    std::shared_ptr<Field> field;
public:
    virtual int get_value() = 0;
    bool get_is_white();
    virtual bool can_move(std::shared_ptr<Field> field_final) = 0;
    explicit Piece(bool is_white);
    bool is_on_a_field();
    void set_field(std::shared_ptr<Field> new_field);
    std::shared_ptr<Field> get_field();
};


#endif //POBI_PROJ_SZACHY_PIECE_H
