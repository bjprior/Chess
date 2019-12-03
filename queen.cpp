#include"queen.hpp"
#include"base.hpp"
#include"Chessboard.hpp"
#include<iostream>

using namespace std;

Queen::Queen(char* pos, int col,ChessBoard* board):Piece(pos,col,board){
  type = 'Q';
}

Queen::~Queen(){}

int Queen::move(const char* start, const char* end){
  return 0;
}

void Queen::print_type(){
  cout <<"Queen";
}
