#include"pawn.hpp"
#include"base.hpp"
#include"helper.hpp"
#include<iostream>
#include"Chessboard.hpp"
#include<cstdlib>
#include"errors.hpp"

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

  // Check for fwd moves //
  if(colour == WHITE and fwd_move >0){
    return PAWN_BACKWARDS;
  }
  if(colour == BLACK and fwd_move < 0){
    return PAWN_BACKWARDS;
  }
  
  // Check valid moves // 
  if(abs(fwd_move) > 1 and number_of_moves > 0 and side_move ==0){
    return INVALID_MOVE;
  }
  
  if(abs(fwd_move) > 2 and number_of_moves == 0 and side_move ==0){
    return INVALID_MOVE;
  }
  
  if(abs(fwd_move) > 1 and abs(side_move) > 1){
    return INVALID_MOVE;
  }
  
  if(abs(fwd_move) ==1 and abs(side_move) ==1 and board->boardp[erow][ecolumn]==nullptr ){
        return NONE_CAPTURING_DIAGONAL;
  }
  
  if((abs(fwd_move) == 1 or abs(fwd_move) ==2) and board->boardp[erow][ecolumn] != nullptr and
     board->boardp[erow][ecolumn]->colour != colour and side_move == 0){
    return INVALID_MOVE;
  }
  
  if(abs(fwd_move) > 2 or abs(side_move) >2){
        return INVALID_MOVE;
  }
  
  if(abs(fwd_move) >1 and number_of_moves >0){
    return INVALID_MOVE;
  }
  
  if(fwd_move == 0 and side_move != 0){
    return INVALID_MOVE;
  }
  if(abs(side_move) > 1){
    return INVALID_MOVE;
  }
  if(abs(fwd_move) >1 and side_move !=0){
    return INVALID_MOVE;
  }
  //Check for blocking piece in first forward move //
  if(abs(fwd_move) ==2){
    int temp_adj_row = fwd_move/2;
    if(board->boardp[srow+temp_adj_row][scolumn] != nullptr){
    return PIECE_BLOCKING;
    }
  }

  if(abs(fwd_move) > 0 and abs(side_move) > 0 and board->boardp[erow][ecolumn] == nullptr){
    return NONE_CAPTURING_DIAGONAL;
  }
  
  if(board->boardp[erow][ecolumn] != nullptr and board->boardp[erow][ecolumn]->colour == colour){
    return CANNOT_CAPTURE_OWN_PIECE;
  }
  // Make fwd move (first move) //
  if(number_of_moves == 0 and abs(fwd_move) <3 and side_move == 0 and
     board->boardp[erow][ecolumn] == nullptr){
    return REGULAR_MOVE;
  }

  // Make fwd move (subsequent moves) //
  if(number_of_moves > 0 and abs(fwd_move) <2 and side_move == 0 and
     board->boardp[erow][ecolumn] == nullptr){
    return REGULAR_MOVE;
  }

  
  // Make diagonal capturing move //
  if(abs(fwd_move)==1 and abs(side_move) ==1 and (board->boardp[erow][ecolumn]!= nullptr)
     and (board->boardp[erow][ecolumn]->colour != colour)){
    return TAKE_PIECE;
  }
  

  cout << " Pawn error(def) in move:" << start<< " to " << end << endl;
  return UNDEFINED_ERROR;
}

void Pawn::print_type(){
  cout <<"Pawn";
}

  
