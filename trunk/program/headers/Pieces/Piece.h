//
// Created by Przemek on 29.12.2019.
//

#ifndef POBI_PROJ_SZACHY_PIECE_H
#define POBI_PROJ_SZACHY_PIECE_H
#include "memory"
class Field;

class Piece {
private:
    bool is_white;
    std::shared_ptr<Field> field;
public:
    virtual int get_value() = 0;
    bool get_is_white();
    virtual bool can_move(Field) = 0;
    explicit Piece(bool);
    bool is_on_a_field();
    void set_field(std::shared_ptr<Field>);
    std::shared_ptr<Field> get_field();
};


#endif //POBI_PROJ_SZACHY_PIECE_H
