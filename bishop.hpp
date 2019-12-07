#ifndef BISHOP_H
#define BISHOP_H
#include"base.hpp"
#include"Chessboard.hpp"

class Bishop : public Piece{
public:
  //Contructor
  Bishop(char* pos,int col, ChessBoard* board);

  // Member functions //

  // Check if move past is valid returns an error code if not and TAKE_PIECE or REGULAR_MOVE if fine //
  int move(const char* start, const char* end) override;

  // Prints type //
  void print_type() override;

  ~Bishop() override;
};

#endif
