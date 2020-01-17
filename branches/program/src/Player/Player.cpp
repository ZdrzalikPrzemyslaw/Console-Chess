//
// Created by premi on 13.01.2020.
//

#include "Player/Player.h"
#include "Pieces/Piece.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Board.h"
#include "Field.h"
#include "iostream"


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

void Player::set_enemy_pieces(std::vector<std::shared_ptr<Piece>> enemy_pieces) {
    this->enemy_pieces = enemy_pieces;
}

std::vector<std::shared_ptr<Piece>> Player::get_pieces() {
    return this->pieces;
}

std::vector<std::shared_ptr<Piece>> Player::get_enemy_pieces() {
    return this->enemy_pieces;
}

bool Player::is_check() {
    for(auto &i : this->pieces){
        if(dynamic_cast<King*>(i.get()) != nullptr){
            for(auto &j : this->enemy_pieces){
                if(j->is_on_a_field() && j->can_move(i->get_field()) && this->get_current_board_state()->is_clear_path(j->get_field()->get_position(), i->get_field()->get_position())){
                    return true;
                }
            }

        }
    }
    return false;
}