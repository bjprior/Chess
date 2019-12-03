#ifndef PAWN_H
#define PAWN_H
#include"base.hpp"

class Pawn : public Piece{
public:
  // Constructor
  Pawn(char* pos, int col,ChessBoard* board);

  //   Member functions   //

  int move(const char* start, const char* end) override;
  void print_type() override;

  //    Destructor   // 
  ~Pawn() override;
};
#endif  
