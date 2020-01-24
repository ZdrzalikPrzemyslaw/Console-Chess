//
// Created by Przemek on 29.12.2019.
//

#include "Position.h"

Position::Position(int row, int col) : row(row), col(col){}

bool Position::operator==(Position &rhs) {
    return this->row == rhs.row && (this->col == rhs.col);
}
