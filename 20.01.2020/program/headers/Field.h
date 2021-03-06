//
// Created by Przemek on 29.12.2019.
//

#ifndef POBI_PROJ_SZACHY_FIELD_H
#define POBI_PROJ_SZACHY_FIELD_H

#include "Position.h"
#include "memory"

struct Position;
class Piece;

class Field {
private:
    Position position;
    std::shared_ptr<Piece> piece = nullptr;
public:
    Position get_position();
    Field(int row, int col);
    Field(Position position); // #TODO add to uml
    std::shared_ptr<Piece> get_piece();
    void set_piece(std::shared_ptr<Piece> piece);
    bool is_taken();
};


#endif //POBI_PROJ_SZACHY_FIELD_H
