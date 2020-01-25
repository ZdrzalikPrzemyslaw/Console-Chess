//
// Created by Przemek on 17.01.2020.
//

#include "iostream"
#include "Position.h"
#include "Player/Human.h"
#include "Player/Move.h"
#include "Board.h"
#include "Pieces/Piece.h"
#include "Field.h"
#ifdef __linux__

#include <limits.h>

#endif


void Human::move(std::shared_ptr<Move> move){
    if (move == nullptr){
            throw std::logic_error ("Human::Move, move can't be nullptr, exiting");
    }
    this->do_move(move);
    this->queening(move->get_end_pos());
}

