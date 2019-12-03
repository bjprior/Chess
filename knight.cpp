#include"knight.hpp"
#include"base.hpp"
#include"Chessboard.hpp"
#include<iostream>

using namespace std;

Knight::Knight(char* pos, int col, ChessBoard* board):Piece(pos,col,board){
  type = 'k';
}

int Knight::move(const char* start, const char* end){
  return 0;
}

void Knight::print_type(){
  cout <<"Knight";
}
