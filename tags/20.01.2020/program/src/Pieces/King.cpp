//
// Created by Przemek on 30.12.2019.
//

#include "Pieces/King.h"
#include "Field.h"

int King::get_value() {
    return king_value;
}

//King::King(bool is_white) : Piece(is_white) {}

bool King::can_move(std::shared_ptr<Field> field_final) {
    Position tmp = field_final->get_position();
    if (this->get_field()->get_position().operator==(tmp)) {
        return false; // no moving to it's own location
    }
    if(abs(this->get_field()->get_position().row - field_final->get_position().row) <= 1 && abs(this->get_field()->get_position().col - field_final->get_position().col) <= 1) {
        return true;
    }
    return false;
}