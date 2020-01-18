//
// Created by Przemek on 17.01.2020.
//

#include <boost/test/unit_test.hpp>
#include "Player/Player.h"
#include "Game.h"
#include "memory"
#include "Board.h"
#include "Position.h"
#include "Field.h"
#include "Pieces/Piece.h"
#include "Pieces/Queen.h"
#include "Player/Move.h"

BOOST_AUTO_TEST_SUITE(PlayerTestSuite)

BOOST_AUTO_TEST_CASE(PlayerTest1) {
    Game game;
    game.get_white_player()->set_current_board_state(game.get_board());
    BOOST_CHECK_EQUAL(game.get_board(), game.get_white_player()->get_current_board_state());
    game.get_white_player()->get_current_board_state()->get_field(Position(1,1))->set_piece(nullptr);
    BOOST_CHECK_EQUAL(game.get_board(), game.get_white_player()->get_current_board_state());
}

    BOOST_AUTO_TEST_CASE(PlayerTest2) {
        Game game;
        BOOST_CHECK(game.get_black_player()->get_pieces() ==  game.get_white_player()->get_enemy_pieces());
        BOOST_CHECK(game.get_black_player()->get_enemy_pieces() ==  game.get_white_player()->get_pieces());
        game.get_white_player()->set_current_board_state(game.get_board());
        BOOST_CHECK(!game.get_white_player()->is_check());
        game.get_board()->get_field(Position(1,3))->get_piece()->set_field(nullptr);
        game.get_board()->get_field(Position(1,3))->set_piece(nullptr);
        game.get_board()->get_field(Position(7,4))->get_piece()->set_field(game.get_board()->get_field(Position(4,3)));
        game.get_board()->get_field(Position(4,3))->set_piece(game.get_board()->get_field(Position(7,4))->get_piece());
        game.get_board()->get_field(Position(7,4))->set_piece(nullptr);
        BOOST_CHECK(game.get_white_player()->is_check());
}

    BOOST_AUTO_TEST_CASE(PlayerTest3){
        Game game;
        game.get_white_player()->set_current_board_state(game.get_board());
        game.get_white_player()->generate_all_moves();
        int tmp = 0;
        for(auto &i : game.get_white_player()->get_all_moves()){
            tmp += i.size();
        }
        BOOST_CHECK_EQUAL(20, tmp);
        game.get_black_player()->set_current_board_state(game.get_board());
        game.get_black_player()->generate_all_moves();
        tmp = 0;
        for(auto &i : game.get_black_player()->get_all_moves()){
            tmp += i.size();
        }
        BOOST_CHECK_EQUAL(20, tmp);

}

    BOOST_AUTO_TEST_CASE(PlayerTest4) {
    Game game;
    game.get_black_player()->capture(nullptr);
    game.get_black_player()->capture(game.get_board()->get_field(Position(0,0))->get_piece());
    game.get_black_player()->capture(game.get_board()->get_field(Position(0,0))->get_piece());
    game.get_black_player()->capture(game.get_board()->get_field(Position(7,7))->get_piece());
}


BOOST_AUTO_TEST_SUITE_END()