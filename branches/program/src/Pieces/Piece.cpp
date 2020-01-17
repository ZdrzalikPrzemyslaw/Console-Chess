//
// Created by Przemek on 29.12.2019.
//

#include "Pieces/Piece.h"
#include "Field.h"

bool Piece::get_is_white() {
    return  this->is_white;
}

Piece::Piece(bool is_white) : is_white(is_white), field(nullptr) {}

std::shared_ptr<Field> Piece::get_field() {
    return this->field;
}

bool Piece::is_on_a_field() {
    return !(get_field() == nullptr);
}

void Piece::set_field(std::shared_ptr<Field> field) {
    this->field = field;
}


