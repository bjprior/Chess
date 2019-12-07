#ifndef KNIGHT_H
#define KNIGHT_H
#include"base.hpp"
#include"Chessboard.hpp"

class Knight : public Piece{
public:
  //Contructor
  Knight(char* pos,int col, ChessBoard* board);

  // Member functions //

  // Check if move past is valid returns an error code if not and TAKE_PIECE or REGULAR_MOVE if fine //
  int move(const char* start, const char* end) override;

  // prints type //
  void print_type() override;
};

#endif
