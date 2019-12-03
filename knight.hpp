#ifndef KNIGHT_H
#define KNIGHT_H
#include"base.hpp"
#include"Chessboard.hpp"

class Knight : public Piece{
public:
  //Contructor
  Knight(char* pos,int col, ChessBoard* board);

  // Member functions //

  int move(const char* start, const char* end) override;

  void print_type() override;
};

#endif
