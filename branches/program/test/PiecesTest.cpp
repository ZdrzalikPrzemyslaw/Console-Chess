//
// Created by Przemek on 31.12.2019.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include <Pieces/Queen.h>
#include <Pieces/Rook.h>
#include "Field.h"
#include "Pieces/Piece.h"
#include "Pieces/Pawn.h"
#include "Pieces/King.h"
#include "Board.h"

Position test_pos1(1,1);
Position test_pos2(2,1);
Position test_pos3(3,1);
Position test_pos4(2,2);
Position test_pos5(2,0);
Position test_pos6(7,1);
Position test_pos7(6,1);
Position test_pos8(5,1);
Position test_pos9(6,2);
Position test_pos10(6,0);


BOOST_AUTO_TEST_SUITE(PieceTestSuite)

    BOOST_AUTO_TEST_CASE(white_pawn_test1) {

        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        std::shared_ptr<Pawn> test_pawn1 = std::make_shared<Pawn>(true);
        BOOST_CHECK_EQUAL(test_pawn1->get_value(), 1);
        std::shared_ptr<Piece> test_pawn2 = std::make_shared<Pawn>(false);
        std::shared_ptr<Piece> test_pawn3 = std::make_shared<Pawn>(true);
        test_pawn1->set_field(test_board1->get_field(test_pos1));
        test_board1->get_field(test_pos1)->set_piece(test_pawn1);
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos2)));
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos3)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos4)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos5)));
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

        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        std::shared_ptr<Pawn> test_pawn1 = std::make_shared<Pawn>(false);
        std::shared_ptr<Piece> test_pawn2 = std::make_shared<Pawn>(true);
        std::shared_ptr<Piece> test_pawn3 = std::make_shared<Pawn>(false);
        test_pawn1->set_field(test_board1->get_field(test_pos6));
        test_board1->get_field(test_pos6)->set_piece(test_pawn1);
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos7)));
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos8)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos9)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos10)));
        test_pawn2->set_field(test_board1->get_field(test_pos9));
        test_pawn3->set_field(test_board1->get_field(test_pos10));
        test_board1->get_field(test_pos9)->set_piece(test_pawn2);
        test_board1->get_field(test_pos10)->set_piece(test_pawn3);
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos9)));
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos10)));
        test_pawn1->set_has_moved(true);
        BOOST_CHECK_EQUAL(false,test_pawn1->can_move(test_board1->get_field(test_pos8)));
    }

    BOOST_AUTO_TEST_CASE(king_test){

        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        std::shared_ptr<Piece> test_king1 = std::make_shared<King>(true);
        test_king1->set_field(test_board1->get_field(test_pos7));  // TODO: add a method to automatise these 2 commands (set_field and set_piece)
        test_board1->get_field(test_pos7)->set_piece(test_king1);
        BOOST_CHECK_EQUAL(test_king1->get_field(), test_board1->get_field(test_pos7));
        BOOST_CHECK_EQUAL(test_king1, test_board1->get_field(test_pos7)->get_piece());
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(6,0))));
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(6,2))));
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(5,0))));
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(5,1))));
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(5,2))));
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(7,0))));
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(7,1))));
        BOOST_CHECK(test_king1->can_move(test_board1->get_field(Position(7,2))));
        BOOST_CHECK(!test_king1->can_move(test_board1->get_field(Position(7,4))));
        BOOST_CHECK(!test_king1->can_move(test_board1->get_field(Position(3,4))));
}

    BOOST_AUTO_TEST_CASE(queen_test){

        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        std::shared_ptr<Piece> test_queen1= std::make_shared<Queen>(true);
        test_queen1->set_field(test_board1->get_field(test_pos7));  // TODO: add a method to automatise these 2 commands (set_field and set_piece)
        test_board1->get_field(test_pos7)->set_piece(test_queen1);
        BOOST_CHECK_EQUAL(test_queen1->get_field(), test_board1->get_field(test_pos7));
        BOOST_CHECK_EQUAL(test_queen1, test_board1->get_field(test_pos7)->get_piece());
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(6,0))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(6,1))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(6,2))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(6,3))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(6,4))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(6,5))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(6,6))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(6,7))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(5,0))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(5,1))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(5,2))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(7,0))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(7,1))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(7,2))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(7,4))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(3,4))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(4,3))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(4,2))));
        BOOST_CHECK(test_queen1->can_move(test_board1->get_field(Position(4,1))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(4,0))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(4,4))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(4,5))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(4,6))));
        BOOST_CHECK(!test_queen1->can_move(test_board1->get_field(Position(4,7))));

}

    BOOST_AUTO_TEST_CASE(rook_test){
        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        std::shared_ptr<Piece> test_rook1 = std::make_shared<Rook>(true);
        test_rook1->set_field(test_board1->get_field(test_pos1));    // Position test_pos1(1,1);
        test_board1->get_field(test_pos1)->set_piece(test_rook1);
        BOOST_CHECK_EQUAL(test_rook1->get_field(), test_board1->get_field(test_pos1));
        BOOST_CHECK_EQUAL(test_rook1, test_board1->get_field(test_pos1)->get_piece());
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(1,0))));
        BOOST_CHECK(!test_rook1->can_move(test_board1->get_field(Position(1,1))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(1,2))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(1,3))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(1,4))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(1,5))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(1,6))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(1,7))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(0,1))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(2,1))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(3,1))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(4,1))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(5,1))));
        BOOST_CHECK(test_rook1->can_move(test_board1->get_field(Position(6,1))));
        BOOST_CHECK(!test_rook1->can_move(test_board1->get_field(Position(7,3))));
        BOOST_CHECK(!test_rook1->can_move(test_board1->get_field(Position(7,6))));
        BOOST_CHECK(!test_rook1->can_move(test_board1->get_field(Position(7,7))));
        BOOST_CHECK(!test_rook1->can_move(test_board1->get_field(Position(5,5))));
        BOOST_CHECK(!test_rook1->can_move(test_board1->get_field(Position(3,2))));
}

    // TODO: other pieces tests

BOOST_AUTO_TEST_SUITE_END()