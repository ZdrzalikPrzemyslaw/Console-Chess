//
// Created by Przemek on 17.01.2020.
//

#ifndef POBI_PROJ_SZACHY_AI_H
#define POBI_PROJ_SZACHY_AI_H


#include "Player.h"

class AI : public Player {
public:
    bool move() override;
    using Player::Player;
};


#endif //POBI_PROJ_SZACHY_AI_H
