#include"helper.hpp"
#include<iostream>
#include"Chessboard.hpp"
#include<cstdlib>

using namespace std;

void print_colour(int colour){
  switch(colour){
  case(WHITE):{
    cout <<"White's";
    break;
  }
  case(BLACK):{
    cout <<"Black's";
    break;
  }
  }
}

int file_check(char file){
  
  int ifile;
  ifile = static_cast<int>(file)-'A';
  if(ifile > 7 or ifile < 0)
    return ERROR;

  return ifile;
}

int rank_check(char rank){

  int irank;
  irank= static_cast<int>(rank-'1');
  if(irank > 7 or irank < 0){
    return ERROR;
  }
  
  return abs(irank-7);
}

void print_board(ChessBoard* board){
  cout << endl;
  cout << "   A   B   C   D   E   F   G   H  " << endl;
  cout << " ================================ " << endl;
  for(int i = 0; i < ROWS; i++){
    cout << abs(i-8);
    for(int j =0; j < FILES; j++){
      cout << "| ";
      if(board->boardp[i][j] == nullptr)
	cout <<".";
       else
	 cout<<board->boardp[i][j]->type;
       cout <<" ";
    }
    cout << "|"<<abs(i-8)<< endl << endl;
  }
  cout << " ================================ " << endl;
  cout << "   A   B   C   D   E   F   G   H  " << endl << endl;
}

  
