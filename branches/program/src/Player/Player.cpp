//
// Created by premi on 13.01.2020.
//

#include "Player/Player.h"


void Player::set_pieces(std::vector<std::shared_ptr<Piece>> pieces) {
    this->pieces = pieces;
}