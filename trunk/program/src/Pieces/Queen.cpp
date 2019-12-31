//
// Created by Przemek on 30.12.2019.
//

#include "Pieces/Queen.h"
#include "Field.h"

int Queen::get_value() {
    return queen_value;
}

bool Queen::can_move(std::shared_ptr<Field> field_final) {
    Position tmp = field_final->get_position();
    if (this->get_field()->get_position().operator==(tmp)) {
        return false;
    }
    return true;
}