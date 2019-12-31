//
// Created by Przemek on 31.12.2019.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
#include "Pieces/Piece.h"
#include "Pieces/Pawn.h"
#include "Board.h"
// #include "test.h"


BOOST_AUTO_TEST_SUITE(PieceTestSuite)

    BOOST_AUTO_TEST_CASE(PawnTest1) {
        Position test_pos1(1,1);
        Position test_pos2(2,1);
        std::shared_ptr<Piece> test_pawn1 = std::make_shared<Pawn>(true);
        std::shared_ptr<Board> test_board1 = std::make_shared<Board>();
        test_pawn1->set_field(test_board1->get_field(test_pos1));
        BOOST_CHECK_EQUAL(true,test_pawn1->can_move(test_board1->get_field(test_pos2)));
       // test_pawn1->queening();
    }

BOOST_AUTO_TEST_SUITE_END()