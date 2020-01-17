//
// Created by premi on 13.01.2020.
//

#ifndef POBI_PROJ_SZACHY_PLAYER_H
#define POBI_PROJ_SZACHY_PLAYER_H

#include <vector>
#include <memory>

class Move;
class Piece;
class Board;

class Player {
    bool is_white;
    int score = 0;
    std::vector<std::shared_ptr<Move>> all_moves;
    std::vector<std::shared_ptr<Piece>> pieces;
    std::vector<std::shared_ptr<Piece>> enemy_pieces;
    std::vector<std::shared_ptr<Piece>> captured_pieces;
    std::shared_ptr<Board> current_board_state;
public:
    void set_pieces(std::vector<std::shared_ptr<Piece>> pieces);
    void calculate_score();
    int get_score();
    void set_current_board_state(std::shared_ptr<Board> current_board_state);
    std::shared_ptr<Board> get_current_board_state(); // #TODO: usun - do testow
    std::vector<std::shared_ptr<Piece>> get_pieces(); // #TODO: usun - do testow
    std::vector<std::shared_ptr<Piece>> get_enemy_pieces(); // #TODO: usun - do testow

    Player(bool is_white);
    virtual bool move() = 0;
    void set_enemy_pieces(std::vector<std::shared_ptr<Piece>> enemy_pieces);
    bool is_check();

};


#endif //POBI_PROJ_SZACHY_PLAYER_H
