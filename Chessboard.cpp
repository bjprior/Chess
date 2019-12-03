#include<iostream>
#include"Chessboard.hpp"
#include"base.hpp"
#include"pawn.hpp"
#include"rook.hpp"
#include"knight.hpp"
#include"bishop.hpp"
#include"king.hpp"
#include"queen.hpp"
#include"helper.hpp"

using namespace std;

ChessBoard::ChessBoard(){
  cout <<"A new chess game is started!" << endl;
  
  char pos[2];

  turn = WHITE;  //Set turn to white
  
  //set white pawns //
  for(int i = 0; i < FILES; i++){
    board[6][i] = 'p';
    pos[0] = 2;
    pos[1] = static_cast<char>(i+65);
    boardp[6][i] = new Pawn(pos,WHITE,this);
  }
  //set white others//
  for(int i=0; i < FILES; i++){
    pos[0] = 1;
    pos[1]= static_cast<char>(i+65);
    if(i == 0 || i ==7){
      boardp[7][i] = new Rook(pos,WHITE,this);
      board[7][i] = 'r';
    }
    if(i ==1 || i == 6){
      boardp[7][i] = new Knight(pos,WHITE,this);
      board[7][i] = 'k';
    }
    if(i ==2 || i == 5){
      boardp[7][i] = new Bishop(pos,WHITE,this);
      board[7][i] = 'b';
    }
    if(i ==3){
      boardp[7][i] = new Queen(pos,WHITE,this);
      board[7][i] = 'Q';
    }
    if(i ==4){
      boardp[7][i] = new King(pos,WHITE,this);
      board[7][i] = 'K';
    } 
  }
  //Set black pawns
  for(int i = 0; i < FILES; i++){
    board[1][i] = 'p';
    pos[0] = 7;
    pos[1] = static_cast<char>(i+65);
    boardp[1][i] = new Pawn(pos,BLACK,this);
  }
   //set black others//
  for(int i=0; i < FILES; i++){
    pos[0] = 8;
    pos[1]= static_cast<char>(i+65);
    if(i == 0 || i ==7){
      boardp[0][i] = new Rook(pos,BLACK,this);
      board[0][i] = 'r';
    }
    if(i ==1 || i == 6){
      boardp[0][i] = new Knight(pos,BLACK,this);
      board[0][i] = 'k';
    }
    if(i ==2 || i == 5){
      boardp[0][i] = new Bishop(pos,BLACK,this);
      board[0][i] = 'b';
    }
    if(i ==3){
      boardp[0][i] = new Queen(pos,BLACK,this);
      board[0][i] = 'Q';
    }
    if(i ==4){
      boardp[0][i] = new King(pos,BLACK,this);
      board[0][i] = 'K';
    } 
  }
  // Initialise remaing pointers as null //

  for(int i =2; i < 6; i++){
    for(int j = 0; j <FILES; j++){
      boardp[i][j]=nullptr;
    }
  }
}

int ChessBoard::submitMove(const char* start, const char* end){

  int colour_piece;
  int srow,scolumn,erow,ecolumn, outcome;
  
  srow = rank_check(start[1]);
  scolumn = file_check(start[0]);
  erow = rank_check(end[1]);
  ecolumn = file_check(end[0]);

  
  if(boardp[srow][scolumn] != nullptr)
  
  if(srow == -1 or scolumn == -1){
    cout << start << " is an invalid coordinate!" << endl;
    return ERROR;
  }

  if(erow == -1 or ecolumn == -1){
    cout << end << " is an invalid coordinate!" << endl;
    return ERROR;
  }

  if(srow == erow and scolumn == erow){
    cout << "Cannot move from and to the same position: "
	 << start << " to "<< end << "!"<<endl;
    return ERROR;
  }
  /*cout << "start row:" << srow << endl;
  cout << "start column:"<< scolumn << endl;
  cout << "end row:" << erow << endl;
  cout << "end column:"<< ecolumn << endl;*/

  
  /* Check if piece in position */

  if(boardp[srow][scolumn] == nullptr){
    cout << "There is no peice at position " <<start <<"!"<< endl;
    return ERROR;
  }
  
   /* Check turn */

  colour_piece = boardp[srow][scolumn]->colour;

  if(colour_piece != turn){
    cout <<"It is not ";
    print_colour(colour_piece);
    cout<< " turn to move!" << endl;
    return ERROR;
  }

  /* make move */

  print_colour(colour_piece);

  outcome = boardp[srow][scolumn]->move(start,end);
  if(outcome == ERROR)
    return ERROR;

  if(outcome == TAKE_PIECE){
    delete boardp[erow][ecolumn];
    boardp[erow][ecolumn] = nullptr;
  }
  
  boardp[erow][ecolumn] = boardp[srow][scolumn];
  boardp[srow][scolumn] = nullptr;

  print_board(this); 

  change_turn();
  
  return 0;
}

void ChessBoard::resetBoard(){
  

}

void ChessBoard::change_turn(){
  if(turn == WHITE){
    turn = BLACK;
    return;
  }
  if(turn ==BLACK){
    turn = WHITE;
    return;
  }
}
