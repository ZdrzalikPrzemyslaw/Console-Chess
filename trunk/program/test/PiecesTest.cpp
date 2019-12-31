//
// Created by Przemek on 31.12.2019.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
#include "Pieces/Piece.h"
#include "Pieces/Pawn.h"
// #include "test.h"


BOOST_AUTO_TEST_SUITE(PieceTestSuite)

    BOOST_AUTO_TEST_CASE(PawnTest1) {
        std::shared_ptr<Piece> test_pawn1 = std::make_shared<Pawn>(true);
        test_pawn1->queening();
    }

BOOST_AUTO_TEST_SUITE_END()