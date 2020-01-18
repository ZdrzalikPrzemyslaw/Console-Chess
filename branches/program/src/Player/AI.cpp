//
// Created by Przemek on 17.01.2020.
//

#include "Player/AI.h"
#include "random"
#include "Player/Move.h"
#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif

const int sleepMs = 500;

bool AI::move() {
#ifdef LINUX
    usleep(sleepMs * 1000);
#endif
#ifdef WINDOWS
    Sleep(sleepMs);
#endif
    int tmp = 0;
    std::shared_ptr<Move> ai_move;
    for(auto &i: this->get_all_moves()){
            tmp += i.size();
    }
    std::uniform_int_distribution<int> d(0,tmp - 1);
    std::random_device random1;
    int random_move_id = d(random1);
    tmp = 0;
    for(auto &i: this->get_all_moves()){
        for(auto &j : i){
            if(tmp == random_move_id){
            std::shared_ptr<Move> ai_move = j;
            }
            tmp += 1;
        }
    }

}