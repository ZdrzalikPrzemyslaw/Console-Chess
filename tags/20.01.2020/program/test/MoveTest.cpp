//
// Created by Przemek on 19.01.2020.
//
#include <boost/test/unit_test.hpp>
#include "Player/Move.h"
#include "Player/Previous_Move.h"
#include "Pieces/Piece.h"
#include "Pieces/Pawn.h"
#include "Field.h"

BOOST_AUTO_TEST_SUITE(MoveTestSuite)

BOOST_AUTO_TEST_CASE(MoveTest1) {
    Position pos1(1,1);
    Position pos2(3,3);
    std::shared_ptr<Move> test_move1 = std::make_shared<Move>(pos1, pos2);
    BOOST_CHECK(test_move1->get_beg_pos() == pos1);
    BOOST_CHECK(test_move1->get_end_pos() == pos2);
}

BOOST_AUTO_TEST_CASE(Previous_MoveTest1) {
        Position pos1(1,1);
        Position pos2(3,3);
        std::shared_ptr<Field> test_field_1 = std::make_shared<Field>(pos1);
        std::shared_ptr<Field> test_field_2 = std::make_shared<Field>(pos2);
        std::shared_ptr<Piece> test_pawn1 = std::make_shared<Pawn>(true);
        std::shared_ptr<Piece> test_pawn2 = std::make_shared<Pawn>(false);
        test_pawn1->set_field(test_field_1);
        test_pawn2->set_field(test_field_2);
        std::shared_ptr<Previous_Move> test_p_move1 = std::make_shared<Previous_Move>(pos1, pos2, test_pawn1, test_pawn2);
        BOOST_CHECK(test_p_move1->get_beg_pos() == pos1);
        BOOST_CHECK(test_p_move1->get_end_pos() == pos2);
        BOOST_CHECK(test_pawn1 == test_p_move1->get_piece_in_beg_position());
        BOOST_CHECK(test_pawn2 == test_p_move1->get_piece_in_end_position());
    }




BOOST_AUTO_TEST_SUITE_END()