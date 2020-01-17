//
// Created by Przemek on 17.01.2020.
//

#include "Player/Previous_Move.h"


Previous_Move::Previous_Move(Position beg_position, Position end_position, std::shared_ptr<Piece> piece_in_beg_position, std::shared_ptr<Piece> piece_in_end_position)
: beg_position(beg_position), end_position(end_position), piece_in_end_position(piece_in_end_position), piece_in_beg_position(piece_in_beg_position){}

Position Previous_Move::get_beg_pos() {
    return this->beg_position;
}

Position Previous_Move::get_end_pos() {
    return this->end_position;
}

std::shared_ptr<Piece> Previous_Move::get_piece_in_end_position() {
    return this->piece_in_end_position;
}

std::shared_ptr<Piece> Previous_Move::get_piece_in_beg_position() {
    return this->piece_in_beg_position;
}