//
// Created by premi on 13.01.2020.
//

#include "Player/Player.h"
#include "Pieces/Piece.h"


void Player::set_pieces(std::vector<std::shared_ptr<Piece>> pieces) {
    this->pieces = pieces;
}

void Player::calculate_score() {
    int tmp = 0;
    for (auto &i: this->captured_pieces) {
        tmp += i->get_value();
    }
    this->score = tmp;
}

int Player::get_score() {
    return this->score;
}