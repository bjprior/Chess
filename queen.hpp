#ifndef QUEEN_H
#define QUEEN_H
#include"base.hpp"
#include"Chessboard.hpp"

class Queen : public Piece{
public:
  //Contructor
  Queen(char* pos,int col, ChessBoard* board);

  // Member functions //

  int move(const char* start, const char* end) override;

  void print_type() override;

  ~Queen() override;
};

#endif
