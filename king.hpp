#ifndef KING_H
#define KING_H
#include"base.hpp"
#include"Chessboard.hpp"

class King : public Piece{
public:
  //Contructor
  King(char* pos,int col,ChessBoard* board);

  // Member functions //

  int move(const char* start, const char* end) override;

  void print_type() override;

  ~King() override;
};

#endif
