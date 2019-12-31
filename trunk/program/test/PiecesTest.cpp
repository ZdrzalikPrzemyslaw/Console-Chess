//
// Created by Przemek on 31.12.2019.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
#include "Pieces/Piece.h"
#include "Pieces/Pawn.h"
#include "Board.h"


BOOST_AUTO_TEST_SUITE(PieceTestSuite)

    BOOST_AUTO_TEST_CASE(white_pawn_test1) {
        Position test_pos1(1,1);
        Position test_pos2(2,1);
        Position test_pos3(3,1);
        Position test_pos4(2,2);
        Position test_pos5(2,0);
        std::shared_ptr<Pawn> test_pawn1 = std::make_shared<Pawn>(true);
        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        test_pawn1->set_field(test_board1->get_field(test_pos1));
        test_board1->get_field(test_pos1)->set_piece(test_pawn1);
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos2)));
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos3)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos4)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos5)));
        std::shared_ptr<Piece> test_pawn2 = std::make_shared<Pawn>(false);
        std::shared_ptr<Piece> test_pawn3 = std::make_shared<Pawn>(true);
        test_pawn2->set_field(test_board1->get_field(test_pos4));
        test_pawn3->set_field(test_board1->get_field(test_pos5));
        test_board1->get_field(test_pos4)->set_piece(test_pawn2);
        test_board1->get_field(test_pos5)->set_piece(test_pawn3);
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos4)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos5)));
        test_pawn1->set_has_moved(true);
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos3)));

    }

    BOOST_AUTO_TEST_CASE(black_pawn_test1) {
        Position test_pos1(7,1);
        Position test_pos2(6,1);
        Position test_pos3(5,1);
        Position test_pos4(6,2);
        Position test_pos5(6,0);
        std::shared_ptr<Pawn> test_pawn1 = std::make_shared<Pawn>(false);
        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        test_pawn1->set_field(test_board1->get_field(test_pos1));
        test_board1->get_field(test_pos1)->set_piece(test_pawn1);
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos2)));
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos3)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos4)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos5)));
        std::shared_ptr<Piece> test_pawn2 = std::make_shared<Pawn>(true);
        std::shared_ptr<Piece> test_pawn3 = std::make_shared<Pawn>(false);
        test_pawn2->set_field(test_board1->get_field(test_pos4));
        test_pawn3->set_field(test_board1->get_field(test_pos5));
        test_board1->get_field(test_pos4)->set_piece(test_pawn2);
        test_board1->get_field(test_pos5)->set_piece(test_pawn3);
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos4)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos5)));
        test_pawn1->set_has_moved(true);
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos3)));

    }

BOOST_AUTO_TEST_SUITE_END()