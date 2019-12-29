//
// Created by Przemek on 29.12.2019.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
#include "Board.h"
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

BOOST_AUTO_TEST_SUITE_END()