//
// Created by Przemek on 29.12.2019.
//
#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
#include "Pieces/Pawn.h"
// #include "test.h"

const int row_1 = 1;
const int col_1 = 2;

BOOST_AUTO_TEST_SUITE(FieldTestSuite)

BOOST_AUTO_TEST_CASE(FieldTest1) {
    std::shared_ptr<Field> test_field_1 = std::make_shared<Field>(row_1, col_1);
    Position test_pos_1(row_1, col_1);
    BOOST_REQUIRE_EQUAL(test_pos_1.row, row_1);
    BOOST_REQUIRE_EQUAL(test_pos_1.col, col_1);
    BOOST_REQUIRE_EQUAL(test_pos_1.row, test_field_1->get_position().row);
    BOOST_REQUIRE_EQUAL(test_pos_1.col, test_field_1->get_position().col);

    Position tmp = test_field_1->get_position();
    BOOST_REQUIRE_EQUAL(test_pos_1.operator==(tmp), true);

    std::shared_ptr<Piece> test_pawn1 = std::make_shared<Pawn>(true);
    std::shared_ptr<Piece> test_pawn2 = std::make_shared<Pawn>(true);
    test_field_1->set_piece(test_pawn1);
    test_field_1->set_piece(test_pawn2);
    BOOST_CHECK_EQUAL(test_field_1->get_piece(), test_pawn2);
    test_field_1->set_piece(test_pawn1);
    BOOST_CHECK_EQUAL(test_field_1->get_piece(), test_pawn1);
    BOOST_CHECK(test_field_1->is_taken());

    std::shared_ptr<Pawn> test_pawn3 = std::make_shared<Pawn>(true);
    test_field_1->set_piece(test_pawn3);
    BOOST_CHECK(test_field_1->is_taken());
    BOOST_CHECK_EQUAL(test_field_1->get_piece(), test_pawn3);
}




BOOST_AUTO_TEST_SUITE_END()