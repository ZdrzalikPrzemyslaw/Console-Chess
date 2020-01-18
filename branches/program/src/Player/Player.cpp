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
#include "Player/Move.h"
#include "Player/Previous_Move.h"
#include <cstdlib>
#include <Pieces/Pawn.h>


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

Player::Player(bool is_white, std::vector<std::shared_ptr<Piece>> &pieces,
               std::vector<std::shared_ptr<Piece>> &enemy_pieces, std::shared_ptr<Board> &current_board_state)
        : is_white(is_white), pieces(pieces), enemy_pieces(enemy_pieces), current_board_state(current_board_state) {}

std::shared_ptr<Board> Player::get_current_board_state() {
    return this->current_board_state;
}

void Player::set_current_board_state(std::shared_ptr<Board> current_board_state) {
    this->current_board_state = current_board_state;
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

void Player::generate_all_moves() {
    int vectorindex = 0;
    for(auto &i: this->pieces){
        this->all_moves.push_back(std::vector<std::shared_ptr<Move>>());
        if(i->is_on_a_field()){
            for(auto &j: this->current_board_state->get_board()){
                for(auto &k: j){
                    if(i->can_move(k) && this->current_board_state->is_clear_path(i->get_field()->get_position(), k->get_position())){
                        this->all_moves[vectorindex].push_back(std::make_shared<Move>(i->get_field()->get_position(), k->get_position()));
                    }
                }
            }
        }
        vectorindex++;
    }
    auto i = this->all_moves.begin();
    while(i != this->all_moves.end()){
        auto j = i->begin();
        while(j != i->end()){
            if(!this->test_move(*j)){
                j = i->erase(j);
            } else ++j;
           }
        ++i;
    }

}

std::vector<std::vector<std::shared_ptr<Move>>> Player::get_all_moves() {
    return this->all_moves;
}

bool Player::test_move(std::shared_ptr<Move> move) {
        this->previous_move = std::make_shared<Previous_Move>(move->get_beg_pos(), move->get_end_pos(), this->current_board_state->get_field(move->get_beg_pos())->get_piece(),
            this->current_board_state->get_field(move->get_end_pos())->get_piece());
    if(!previous_move->get_piece_in_beg_position()) {
        return false;
    }
    if(this->get_current_board_state()->get_field(move->get_end_pos())->is_taken()) {
        this->get_current_board_state()->get_field(move->get_end_pos())->get_piece()->set_field(nullptr);
    }
    this->get_current_board_state()->get_field(move->get_end_pos())->set_piece(this->get_current_board_state()->get_field(move->get_beg_pos())->get_piece());
    this->get_current_board_state()->get_field(move->get_end_pos())->get_piece()->set_field(this->get_current_board_state()->get_field(move->get_end_pos()));
    this->get_current_board_state()->get_field(move->get_beg_pos())->set_piece(nullptr);
    bool tmp = !this->is_check();
    this->get_current_board_state()->get_field(move->get_beg_pos())->set_piece(this->previous_move->get_piece_in_beg_position());
    this->previous_move->get_piece_in_beg_position()->set_field(this->get_current_board_state()->get_field(move->get_beg_pos()));
    this->get_current_board_state()->get_field(move->get_end_pos())->set_piece(this->previous_move->get_piece_in_end_position());
    if(this->previous_move->get_piece_in_end_position()) {
        this->previous_move->get_piece_in_end_position()->set_field(this->get_current_board_state()->get_field(move->get_end_pos()));
    }
    return tmp;
}

void Player::capture(std::shared_ptr<Piece> piece) {
    try{
        if(piece == nullptr){
            throw std::runtime_error("Player::capture tried to capture a null pointer");
        }
        for (auto&i: this->pieces){
            if (i == piece){
                throw std::runtime_error("Player::capture tried to capture players own piece");
            }
        }
        for (auto &i: this->captured_pieces){
            if(i == piece){
                throw std::runtime_error("Player::capture tried to capture already captured piece");
            }
        }
    }
    catch(const std::runtime_error& e){
        std::cout<< "Caught " << typeid(e).name() << " in Player:capture "<< e.what() << "\n";
        exit(113);
        return;
    }
    this->captured_pieces.push_back(piece);
}

void Player::do_move(std::shared_ptr<Move> move) {
    if(auto x = dynamic_cast<Pawn*>(this->current_board_state->get_field(move->get_beg_pos())->get_piece().get())){
        x->set_has_moved(true);
    }
    if(this->current_board_state->get_field(move->get_end_pos())->get_piece()){
        capture(this->current_board_state->get_field(move->get_end_pos())->get_piece());
        this->current_board_state->get_field(move->get_end_pos())->get_piece()->set_field(nullptr);
    }
    this->current_board_state->get_field(move->get_end_pos())->set_piece(this->current_board_state->get_field(move->get_beg_pos())->get_piece());
    this->current_board_state->get_field(move->get_end_pos())->get_piece()->set_field( this->current_board_state->get_field(move->get_end_pos()));
    this->current_board_state->get_field(move->get_beg_pos())->set_piece(nullptr);
}

void Player::reset_all_moves() {
    this->all_moves.clear();
}

int Player::get_amount_of_moves() {
    int tmp = 0;
    for(auto &i : this->get_all_moves()){
            tmp += i.size();
    }
    return tmp;
}

void Player::queening(Position position) {
    if(!dynamic_cast<Pawn*>(this->current_board_state->get_field(position)->get_piece().get())){
        return;
    }
    std::shared_ptr<Piece> new_queen = std::make_shared<Queen>(this->current_board_state->get_field(position)->get_piece()->get_is_white());
    auto it = this->pieces.begin();
    while(it != this->pieces.end()){
        if (*it == this->current_board_state->get_field(position)->get_piece()){
            it = this->pieces.erase(it);
        }else ++it;

    }
    this->pieces.push_back(new_queen);

    this->get_current_board_state()->get_field(position)->get_piece()->set_field(nullptr);
    this->get_current_board_state()->get_field(position)->set_piece(new_queen);
    this->get_current_board_state()->get_field(position)->get_piece()->set_field(this->current_board_state->get_field(position));

    std::cout << "\n\n\n\n\n" << "QUEEENING" << "\n";
    for(auto &i :this->get_pieces()){
        std::cout << i->get_is_white() << " " << i->is_on_a_field() << " \n";
    }
}