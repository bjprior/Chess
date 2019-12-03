#include"base.hpp"
#include"Chessboard.hpp"

Piece::Piece(char* pos, int colour, ChessBoard* board):colour(colour),board(board){
  position[0] = pos[0];
  position[1] = pos[1];
  number_of_moves = 0;
}
int Piece::move(const char* start, const char* end){
  return 0; 
}
