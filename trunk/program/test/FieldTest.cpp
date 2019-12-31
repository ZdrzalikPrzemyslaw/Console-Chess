//
// Created by Przemek on 29.12.2019.
//
#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
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

}




BOOST_AUTO_TEST_SUITE_END()