#ifndef BASE_H
#define BASE_H

class ChessBoard;

class Piece{
public:
  // Constructor //
  Piece(char* pos, int colour, ChessBoard* board);

  char position[2];
  const int colour; // 1 for white, 2 for black 
  int number_of_moves;
  ChessBoard* board;
  char type;
  // Member functions //

  //virtual function to check if move is possible and make //
  virtual int move(const char* start, const char* end) = 0;
  virtual void print_type() = 0;
  virtual ~Piece(){}
};

#endif
