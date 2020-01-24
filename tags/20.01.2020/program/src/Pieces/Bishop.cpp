//
// Created by Przemek on 30.12.2019.
//

#include "Pieces/Bishop.h"
#include "Field.h"

int Bishop::get_value() {
    return bishop_value;
}

bool Bishop::can_move(std::shared_ptr<Field> field_final) {
    Position tmp = field_final->get_position();
    if (this->get_field()->get_position().operator==(tmp)) {
        return false; // no moving to it's own location
    }
    if(abs(this->get_field()->get_position().row - field_final->get_position().row) == abs(this->get_field()->get_position().col - field_final->get_position().col)) {
        return true;
    }
    return false;
}
