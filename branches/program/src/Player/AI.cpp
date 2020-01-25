//
// Created by Przemek on 17.01.2020.
//

#include "Player/AI.h"
#include "random"
#include "Player/Move.h"
#include "Pieces/Piece.h"
#include <iostream>
#include "Board.h"
#include "Field.h"
#ifdef linux
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

const int sleepMs = 5000;

void AI::move(std::shared_ptr<Move> move) {
#ifdef linux
    usleep(sleepMs * 1000);
#elif _WIN32
    Sleep(sleepMs);
#endif
    int tmp = 0;
    std::shared_ptr<Move> ai_move;
    try{
        if (this->get_all_moves().empty()){
            throw std::runtime_error("all moves vector empty");
        }
    }
    catch(const std::runtime_error& e){
        std::cout << "Caught " << typeid(e).name() << " in AI::move " << e.what() << "\n";
        return;
    }
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
                this->do_move(j);
                this->queening(j->get_end_pos());
            }
            tmp += 1;
        }
    }
}