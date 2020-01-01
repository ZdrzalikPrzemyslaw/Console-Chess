//
// Created by Przemek on 30.12.2019.
//

#include "Pieces/Pawn.h"
#include "Field.h"



int Pawn::get_value() {
    return pawn_value;
}

Pawn::Pawn(bool is_white) : Piece(is_white){}



bool Pawn::can_move(std::shared_ptr<Field> field_final) { // board row count starts at 0 ends at 7. Black pawns start at row 7, white at row 1. (Player sees the pieces on fields 1-8)
    Position tmp = field_final->get_position();
    if (this->get_field()->get_position().operator==(tmp)) {
        return false;
    }
    if (this->get_is_white()){
        if (field_final->get_position().row - this->get_field()->get_position().row == 2 &&
        (!this->has_moved) &&
        (field_final->get_position().col == this->get_field()->get_position().col)){
            return true;
        }
        if(field_final->get_position().row - this->get_field()->get_position().row == 1 &&
        (field_final->get_position().col == this->get_field()->get_position().col)) {
            return true;
        }
        if(field_final->get_position().row - this->get_field()->get_position().row == 1 &&
        (abs(field_final->get_position().col - this->get_field()->get_position().col) == 1) &&
        (field_final->get_piece() != nullptr)
        && (field_final->get_piece()->get_is_white() != this->get_is_white())){
            return true; // normally the pieces don't check if the path they want to take is valid.
                                 // this is the 1 exception because the way the pawn moves changes depending on if he can attack.
        }
    }
    if(!this->get_is_white()){
        if (field_final->get_position().row - this->get_field()->get_position().row == -2 &&
        (!this->has_moved) &&
        (field_final->get_position().col == this->get_field()->get_position().col)){
            return true;
        }
        if(field_final->get_position().row - this->get_field()->get_position().row == -1 &&
        (field_final->get_position().col == this->get_field()->get_position().col)) {
            return true;
        }
        if(field_final->get_position().row - this->get_field()->get_position().row == -1 &&
        (abs(field_final->get_position().col - this->get_field()->get_position().col) == 1) &&
        (field_final->get_piece() != nullptr) &&
        (field_final->get_piece()->get_is_white() != this->get_is_white())){
            return true; // normally the pieces don't check if the path they want to take is valid.
                                 // this is the 1 exception because the way the pawn moves changes depending on if he can attack.
        }
    }
    return false;
}

void Pawn::set_has_moved(bool has_moved) {
    this->has_moved = has_moved;
}

