//
// Created by Przemek on 29.12.2019.
//

#ifndef POBI_PROJ_SZACHY_POSITION_H
#define POBI_PROJ_SZACHY_POSITION_H

struct Position{
public:
    int row;
    int col;
    bool operator == (Position &rhs);
    Position();
    Position(int row, int col);
};


#endif //POBI_PROJ_SZACHY_POSITION_H
