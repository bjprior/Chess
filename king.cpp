#include"king.hpp"
#include"base.hpp"
#include"Chessboard.hpp"
#include<iostream>

using namespace std;

King::King(char* pos, int col, ChessBoard* board):Piece(pos,col,board){
  type = 'K';
}

King::~King(){}

int King::move(const char* start, const char* end){
  return 0;
}

void King::print_type(){
  cout <<"King";
}


