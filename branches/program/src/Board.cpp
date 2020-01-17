//
// Created by Przemek on 29.12.2019.
//

#include <iostream>
#include "Board.h"
#include "Field.h"


Board::Board() {
    for(int i = 0; i < 8; i++){
        fields.push_back(std::vector<std::shared_ptr<Field>>());
        for(int j = 0; j < 8; j++){
            auto tmp = std::make_shared<Field>(i,j);
            this->fields[i].push_back(tmp);
        }
    }
}

std::vector<std::vector<std::shared_ptr<Field>>> Board::get_board() {
    return this->fields;
}

std::shared_ptr<Field> Board::get_field(Position position) {
    if(position.row  < 0 || (position.col < 0)){
        throw std::out_of_range ("VECTOR HAS TO BE A NATURAL NUMBER");  // TODO: add error for out of range non negative+
    }
    return this->fields[position.row][position.col];
}

int Board::board_size() {
    int tmp = 0;
    for(auto &i: this->fields){
        tmp += i.size();
    }
    return tmp;
}

bool Board::is_clear_path(Position pos_beg,  Position pos_end) {
    if(pos_beg == pos_end) return false;
    if(pos_beg.col - pos_end.col == 0){
        for(int i = std::min(pos_beg.row, pos_end.row) + 1; i < (std::max(pos_beg.row, pos_end.row)); i++){
            if(this->get_field(Position(i, pos_beg.col))->get_piece() != nullptr){
                return false;
            }
        }
    }
    if(pos_beg.row - pos_end.row == 0){
        for(int i = std::min(pos_beg.col, pos_end.col) + 1; i < (std::max(pos_beg.col, pos_end.col)); i++){
            if(this->get_field(Position(pos_beg.row, i))->get_piece() != nullptr){
                return false;
            }
        }

    }
    if((abs(pos_beg.col - pos_end.col) - abs(pos_beg.row - pos_end.row)) == 0){
        for(int i = std::min(pos_beg.row, pos_end.row) + 1; i < (std::max(pos_beg.row, pos_end.row)); i++){
            if(this->get_field(Position(i, i))->get_piece() != nullptr){
                return false;
            }
        }
    }
    return true;
}