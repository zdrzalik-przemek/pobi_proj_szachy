//
// Created by premi on 13.01.2020.
//

#ifndef POBI_PROJ_SZACHY_PLAYER_H
#define POBI_PROJ_SZACHY_PLAYER_H

#include <vector>
#include <memory>
#include "Position.h"

class Move;
class Piece;
class Board;
class Previous_Move;

class Player {
    bool is_white;
    int score = 0;
    std::vector<std::vector<std::shared_ptr<Move>>> all_moves;
    std::vector<std::shared_ptr<Piece>> &pieces;
    std::vector<std::shared_ptr<Piece>> &enemy_pieces;
    std::vector<std::shared_ptr<Piece>> captured_pieces;
    std::shared_ptr<Board> current_board_state;
    std::shared_ptr<Previous_Move> previous_move;
public:
    void set_pieces(std::vector<std::shared_ptr<Piece>> & pieces);
    void calculate_score();
    int get_score();
    void set_current_board_state(std::shared_ptr<Board> current_board_state);
    std::shared_ptr<Board> get_current_board_state(); // #TODO: usun - do testow
    std::vector<std::shared_ptr<Piece>> get_pieces(); // #TODO: usun - do testow
    std::vector<std::shared_ptr<Piece>> get_enemy_pieces(); // #TODO: usun - do testow

    Player(bool is_white, std::vector<std::shared_ptr<Piece>> &pieces,
           std::vector<std::shared_ptr<Piece>> &enemy_pieces);
    virtual bool move() = 0;
    void set_enemy_pieces(std::vector<std::shared_ptr<Piece>>& enemy_pieces);
    void set_enemy_pieces(std::shared_ptr<std::vector<std::shared_ptr<Piece>>> pieces);
    bool is_check();
    void generate_all_moves();
    std::vector<std::vector<std::shared_ptr<Move>>> get_all_moves();
    bool test_move(std::shared_ptr<Move> move);
    void capture(std::shared_ptr<Piece> piece);
    void reset_all_moves(); // TODO add to uml
    int get_amount_of_moves(); // TODO add to uml
    void queening(Position position);

protected:
    void do_move(std::shared_ptr<Move> move);



};


#endif //POBI_PROJ_SZACHY_PLAYER_H
