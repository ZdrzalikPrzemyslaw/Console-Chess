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

Player::Player(bool is_white) : is_white(is_white) {}

std::shared_ptr<Board> Player::get_current_board_state() {
    return this->current_board_state;
}

void Player::set_current_board_state(std::shared_ptr<Board> current_board_state) {
    this->current_board_state = current_board_state;
}