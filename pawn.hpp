#ifndef PAWN_H
#define PAWN_H
#include"base.hpp"

class Pawn : public Piece{
public:
  // Constructor
  Pawn(char* pos, int col,ChessBoard* board);

  //   Member functions   //

  // Check if move past is valid returns an error code if not and TAKE_PIECE or REGULAR_MOVE if fine //
  int move(const char* start, const char* end) override;

  // Prints type //
  void print_type() override;

  //    Destructor   // 
  ~Pawn() override;
};
#endif  
