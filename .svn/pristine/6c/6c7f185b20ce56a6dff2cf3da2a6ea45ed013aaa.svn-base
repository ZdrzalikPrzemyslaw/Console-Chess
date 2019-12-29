//
// Created by Przemek on 29.12.2019.
//

#include <iostream>
#include "Board.h"
#include "Field.h"


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
    return this->fields[position.row][position.col];
}

int Board::board_size() {
    int tmp = 0;
    for(auto &i: this->fields){
        tmp += i.size();
    }
    return tmp;
}