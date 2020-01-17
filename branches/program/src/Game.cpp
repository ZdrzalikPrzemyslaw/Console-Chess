//
// Created by premi on 09.01.2020.
//

#include "Game.h"

#include "Pieces/Piece.h"
#include "Pieces/Pawn.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/King.h"

#include "Board.h"

#include "Field.h"

#include <iostream>

void Game::initialize() {
    auto tmp = std::make_shared<Board>();
    this->board = tmp;
    for (int i = 0; i < 8; i++) {
        this->white_pieces.push_back(std::make_shared<Pawn>(true));
        this->black_pieces.push_back(std::make_shared<Pawn>(false));
    }
    for (int i = 0; i < 2; i++){
        this->white_pieces.push_back(std::make_shared<Rook>(true));
        this->black_pieces.push_back(std::make_shared<Rook>(false));
        this->white_pieces.push_back(std::make_shared<Knight>(true));
        this->black_pieces.push_back(std::make_shared<Knight>(false));
        this->white_pieces.push_back(std::make_shared<Bishop>(true));
        this->black_pieces.push_back(std::make_shared<Bishop>(false));
    }
    this->white_pieces.push_back(std::make_shared<Queen>(true));
    this->white_pieces.push_back(std::make_shared<King>(true));
    this->black_pieces.push_back(std::make_shared<Queen>(false));
    this->black_pieces.push_back(std::make_shared<King>(false));

    int i = 0;
    while(i <= 7){
        this->board->get_board()[1][i]->set_piece(this->white_pieces[i]);
        this->white_pieces[i]->set_field(this->board->get_board()[1][i]);
        this->board->get_board()[6][i]->set_piece(this->black_pieces[i]);
        this->black_pieces[i]->set_field(this->board->get_board()[6][i]);
        i++;
    }

    this->board->get_board()[0][0]->set_piece(this->white_pieces[8]);
    this->white_pieces[8]->set_field(this->board->get_board()[0][0]);
    this->board->get_board()[7][0]->set_piece(this->black_pieces[8]);
    this->black_pieces[8]->set_field(this->board->get_board()[7][0]);

    this->board->get_board()[0][7]->set_piece(this->white_pieces[9]);
    this->white_pieces[9]->set_field(this->board->get_board()[0][7]);
    this->board->get_board()[7][7]->set_piece(this->black_pieces[9]);
    this->black_pieces[9]->set_field(this->board->get_board()[7][7]);

    this->board->get_board()[0][1]->set_piece(this->white_pieces[10]);
    this->white_pieces[10]->set_field(this->board->get_board()[0][1]);
    this->board->get_board()[7][1]->set_piece(this->black_pieces[10]);
    this->black_pieces[10]->set_field(this->board->get_board()[7][1]);

    this->board->get_board()[0][6]->set_piece(this->white_pieces[11]);
    this->white_pieces[11]->set_field(this->board->get_board()[0][6]);
    this->board->get_board()[7][6]->set_piece(this->black_pieces[11]);
    this->black_pieces[11]->set_field(this->board->get_board()[7][6]);

    this->board->get_board()[0][2]->set_piece(this->white_pieces[12]);
    this->white_pieces[12]->set_field(this->board->get_board()[0][2]);
    this->board->get_board()[7][2]->set_piece(this->black_pieces[12]);
    this->black_pieces[12]->set_field(this->board->get_board()[7][2]);

    this->board->get_board()[0][5]->set_piece(this->white_pieces[13]);
    this->white_pieces[13]->set_field(this->board->get_board()[0][5]);
    this->board->get_board()[7][5]->set_piece(this->black_pieces[13]);
    this->black_pieces[13]->set_field(this->board->get_board()[7][5]);

    this->board->get_board()[0][3]->set_piece(this->white_pieces[14]);
    this->white_pieces[14]->set_field(this->board->get_board()[0][3]);
    this->board->get_board()[7][3]->set_piece(this->black_pieces[14]);
    this->black_pieces[14]->set_field(this->board->get_board()[7][3]);

    this->board->get_board()[0][4]->set_piece(this->white_pieces[15]);
    this->white_pieces[15]->set_field(this->board->get_board()[0][4]);
    this->board->get_board()[7][4]->set_piece(this->black_pieces[15]);
    this->black_pieces[15]->set_field(this->board->get_board()[7][4]);
}

Game::Game(){
    //initialize();
}
/*
const std::shared_ptr<Board> &Game::get_board() const {
    return board;
}

const std::vector<std::shared_ptr<Piece>> &Game::get_white_pieces() const {
    return white_pieces;
}

const std::vector<std::shared_ptr<Piece>> &Game::get_black_pieces() const {
    return black_pieces;
}

//const std::vector<std::shared_ptr<Player>> &Game::get_players() const {
//    return players;
//}

 */