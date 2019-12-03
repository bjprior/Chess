#include"rook.hpp"
#include"base.hpp"
#include"Chessboard.hpp"
#include<iostream>
#include"helper.hpp"

using namespace std;

Rook::Rook(char* pos, int col,ChessBoard* board):Piece(pos,col,board){
  type = 'r';
}

Rook::~Rook(){}

int Rook::move(const char* start, const char* end){  

  int srow, scolumn, erow, ecolumn, drow,dcolumn ,adjust, trow, tcolumn;
  int colour;

  srow = rank_check(start[1]);
  scolumn = file_check(start[0]);
  erow = rank_check(end[1]);
  ecolumn = file_check(end[0]);

  colour = this->colour;

  drow = erow-srow;
  dcolumn = ecolumn - scolumn;

  // Check for valid move // 
  if(drow != 0 and dcolumn !=0){
    cout << "Rook invalid move:" << start <<
      " to " << end << "!"<< endl;
    return ERROR;
  }

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
      cout <<" Rook cannot move from " <<start<<" to " << end << "!" << endl;
      return ERROR;
    }
  }

  // Check square doesnt occupy piece of same colour //
  if(board->boardp[trow][tcolumn] != nullptr and
     board->boardp[erow][ecolumn]->colour == colour){
    cout <<" Rook cannot move from " << start << " to " << end << "!" << endl;
      return ERROR;
  }
    

  cout << " Rook moves from " << start <<" to " << end;

  if(board->boardp[erow][ecolumn] == nullptr){
    cout << endl;
    return REGULAR_MOVE;
  }
  if(board->boardp[erow][ecolumn] != nullptr){
    cout<< " taking ";
    print_colour(board->boardp[erow][ecolumn]->colour);
    cout <<" ";
    board->boardp[erow][ecolumn]->print_type();
    cout << endl;
    return TAKE_PIECE;
  }
  return ERROR;

}

void Rook::print_type(){
  cout <<"Rook";
}
