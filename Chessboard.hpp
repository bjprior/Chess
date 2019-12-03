#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include"base.hpp"

const int ROWS (8), FILES(8),WHITE(1), BLACK(2),REGULAR_MOVE(0),TAKE_PIECE(3), ERROR (-1);

class ChessBoard{
public:
  
  ChessBoard();
  
  char board[ROWS][FILES];
  Piece* boardp[ROWS][FILES];
  int turn; // 1 for white, 2 for black
  
  // Member functions // 

  // Resets the chessboard to starting position //
  void resetBoard();

  // Submits and executes a move //
  int submitMove(const char* start, const char* end);
  
  void change_turn();
};

#endif
