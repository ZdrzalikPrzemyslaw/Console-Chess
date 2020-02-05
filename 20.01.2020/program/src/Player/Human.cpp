//
// Created by Przemek on 17.01.2020.
//

#include "iostream"
#include "Position.h"
#include "Player/Human.h"
#include "Player/Move.h"
#include "Board.h"
#include "Pieces/Piece.h"
#include "Field.h"
#ifdef __linux__

#include <limits.h>

#endif


bool Human::move() {
    std::cout <<"\n";
    std::string input;
    Position choose_piece(-1,-1);
    std::vector<std::shared_ptr<Move>> avaiable_moves;
    while (input.length()!= 2 || choose_piece.row == -1 || avaiable_moves.empty()) {
        avaiable_moves.clear();
        std::cout << "Choose piece that you want to move: ";
        std::cin >> input;
        std::cout << "\n";
        while (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Choose piece that you want to move: ";
            std::cin >> input;
            std::cout << "\n";
        }
        choose_piece = this->parse_input_to_position(input);
        for (auto &i: this->get_all_moves()) {
            for (auto &j: i) {
                if (j->get_beg_pos() == choose_piece) {
                    avaiable_moves.push_back(j);
                }
            }
        }
        if (avaiable_moves.empty()) {
            std::cout << "No avaiable moves for this piece \n";
        }
        else {
            std::cout << "avaiable moves for this piece:" << "\n";
            for (auto &i : avaiable_moves) {
                std::cout << "Col: " << char(i->get_end_pos().col + 'A')<< " Row: " << i->get_end_pos().row + 1 << "\n";
            }
            input.clear();
            choose_piece.row = -1;
            choose_piece.col = -1;
            bool is_in_avaiable_moves = false;
            while(input != "redo" && (input.length()!= 2 || choose_piece.row == -1 || !is_in_avaiable_moves)){
                std::cout << "Choose one of the avaiable moves or write 'redo' to choose another piece :";
                std::cin >> input;
                std::cout << "\n";
                while (!std::cin.good()) {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Choose one of the avaiable moves or write 'redo' to choose another piece" << "\n";
                    std::cin >> input;
                    std::cout << "\n";
                }
                if(input != "redo"){
                    choose_piece = parse_input_to_position(input);
                    for (auto &i : avaiable_moves) {
                        if(i->get_end_pos() == choose_piece){
                            do_move(i);
                            if (i->get_end_pos().row == 7 && this->get_current_board_state()->get_field(i->get_end_pos())->get_piece()->get_is_white()){
                                this->queening(i->get_end_pos());
                            }
                            else if(i->get_end_pos().row == 0 && !this->get_current_board_state()->get_field(i->get_end_pos())->get_piece()->get_is_white()){
                                this->queening(i->get_end_pos());
                            }
                            return true;
                        }
                    }

                }

            }

        }

    }
    return false;
}

Position Human::parse_input_to_position(std::string input) {
    Position position(-1,-1);
    //std::cout << " " << char(input[0]) << " " << static_cast<int>(input[1]) - '0';
    if(!((char(input[0])>=char('A') && char(input[0])<=char('H')) || (char(input[0])>=char('a') && char(input[0])<=char('h')))){
        return Position(-1,-1);
    }
    if(char(input[0])>=char('A') && char(input[0])<=char('H')){
        position.col = int(input[0]) - 'A';
    }
    else if (char(input[0])>=char('a') && char(input[0])<=char('h')){
        position.col = int(input[0]) - 'a';
    }
    if(int(input[1]) - '0' > 8 || int(input[1]) - '0' < 1){
        return Position(-1,-1);
    }
    else{
        position.row = int(input[1]) - '0' - 1;
    }
    return position;

}