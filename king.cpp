#include"king.hpp"
#include"base.hpp"
#include"Chessboard.hpp"
#include<iostream>
#include"helper.hpp"

using namespace std;

King::King(char* pos, int col, ChessBoard* board):Piece(pos,col,board){
  type = 'K';
}

King::~King(){}

int King::move(const char* start, const char* end){

  int srow, scolumn, erow, ecolumn, drow,dcolumn;
  int colour;

  srow = rank_check(start[1]);
  scolumn = file_check(start[0]);
  erow = rank_check(end[1]);
  ecolumn = file_check(end[0]);

  colour = this->colour;

  drow = erow-srow;
  dcolumn = ecolumn - scolumn;

  // Check for valid move //
  if(!(abs(drow) <2 and abs(dcolumn) <2)){
    return INVALID_MOVE;
  }

  // Check square doesnt occupy piece of same colour //
  if(board->boardp[erow][ecolumn] != nullptr and
     board->boardp[erow][ecolumn]->colour == colour){
      return CANNOT_CAPTURE_OWN_PIECE;
  }

  if(board->boardp[erow][ecolumn] == nullptr){
    return REGULAR_MOVE;
  }
  
  if(board->boardp[erow][ecolumn] != nullptr){
    return TAKE_PIECE;
  }
 
  return UNDEFINED_ERROR;
}

void King::print_type(){
  cout <<"King";
}


