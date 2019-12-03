#include"pawn.hpp"
#include"base.hpp"
#include"helper.hpp"
#include<iostream>
#include"Chessboard.hpp"
#include<cstdlib>

using namespace std;

Pawn::Pawn(char* pos, int col,ChessBoard* board):Piece(pos,col,board){
  type = 'p';
}

Pawn::~Pawn(){}

int Pawn::move(const char* start, const char* end){

 
  int srow, scolumn, erow, ecolumn, fwd_move, side_move;
  int colour;
  
  srow = rank_check(start[1]);
  scolumn = file_check(start[0]);
  erow = rank_check(end[1]);
  ecolumn = file_check(end[0]);

  fwd_move = erow - srow;
  side_move = ecolumn-scolumn;
  
  colour = this->colour;

  // Check for fwd move //
  if(colour == WHITE and fwd_move >0){
    cout << " Pawn cannot move backwards!" << endl;
    return ERROR;
  }
  if(colour == BLACK and fwd_move < 0){
    cout << " Pawn cannot move backwards!" << endl;
    return ERROR;
  }

  // Make fwd move //
  if(number_of_moves == 0 and abs(fwd_move) <3 and side_move == 0 and
     board->boardp[erow][ecolumn] == nullptr){
    cout << " Pawn moves from " << start << " to " << end << endl;
    return REGULAR_MOVE;
  }

  if(number_of_moves > 0 and abs(fwd_move) <2 and side_move == 0 and
     board->boardp[erow][ecolumn] == nullptr){
    cout << " Pawn moves from " << start << " to " << end << endl;
    return REGULAR_MOVE;
  }

  if(abs(fwd_move)==1 and abs(side_move) ==1 and
     (board->boardp[erow][ecolumn]->colour != colour)){
    cout <<  " Pawn moves from " << start << " to " << end
	 << " taking ";
    print_colour(board->boardp[erow][ecolumn]->colour);
    cout <<" ";
    board->boardp[erow][ecolumn]->print_type();
    cout << endl;
    return TAKE_PIECE;
  }

  cout << " Error(def) in move:" << start<< " to " << end << endl;
  return ERROR;
}

void Pawn::print_type(){
  cout <<"Pawn";
}

  
