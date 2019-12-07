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

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < FILES; j++){
	boardp[i][j] = nullptr;
    }
  }
  
  
  ChessBoard::resetBoard();
}

int ChessBoard::submitMove(const char* start, const char* end){
  
  int colour_piece;
  int srow,scolumn,erow,ecolumn, outcome;
  
  srow = rank_check(start[1]);
  scolumn = file_check(start[0]);
  erow = rank_check(end[1]);
  ecolumn = file_check(end[0]);

  
  if(srow == -1 or scolumn == -1){
    cout << start << " is an invalid coordinate!" << endl;
    return INVALID_COORDINATES;
  }

  if(erow == -1 or ecolumn == -1){
    cout << end << " is an invalid coordinate!" << endl;
    return INVALID_COORDINATES;
  }

  
  /* Check if piece in position */

  if(boardp[srow][scolumn] == nullptr){
    cout << "There is no peice at position " <<start <<"!"<< endl;
    return INVALID_COORDINATES;
  }
  
  /* Check turn */

  colour_piece = boardp[srow][scolumn]->colour;

  if(colour_piece != turn){
    cout <<"It is not ";
    print_colour(colour_piece);
    cout<< " turn to move!" << endl;
    return NOT_CORRECT_TURN;
  }
  /* check if moving to same position */
  if(srow == erow and scolumn == erow){
    print_colour(colour_piece);
    cout <<" ";
    boardp[srow][scolumn]->print_type();
    cout << " cannot move from and to the same position: "
	 << start << " to "<< end << "!"<<endl;
    return INVALID_MOVE;
  }


  
  /* make move */

  print_colour(colour_piece);
  outcome = boardp[srow][scolumn]->move(start,end);

  /* error case */ 
  if(outcome < 0){
    cout << " ";
    boardp[srow][scolumn]->print_type();
    cout << " cannot move to " << end <<"!" << endl;
    print_error(outcome);
    return ERROR;
  }
  
  /*Check if will leave king in check*/

  if(leaves_king_in_check(start,end,colour_piece) == IN_CHECK){
    cout << " ";
    boardp[srow][scolumn]->print_type();
    cout << " cannot move to " << end <<"!";
    cout << " It will leave own king in check" << endl;
    return ERROR;
  }
 
  if(outcome == REGULAR_MOVE or outcome == TAKE_PIECE){
    (boardp[srow][scolumn]->number_of_moves)++;
    cout << " ";
    boardp[srow][scolumn]->print_type();
    cout <<" moves from " << start << " to " << end;
    if(outcome == TAKE_PIECE){
      cout << " taking ";
      print_colour(boardp[erow][ecolumn]->colour);
      cout << " ";
      boardp[erow][ecolumn]->print_type();
    }
    cout << endl;
  }
  
  // Make Move !!! Dont Change ordering !!//
  if(outcome == TAKE_PIECE){
    delete boardp[erow][ecolumn];
    boardp[erow][ecolumn] = nullptr;
  }
  if(outcome == TAKE_PIECE or outcome == REGULAR_MOVE){
  boardp[erow][ecolumn] = boardp[srow][scolumn];
  boardp[srow][scolumn] = nullptr;
  }
  
  // Move King on board //
  if(boardp[erow][ecolumn]->type == 'K'){
    move_king(turn,end);
  }

  // Opponent in check and check mate following move //
  {
    int in_check_var = 0;
    int in_check_mate_var = NOT_IN_CHECK_MATE;
    if(colour_piece == WHITE)
      in_check_var = is_in_check(end,BLACK);
    if(colour_piece == BLACK)
      in_check_var = is_in_check(end,WHITE);

    if(in_check_var == IN_CHECK and colour_piece ==BLACK){
      cout << "White is in check";
      in_check_mate_var = is_in_check_mate(WHITE);
      if(in_check_mate_var == CHECK_MATE)
	 cout << "mate";
      cout << endl;
       in_check = IN_CHECK;
    }
    if(in_check_var == IN_CHECK and colour_piece == WHITE){
      cout << "Black is in check";
      in_check_mate_var = is_in_check_mate(BLACK);
      if(in_check_mate_var == CHECK_MATE)
	cout << "mate";
      cout << endl;
      in_check = IN_CHECK;
    }
    if(in_check_mate_var == CHECK_MATE)
      return CHECK_MATE;
  }
   
  change_turn();

  if(is_in_stale_mate(turn) == STALE_MATE){
    cout << "Game is in stalemate" << endl;
    return STALE_MATE;
  }
  
  return 0;
}

void ChessBoard::resetBoard(){

  cout <<"A new chess game is started!" << endl;
  
  
  // Clear existing board //
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < FILES; j++){
      if(boardp[i][j] != nullptr){
	delete boardp[i][j];
	boardp[i][j] = nullptr;
      }
    }
  }
  
  char pos[2];

  turn = WHITE;  //Set turn to white
  in_check = NOT_IN_CHECK;
  white_king[0] = 'E';
  white_king[1] = '1';
  black_king[0] = 'E';
  black_king[1] = '8';
  
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

int ChessBoard::leaves_king_in_check(const char* start,const char* end,int colour){

  int srow = rank_check(start[1]);
  int scolumn = file_check(start[0]);
  int erow = rank_check(end[1]);
  int ecolumn = file_check(end[0]);
  char pos[3];
  pos[2] = '\0';
  int move = 0;
  int outcome = -3;
  
  Piece* temp_ptr = nullptr;

  // In case King moves temp move king position //
  if(boardp[srow][scolumn]->type == 'K'){
    move_king(boardp[srow][scolumn]->colour,end);
  }
  if(boardp[erow][ecolumn] != nullptr){
    // Temporarily move piece //
    temp_ptr = boardp[erow][ecolumn];
    boardp[erow][ecolumn] = boardp[srow][scolumn];
    boardp[srow][scolumn] = nullptr;
    ++move;
  }
  if(boardp[erow][ecolumn] == nullptr and move == 0){
    // Temporarily move piece //
    boardp[erow][ecolumn] = boardp[srow][scolumn];
    boardp[srow][scolumn] = nullptr;
  }


  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j <FILES; j++){
      pos[0] = static_cast<char>(j+'A');
      pos[1] = static_cast<char>('8'-i);
      if(boardp[i][j] != nullptr and boardp[i][j]->colour != colour){
	outcome = is_in_check(pos,colour);
	if(outcome == IN_CHECK){
	  if(temp_ptr!= nullptr){
	    boardp[srow][scolumn] = boardp[erow][ecolumn];
	    boardp[erow][ecolumn] = temp_ptr;
	    temp_ptr = nullptr;
	    if(boardp[srow][scolumn]->type == 'K'){
	      move_king(boardp[srow][scolumn]->colour,start);
	    }
	    return IN_CHECK;
	  }
	  if(temp_ptr == nullptr){
	    boardp[srow][scolumn] = boardp[erow][ecolumn];
	    boardp[erow][ecolumn] = nullptr;
	    if(boardp[srow][scolumn]->type == 'K'){
	    move_king(boardp[srow][scolumn]->colour,start);
	    }
	    return IN_CHECK;
	  } 
	}
      }
    }
  }

  if(temp_ptr!= nullptr){
    boardp[srow][scolumn] = boardp[erow][ecolumn];
    boardp[erow][ecolumn] = temp_ptr;
    temp_ptr = nullptr;
    if(boardp[srow][scolumn]->type == 'K'){
      move_king(boardp[srow][scolumn]->colour,start);
    }
      return NOT_IN_CHECK;
  }
  if(temp_ptr == nullptr){
    boardp[srow][scolumn] = boardp[erow][ecolumn];
    boardp[erow][ecolumn] = nullptr;
    if(boardp[srow][scolumn]->type == 'K'){
      move_king(boardp[srow][scolumn]->colour,start);
    }
    return NOT_IN_CHECK;
  } 
  return NOT_IN_CHECK;
}

// Checks whether the king of the colour you pass is in check //

int ChessBoard::is_in_check(const char* piece_pos, int colour){

  
  char* king_pos_var;
  int outcome = 0;
  int srow = rank_check(piece_pos[1]);
  int scolumn = file_check(piece_pos[0]);
  
  if(colour == BLACK)
    king_pos_var = black_king;
  if(colour == WHITE)
    king_pos_var = white_king;
  
  outcome = boardp[srow][scolumn]->move(piece_pos,king_pos_var);

  if(outcome == TAKE_PIECE or outcome == REGULAR_MOVE){  
      return IN_CHECK;
  }
  
  return NOT_IN_CHECK;
}

void ChessBoard::move_king(int colour, const char* pos){

  if(colour == WHITE){
    white_king[0] = pos[0];
    white_king[1] = pos[1];
    return;
  }
  if(colour == BLACK){
    black_king[0] = pos[0];
    black_king[1] = pos[1];
    return;
  }
}

int ChessBoard::is_in_check_mate(int colour){

  char start_pos[3], end_pos[3];
  int outcome, pos_move(-1);

  start_pos[2] = '\0';
  end_pos[2] = '\0';

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < FILES; j++){
      if(boardp[i][j] != nullptr and boardp[i][j]->colour == colour){
	start_pos[0] = static_cast<char>(j+'A');
	start_pos[1] = static_cast<char>('8'-i);
	for(int k = 0; k< ROWS; k++){
	  for(int l = 0; l < FILES; l++){
	    end_pos[0] = static_cast<char>(l+'A');
	    end_pos[1] = static_cast<char>('8'-k);
	    pos_move = boardp[i][j]->move(start_pos,end_pos);
	    if(pos_move == TAKE_PIECE or pos_move == REGULAR_MOVE){
	      outcome =leaves_king_in_check(start_pos,end_pos,colour);
	      if(outcome == NOT_IN_CHECK){
		return NOT_IN_CHECK_MATE;
	      }
	    }
	  }
	}
      }
    }
  }
  
  return CHECK_MATE;
}

int ChessBoard::is_in_stale_mate(int colour){
  
  char start_pos[3], end_pos[3];
  start_pos[2] = '\0';
  end_pos[2] = '\0';
    
  for(int i = 0; i < ROWS; i++){
    for(int j= 0; j < FILES; j++){
      if(boardp[i][j]!= nullptr and boardp[i][j]->colour == colour){
        start_pos[0] = static_cast<char>(j+'A');
	start_pos[1] = static_cast<char>('8'-i);
	for(int k = 0; k < ROWS; k++){
	  for(int l = 0; l < FILES; l++){
	    end_pos[0] = static_cast<char>(l+'A');
	    end_pos[1] = static_cast<char>('8'-k);
	    if(boardp[i][j]->move(start_pos,end_pos) >-1 and
	       leaves_king_in_check(start_pos,end_pos,colour) == NOT_IN_CHECK){
	      return NOT_IN_STALE_MATE;
	    }
	  }
	}
      }
    }
  }
  return STALE_MATE;
}

void ChessBoard::print_error(int error){

  switch(error){
  case(PIECE_BLOCKING):
    cout << " Piece blocking path! " << endl;
    break;
  case(INVALID_MOVE):
    cout << " Invalid move!" << endl;
    break;
  case(PAWN_BACKWARDS):
    cout <<" Pawn cannot move backwards" << endl;
    break;
  case(UNDEFINED_ERROR):
    cout << " Undefined Error!!!!" << endl;
    break;  
  case(NONE_CAPTURING_DIAGONAL):
    cout <<" None capturing Diagonal move" << endl;
    break;
  case(BISHOP_NOT_DIAGONAL):
    cout << " Not diagonal" << endl;
    break;
  }
}

ChessBoard::~ChessBoard(){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < FILES; j++){
      if(boardp[i][j] != nullptr){
	delete boardp[i][j];
	boardp[i][j] = nullptr;
      }
    }
  }
}


