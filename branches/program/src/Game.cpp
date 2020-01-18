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

#include "Player/Player.h"
#include "Player/Human.h"
#include "Player/AI.h"

#include <iostream>
#include <iomanip>

void Game::initialize(bool is_ai_player1, bool is_ai_player2) {
    auto tmp = std::make_shared<Board>();
    this->board = tmp;
    for (int i = 0; i < 8; i++) {
        this->white_pieces.push_back(std::make_shared<Pawn>(true));
        this->black_pieces.push_back(std::make_shared<Pawn>(false));
    }
    for (int i = 0; i < 2; i++){
        this->white_pieces.push_back(std::make_shared<Rook>(true));
        this->black_pieces.push_back(std::make_shared<Rook>(false));
    }
    for (int i = 0; i < 2; i++) {
        this->white_pieces.push_back(std::make_shared<Knight>(true));
        this->black_pieces.push_back(std::make_shared<Knight>(false));
    }
    for (int i = 0; i < 2; i++) {
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

    this->board->get_board()[0][4]->set_piece(this->white_pieces[14]);
    this->white_pieces[14]->set_field(this->board->get_board()[0][4]);
    this->board->get_board()[7][4]->set_piece(this->black_pieces[14]);
    this->black_pieces[14]->set_field(this->board->get_board()[7][4]);

    this->board->get_board()[0][3]->set_piece(this->white_pieces[15]);
    this->white_pieces[15]->set_field(this->board->get_board()[0][3]);
    this->board->get_board()[7][3]->set_piece(this->black_pieces[15]);
    this->black_pieces[15]->set_field(this->board->get_board()[7][3]);
    if(!is_ai_player1){
        this->players.push_back(std::make_shared<Human>(true, this->white_pieces, this->black_pieces, this->get_board()));
    }else{
        this->players.push_back(std::make_shared<AI>(true, this->white_pieces, this->black_pieces, this->get_board()));
    }
    if(!is_ai_player2){
        this->players.push_back(std::make_shared<Human>(false, this->black_pieces, this->white_pieces, this->get_board()));
    }else{
        this->players.push_back(std::make_shared<AI>(false, this->black_pieces, this->white_pieces, this->get_board()));
    }
//    std::vector<std::shared_ptr<Piece>> &vector_ref_white = this->white_pieces;
//    std::vector<std::shared_ptr<Piece>> &vector_ref_black = this->black_pieces;
//    this->get_white_player()->set_pieces(vector_ref_white);
//    this->get_white_player()->set_enemy_pieces(vector_ref_black);
//    this->get_black_player()->set_pieces(vector_ref_white);
//    this->get_black_player()->set_enemy_pieces(vector_ref_black);
}

Game::Game(){
    initialize();
    this->game_begin_time = boost::posix_time::ptime(boost::posix_time::second_clock::local_time());
}

Game::Game(bool is_ai_player1, bool is_ai_player2) {
    initialize(is_ai_player1, is_ai_player2);
}

 std::shared_ptr<Board> & Game::get_board()  {
    return this->board;
}

std::vector<std::shared_ptr<Piece>> &Game::get_white_pieces()  {
    return this->white_pieces;
}

std::vector<std::shared_ptr<Piece>> &Game::get_black_pieces()  {
    return black_pieces;
}

const std::shared_ptr<Player>& Game::get_white_player() const {
    return this->players[0];
}

const std::shared_ptr<Player>& Game::get_black_player() const {
    return this->players[1];
}

void Game::draw() {
#ifdef linux
    const char * left_upper_corner  = u8"\u250C";
    const char * left_lower_corner  = u8"\u2514";
    const char * line_horizontal    = u8"\u2501";
    const char * line_vertical      = u8"\u2502";
    const char * right_upper_corner = u8"\u2510";
    const char * right_lower_corner = u8"\u2519";
    const char * joint_left         = u8"\u2520";
    const char * joint_right        = u8"\u2525";
    const char * joint_upper        = u8"\u2530";
    const char * joint_lower        = u8"\u2538";
    const char * joint_middle       = u8"\u2540";
#elif _WIN32
    const char left_upper_corner = char(218);
    const char left_lower_corner = char(192);
    const char line_horizontal = char(196);
    const char line_vertical = char(179);
    const char right_upper_corner = char(191);
    const char right_lower_corner = char(217);
    const char joint_left = char(195);
    const char joint_right = char(180);
    const char joint_upper = char(194);
    const char joint_lower = char(193);
    const char joint_middle = char(197);
#else

#endif
    const char field = ' ';
    const char figure_name_pawn = 'P';
    const char figure_name_rook = 'R';
    const char figure_name_bishop = 'B';
    const char figure_name_knight = 'H';
    const char figure_name_king = 'K';
    const char figure_name_queen = 'Q';
    const char figure_color_white = 'w';
    const char figure_color_black = 'b';
    const std::string no_figure_on_field = "  ";
    std::vector<std::vector<std::string>> figure_color_name;
    int index1 = 0;
    int index2 = 0;
    for(auto &i : this->board->get_board()){
        figure_color_name.push_back(std::vector<std::string>());
        for(auto &j : i){
            figure_color_name[index2].push_back(std::string());
            auto test = this->board->get_board()[index2][index1]->get_piece();
            if(!test){
                figure_color_name[index2][index1] = no_figure_on_field;
            }
            else{
                if(test->get_is_white()){
                    figure_color_name[index2][index1] = figure_color_white;
                }
                else{
                    figure_color_name[index2][index1] = figure_color_black;
                }
                if(dynamic_cast<Bishop*>(test.get())){
                    figure_color_name[index2][index1] += figure_name_bishop;
                }
                else if (dynamic_cast<King*>(test.get())){
                    figure_color_name[index2][index1] += figure_name_king;
                }
                else if(dynamic_cast<Knight*>(test.get())){
                    figure_color_name[index2][index1] += figure_name_knight;
                }
                else if (dynamic_cast<Pawn*>(test.get())){
                    figure_color_name[index2][index1] += figure_name_pawn;
                }
                else if(dynamic_cast<Queen*>(test.get())){
                    figure_color_name[index2][index1] += figure_name_queen;
                }
                else if(dynamic_cast<Rook*>(test.get())){
                    figure_color_name[index2][index1] += figure_name_rook;
                }



            }
            index1++;
        }
        index1 = 0;
        index2++;
    }

    std::cout<<"\n " << std::setw(20) << std::left << "Player White: " + std::to_string(this->get_white_player()->get_score())  << "Player Black: "<<this->get_black_player()->get_score()<<'\n';
    std::cout <<field<< left_upper_corner;
    for(int i = 0; i < 7; i++){
        std::cout << line_horizontal << line_horizontal << line_horizontal << line_horizontal << joint_upper;
    }
    std::cout << line_horizontal << line_horizontal << line_horizontal << line_horizontal << right_upper_corner << '\n';
    for(int j = 7; j > 0; j--) {
        std::cout<<j+1;
        for(int i = 0; i < 8; i++) {

            std::cout << line_vertical << field << figure_color_name[j][i] << field;
        }
        std::cout << line_vertical <<'\n';
        std::cout <<field<<joint_left;
        for (int i = 0; i < 7; i++) {
            std::cout << line_horizontal << line_horizontal << line_horizontal << line_horizontal << joint_middle;
        }
        std::cout << line_horizontal << line_horizontal << line_horizontal << line_horizontal << joint_right << '\n';
    }
    std::cout<<'1';
    for(int i = 0; i < 8; i++) {
        std::cout << line_vertical << field << figure_color_name[0][i] << field;
    }
    std::cout << line_vertical <<'\n';
    std::cout <<field<< left_lower_corner;
    for(int i = 0;i < 7;i++) {
        std::cout << line_horizontal << line_horizontal << line_horizontal << line_horizontal << joint_lower;
    }
    std::cout << line_horizontal << line_horizontal << line_horizontal << line_horizontal << right_lower_corner <<'\n';

    for(int i = 65; i < 73; i++){
        std::cout<<field<<field<<field<<char(i)<<field;
    }
    std::cout<<'\n'<<figure_color_white<<" - white "<<figure_color_black<<" - black"<<'\n'<<"P - Pawn B - Bishop H - Knight R - Rook Q - Queen K - King ";
}

bool Game::main_game_loop() {
    bool current_player = false;
    while(true) {
        if (players[current_player] == this->get_white_player()) {
            std::cout << "White turn: \n";
        } else {
            std::cout << "Black turn: \n";
        }
        this->players[!current_player]->calculate_score();
        this->draw();
        this->players[current_player]->generate_all_moves();
        if (this->players[current_player]->get_amount_of_moves() == 0) {
            if (this->players[current_player]->is_check()) {
                // checkmate
                std::cout << "\ngame over, checkmate\n";
                return true;
            } else {
                // stalemate
                std::cout << "\ngame over, stalemate\n";
                return false;
            }
        }
        if (dynamic_cast<Human *>(this->players[current_player].get())) {
            std::string choice = "a";
            while (choice != "S" && (choice != "M" | choice!= "m")) {
                std::cout << "Choose: \n"
                             "1. 'S' - to save game\n"
                             "2. 'M' - to move\n";
                std::cin >> choice;
                while (!std::cin.good()) {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Choose: \n"
                                 "1. 'S' - to save game\n"
                                 "2. 'M' - to move\n";
                    std::cin >> choice;
                }
            }
            if (choice == "S") {
                // TODO : ADD SAVING HERE
            } else if (choice == "M" || choice == "m") {
                this->players[current_player]->move();
            }
        } else {
            this->players[current_player]->move();
        }
        this->players[current_player]->reset_all_moves();
        this->players[current_player]->get_enemy_pieces();
        current_player = !current_player;
    }
}

