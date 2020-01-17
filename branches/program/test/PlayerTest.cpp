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

BOOST_AUTO_TEST_SUITE(PlayerTestSuite)

BOOST_AUTO_TEST_CASE(PlayerTest1) {
    Game game;
    game.get_white_player()->set_current_board_state(game.get_board());
    BOOST_CHECK_EQUAL(game.get_board(), game.get_white_player()->get_current_board_state());
    game.get_white_player()->get_current_board_state()->get_field(Position(1,1))->set_piece(nullptr);
    BOOST_CHECK_EQUAL(game.get_board(), game.get_white_player()->get_current_board_state());
}

BOOST_AUTO_TEST_SUITE_END()