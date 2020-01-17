//
// Created by Przemek on 17.01.2020.
//

#ifndef POBI_PROJ_SZACHY_PREVIOUS_MOVE_H
#define POBI_PROJ_SZACHY_PREVIOUS_MOVE_H

#include <memory>
#include "Position.h"
class Piece;

class Previous_Move {
private:
    Position beg_position;
    Position end_position;
    std::shared_ptr<Piece> piece_in_end_position;
public:
    Position get_beg_pos();
    Position get_end_pos();
    std::shared_ptr<Piece> get_piece_in_end_position
};


#endif //POBI_PROJ_SZACHY_PREVIOUS_MOVE_H
