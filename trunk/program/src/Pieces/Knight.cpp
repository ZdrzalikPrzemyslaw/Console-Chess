//
// Created by Przemek on 30.12.2019.
//

#include "Pieces/Knight.h"
#include "Field.h"
#include "iostream"



int Knight::get_value() {
    return knight_value;
}

bool Knight::can_move(std::shared_ptr<Field> field_final) {

    // const int row_next[8] = { 2, 1, -1, -2, -2, -1,  1,  2 } ;
    // const int col_next[8] = { 1, 2,  2,  1, -1, -2, -2, -1 }; // all possible knight moves

    if(((abs(this->get_field()->get_position().row - field_final->get_position().row) == 2) &&
    (abs(this->get_field()->get_position().col - field_final->get_position().col) == 1)) ||
    ((abs(this->get_field()->get_position().row - field_final->get_position().row) == 1) &&
    (abs(this->get_field()->get_position().col - field_final->get_position().col) == 2))){
        return true;
    }
    return false;
}