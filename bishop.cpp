#include"bishop.hpp"
#include"base.hpp"
#include"Chessboard.hpp"
#include"helper.hpp"
#include<iostream>

using namespace std;

Bishop::Bishop(char* pos, int col, ChessBoard* board):Piece(pos,col,board){
  type = 'b';
}

Bishop::~Bishop(){}

int Bishop::move(const char* start, const char* end){
  int srow, scolumn, erow, ecolumn, trow, tcolumn, drow, dcolumn, arow, acolumn;
  int colour;
  
  srow = rank_check(start[1]);
  scolumn = file_check(start[0]);
  erow = rank_check(end[1]);
  ecolumn = file_check(end[0]);

  colour = this->colour;
  drow = erow-srow;
  dcolumn = ecolumn - scolumn;

  // Check for valid move // 
  if(abs(drow) != abs(dcolumn)){
    return BISHOP_NOT_DIAGONAL;
  }

  if(drow < 0)
    arow = -1;
  if(drow > 0)    
    arow = 1;
  if(dcolumn < 0)
    acolumn = -1;
  if(dcolumn >0)
    acolumn = 1;


  trow = srow;
  tcolumn = scolumn;

  // Check path of piece for other pieces  //
  for(int i = 1; i < abs(drow); i++){
    trow = srow+(i*arow);
    tcolumn = scolumn+(i* acolumn);
    if(board->boardp[trow][tcolumn] != nullptr){
      return PIECE_BLOCKING;
    }
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

  cout << " Error(def) in move:" << start<< " to " << end << endl;
  return UNDEFINED_ERROR;
  

}

void Bishop::print_type(){
  cout <<"Bishop";
}
