//
// Created by premi on 09.01.2020.
//

#ifndef POBI_PROJ_SZACHY_GAME_H
#define POBI_PROJ_SZACHY_GAME_H

#include <memory>
#include <vector>
#include <boost/date_time/local_time/local_date_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Board;
class Piece;
class Player;

class Game {
private:
    std::shared_ptr<Board> board;
public:
    std::shared_ptr<Board> &get_board();

    const std::shared_ptr<Player> &get_white_player() const;

    const std::shared_ptr<Player> &get_black_player() const;

    Game();

    Game(bool is_ai_player1, bool is_ai_player2, bool load);

private:
    bool is_white_turn;
    std::vector<std::shared_ptr<Piece>> white_pieces;
    std::vector<std::shared_ptr<Piece>> black_pieces;
    std::vector<std::shared_ptr<Player>> players;
    boost::posix_time::ptime game_begin_time = boost::posix_time::ptime(boost::posix_time::second_clock::local_time());
public:
    void initialize(bool is_ai_player1 = false, bool is_ai_player2 = false);

    ~Game();

    void save_game();

    void load_game();

    void draw();

    bool main_game_loop();

    boost::posix_time::time_duration time_passed(); // TODO : add to uml
};


#endif //POBI_PROJ_SZACHY_GAME_H
