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
    const std::shared_ptr<Board> &get_board() const;

    const std::vector<std::shared_ptr<Piece>> &get_white_pieces() const;

    const std::vector<std::shared_ptr<Piece>> &get_black_pieces() const;


    const std::shared_ptr<Player> &get_white_player() const;

    const std::shared_ptr<Player> &get_black_player() const;
    Game();
    Game(bool is_ai_player1, bool is_ai_player2);

private:
    std::vector<std::shared_ptr<Piece>> white_pieces;
    std::vector<std::shared_ptr<Piece>> black_pieces;
    std::vector<std::shared_ptr<Player>> players;
public:
    void initialize(bool is_ai_player1 = false, bool is_ai_player2 = false);
    void save_game();
    void load_game();
    void draw();
    void main_game_loop();

};


#endif //POBI_PROJ_SZACHY_GAME_H
