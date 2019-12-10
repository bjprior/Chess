#include"queen.hpp"
#include"base.hpp"
#include"Chessboard.hpp"
#include<iostream>
#include"helper.hpp"

using namespace std;

Queen::Queen(char* pos, int col,ChessBoard* board):Piece(pos,col,board){
  type = 'Q';
}

Queen::~Queen(){}

int Queen::move(const char* start, const char* end){

  int srow, scolumn, erow, ecolumn, trow, tcolumn, drow, dcolumn, arow, acolumn, adjust;
  int colour;

  srow = rank_check(start[1]);
  scolumn = file_check(start[0]);
  erow = rank_check(end[1]);
  ecolumn = file_check(end[0]);

  colour = this->colour;
  drow = erow-srow;
  dcolumn = ecolumn - scolumn;

  // Check for valid move //
  if(!((abs(drow) == abs(dcolumn)) or (drow == 0 and dcolumn !=0) or (drow != 0 and dcolumn ==0))){
    return INVALID_MOVE;
  }

  // Diagonal Check //
  if(abs(drow) == abs(dcolumn)){
    // Initialise adjusts  //
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
  }    

  // Rank and File Check //
  if((drow == 0 and dcolumn !=0) or (drow != 0 and dcolumn ==0)){
    if(drow != 0)
      adjust = drow;
    if(dcolumn !=0)
      adjust = dcolumn;

    trow = srow;
    tcolumn = scolumn;

    // Check path of piece for other pieces  //
    for(int i =1; i< abs(adjust); i++){
      if(drow != 0)
	trow = srow + (i*(abs(adjust)/adjust));
      if(dcolumn != 0)
	tcolumn = scolumn +(i*(abs(adjust)/adjust));
      if(board->boardp[trow][tcolumn] != nullptr){
	return PIECE_BLOCKING;
      }
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

  return UNDEFINED_ERROR;
}

void Queen::print_type(){
  cout <<"Queen";
}
