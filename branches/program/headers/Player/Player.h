//
// Created by premi on 13.01.2020.
//

#ifndef POBI_PROJ_SZACHY_PLAYER_H
#define POBI_PROJ_SZACHY_PLAYER_H

#include <vector>
#include <memory>

class Move;
class Piece;

class Player {
    bool is_white;
    int score;
    std::vector<std::shared_ptr<Move>> all_moves;
    std::vector<std::shared_ptr<Piece>> pieces;
    std::vector<std::shared_ptr<Piece>> captured_pieces;
    
};


#endif //POBI_PROJ_SZACHY_PLAYER_H