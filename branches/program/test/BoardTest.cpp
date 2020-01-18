//
// Created by Przemek on 29.12.2019.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
#include "Board.h"
#include "Game.h"
// #include "test.h"


BOOST_AUTO_TEST_SUITE(BoardTestSuite)

    BOOST_AUTO_TEST_CASE(BoardTest1) {
    std::shared_ptr<Board> test_board_1 = std::make_shared<Board>();
    BOOST_CHECK_EQUAL(test_board_1->board_size(), 64);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Position test_position(i,j);
            BOOST_CHECK_EQUAL(test_position.row, test_board_1->get_field(test_position)->get_position().row);
            BOOST_CHECK_EQUAL(test_position.col, test_board_1->get_field(test_position)->get_position().col);
            }
        }
    }

    BOOST_AUTO_TEST_CASE(BoardTest2){
    std::shared_ptr<Game> test_Game_1 = std::make_shared<Game>();
    test_Game_1->initialize();
    //itself
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(1,7), Position(1,7)));
    //vertical
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,0), Position(2,0)));
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,0), Position(3,0)));
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,0), Position(4,0)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,1), Position(3,1)));
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,0), Position(4,0)));
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,0), Position(5,0)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,0), Position(5,0)));
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,0), Position(6,0)));
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,0), Position(7,0)));
    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(1,0), Position(7,0)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,0), Position(6,0)));
    //horizontal
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(2,1), Position(2,5)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(3,1), Position(3,5)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(3,1), Position(3,4)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(3,1), Position(3,3)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(3,1), Position(3,2)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(3,7), Position(3,0)));
    //diagonal
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,1), Position(5,5)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,0), Position(6,5)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(6,5), Position(1,0)));

    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(1,0), Position(7,6)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,7), Position(3,5)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,7), Position(4,4)));
    BOOST_CHECK(test_Game_1->get_board()->is_clear_path(Position(1,7), Position(2,6)));


    BOOST_CHECK(!test_Game_1->get_board()->is_clear_path(Position(0,5),Position(2,3)));

    test_Game_1->get_board()->get_field(Position(2,1))->set_piece(test_Game_1->get_board()->get_field(Position(1,1))->get_piece());
    test_Game_1->get_board()->get_field(Position(1,1))->set_piece(nullptr);
    BOOST_CHECK(!test_Game_1->get_board()->get_field(Position(1,1))->is_taken());
    BOOST_CHECK(test_Game_1->get_board()->get_field(Position(2,1))->is_taken());

}



BOOST_AUTO_TEST_SUITE_END()