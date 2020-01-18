//
// Created by Przemek on 29.12.2019.
//

#ifndef POBI_PROJ_SZACHY_BOARD_H
#define POBI_PROJ_SZACHY_BOARD_H

#include <memory>
#include <vector>

class Field;
class Position;

class Board {
private:
    std::vector<std::vector<std::shared_ptr<Field>>> fields;
public:
    Board();
    std::shared_ptr<Field> get_field(Position position);
    bool is_clear_path(Position pos_beg, Position pos_end);
    std::vector<std::vector<std::shared_ptr<Field>>> get_board();
    int board_size(); // for testing only TODO : remove
};


#endif //POBI_PROJ_SZACHY_BOARD_H
