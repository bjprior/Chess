
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include"base.hpp"
#include"errors.hpp"

const int ROWS (8), FILES(8),WHITE(1), BLACK(2), IN_CHECK (1), NOT_IN_CHECK(0), CHECK_MATE (2), NOT_IN_CHECK_MATE(0), STALE_MATE (4), NOT_IN_STALE_MATE(0);

class ChessBoard{
public:
  
  ChessBoard();
  
  char board[ROWS][FILES];
  Piece* boardp[ROWS][FILES];
  int turn; // 1 for white, 2 for black
  char white_king[2];
  int in_check;
  char black_king[2];
  
  // Member functions // 

  // Resets the chessboard to starting position //
  void resetBoard();

  // Submits and executes a move returns error code if invalid move //
  int submitMove(const char* start, const char* end);

  // Switches the turn on completion of a move //
  void change_turn();

  // Checks if move will leave own king in check returns IN_CHECK if does and NOT_IN_CHECK if not //
  int leaves_king_in_check(const char* start, const char* end,int colour);
  
  // Checks if the opposing King is in check following the move returns
  // IN_CHECK if does and NOT_IN_CHECK if not
  int is_in_check(const char* piece_pos, int colour);

  // Print error in move type //
  void print_error(int error);

  // Move the position of the colour of king passed to the fucntion//

  void move_king(int colour, const char* pos);

  // Checks if in check, is there a move to get out of check, returns CHECK_MATE or NOT_IN_CHECK_MATE//
  
  int is_in_check_mate(int colour);

  // Check if the game is in stale mate, returns STALE_MATE or NOT_IN_STALE_MATE //

  int is_in_stale_mate(int colour);
  
  //    Destructor     //

  ~ChessBoard();
};

#endif
