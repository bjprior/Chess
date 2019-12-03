#ifndef ROOK_H
#define ROOK_H
#include"base.hpp"
#include"Chessboard.hpp"

class Rook : public Piece{
public:
  //Contructor
  Rook(char* pos,int col, ChessBoard* board);

  // Member functions //

  int move(const char* start, const char* end) override;

  void print_type() override;

  ~Rook() override;
};

#endif
