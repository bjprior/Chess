#ifndef BISHOP_H
#define BISHOP_H
#include"base.hpp"
#include"Chessboard.hpp"

class Bishop : public Piece{
public:
  //Contructor
  Bishop(char* pos,int col, ChessBoard* board);

  // Member functions //

  int move(const char* start, const char* end) override;

  void print_type() override;

  ~Bishop() override;
};

#endif
