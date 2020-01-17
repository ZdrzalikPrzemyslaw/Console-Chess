//
// Created by premi on 09.01.2020.
//

#ifndef POBI_PROJ_SZACHY_GAME_H
#define POBI_PROJ_SZACHY_GAME_H

#include <memory>
#include <vector>

class Board;
class Piece;
class Player;

class Game {
private:
    bool is_white_turn;
    std::shared_ptr<Board> board;
public:
    std::shared_ptr<Board> get_board() const;

    const std::vector<std::shared_ptr<Piece>> &get_white_pieces() const;

    const std::vector<std::shared_ptr<Piece>> &get_black_pieces() const;

    //const std::vector<std::shared_ptr<Player>> &get_players() const;

    Game();

private:
    std::vector<std::shared_ptr<Piece>> white_pieces;
    std::vector<std::shared_ptr<Piece>> black_pieces;
   // std::vector<std::shared_ptr<Player>> players;
public:
    void save_game();
    void load_game();
    void initialize();
    void main_game_loop();

};


#endif //POBI_PROJ_SZACHY_GAME_H
