#ifndef QUEEN_H
#define QUEEN_H
#include"base.hpp"
#include"Chessboard.hpp"

class Queen : public Piece{
public:
  //Contructor
  Queen(char* pos,int col, ChessBoard* board);

  // Member functions //

  // Check if move past is valid returns an error code if not and TAKE_PIECE or REGULAR_MOVE if fine //
  int move(const char* start, const char* end) override;

  // Print type //
  void print_type() override;

  ~Queen() override;
};

#endif
