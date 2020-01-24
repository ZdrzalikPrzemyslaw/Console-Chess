//
// Created by Przemek on 29.12.2019.
//

#include "Field.h"
#include "Pieces/Piece.h"

Field::Field(int row, int col) : position(Position(row, col)) {}

Field::Field(Position position) : position(position) {}

Position Field::get_position() {
    return this->position;
}

std::shared_ptr<Piece> Field::get_piece() {
    return this->piece;
}

void Field::set_piece(std::shared_ptr<Piece> piece) {
    this->piece = piece;
}

bool Field::is_taken() {
    return !(this->get_piece() == nullptr);
}