//
// Created by Przemek on 29.12.2019.
//

#include <iostream>
#include "Board.h"
#include "Field.h"
#include "Pieces/Piece.h"
#include <algorithm>


const int board_dimensions = 8;

Board::Board() {
    for(int i = 0; i < 8; i++){
        fields.push_back(std::vector<std::shared_ptr<Field>>());
        for(int j = 0; j < 8; j++){
            auto tmp = std::make_shared<Field>(i,j);
            this->fields[i].push_back(tmp);
        }
    }
}

std::vector<std::vector<std::shared_ptr<Field>>> Board::get_board() {
    return this->fields;
}

std::shared_ptr<Field> Board::get_field(Position position) {
    if (position.row < 0 || (position.col < 0)) {
        throw std::out_of_range(
                "VECTOR INDEX HAS TO BE A NATURAL NUMBER");
    }
    if(position.row > board_dimensions - 1 || position.col > board_dimensions - 1){
        throw std::out_of_range(
                "VECTOR INDEX HAS TO BE SMALLER THAN BOARD DIMENSIONS - 1");
    }
    return this->fields[position.row][position.col];
}

int Board::board_size() {
    int tmp = 0;
    for(auto &i: this->fields){
        tmp += i.size();
    }
    return tmp;
}

bool Board::is_clear_path(Position pos_beg,  Position pos_end) {
    try{
        if(pos_beg == pos_end) {
            throw std::runtime_error("attempted to check clear path in place");
        }
    }
    catch(const std::runtime_error& e){
        std::cout<< "Caught " << typeid(e).name() << " in Board::is_clear_path "<< e.what() << "\n";
        return false;
    }
    if(this->get_field(pos_beg)->get_piece() && this->get_field(pos_end)->get_piece() && this->get_field(pos_beg)->get_piece()->get_is_white() == this->get_field(pos_end)->get_piece()->get_is_white()){
        return false;
    }
    if(pos_beg.col - pos_end.col == 0){
        for(int i = std::min(pos_beg.row, pos_end.row) + 1; i < (std::max(pos_beg.row, pos_end.row)); i++){
            if(this->get_field(Position(i, pos_beg.col))->get_piece() != nullptr){
                return false;
            }
        }
    }
    if(pos_beg.row - pos_end.row == 0){
        for(int i = std::min(pos_beg.col, pos_end.col) + 1; i < (std::max(pos_beg.col, pos_end.col)); i++){
            if(this->get_field(Position(pos_beg.row, i))->get_piece() != nullptr){
                return false;
            }
        }

    }
    if((abs(pos_beg.col - pos_end.col) - abs(pos_beg.row - pos_end.row)) == 0) {
        if(pos_end.col > pos_beg.col && (pos_end.row > pos_beg.row)){
            int change = 1;
            while(pos_beg.col + change != pos_end.col){
                if(this->get_field(Position(pos_beg.row + change, pos_beg.col + change))->get_piece() != nullptr){
                    return false;
                }
                change++;
            }
        }
        if(pos_end.col < pos_beg.col && (pos_end.row > pos_beg.row)){
            int change = 1;
            while(pos_beg.col - change != pos_end.col){
                if(this->get_field(Position(pos_beg.row + change, pos_beg.col - change))->get_piece() != nullptr){
                    return false;
                }
                change++;
            }
        }
        if(pos_end.col > pos_beg.col && (pos_end.row < pos_beg.row)){
            int change = 1;
            while(pos_beg.col + change != pos_end.col){
                if(this->get_field(Position(pos_beg.row - change, pos_beg.col + change))->get_piece() != nullptr){
                    return false;
                }
                change++;
            }
        }
        if(pos_end.col < pos_beg.col && (pos_end.row < pos_beg.row)){
            int change = 1;
            while(pos_beg.col - change != pos_end.col){
                if(this->get_field(Position(pos_beg.row - change, pos_beg.col - change))->get_piece() != nullptr){
                    return false;
                }
                change++;
            }
        }
    }
    return true;
}

