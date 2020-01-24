//
// Created by Przemek on 30.12.2019.
//

#include "Pieces/Rook.h"
#include "Field.h"

int Rook::get_value() {
    return rook_value;
}

bool Rook::can_move(std::shared_ptr<Field> field_final) {
    Position tmp = field_final->get_position();
    if (this->get_field()->get_position().operator==(tmp)) {
        return false; // no moving to it's own location
    }
    if(this->get_field()->get_position().col == field_final->get_position().col){
        return true;
    }
    if(this->get_field()->get_position().row == field_final->get_position().row){
        return true;
    }
    return false;
}