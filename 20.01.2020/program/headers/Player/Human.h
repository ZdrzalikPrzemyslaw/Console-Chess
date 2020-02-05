//
// Created by Przemek on 17.01.2020.
//

#ifndef POBI_PROJ_SZACHY_HUMAN_H
#define POBI_PROJ_SZACHY_HUMAN_H


#include "Player.h"
#include "Position.h"

class Human : public Player {
public:
    bool move() override;
    using Player::Player;
private:
    Position parse_input_to_position(std::string input);
};


#endif //POBI_PROJ_SZACHY_HUMAN_H
