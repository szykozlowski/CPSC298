#include <iostream>
//#include "tictactoe.h"
class Game{

//Variables
public:
  char** board;
  int scores[3][3] = {{0,0,0},{0,2,0},{0,0,0}};
  bool game;
  bool tie;
  int moveCount;

//Contructor
  Game(){
    board = new char* [3];
    board[0] = new char[3];
    board[1] = new char[3];
    board[2] = new char[3];
    game = true;
    tie = true;
    moveCount = 0;
  }
  //Destructor
  ~Game(){
    delete[] board;
  }

//Creates a 3x3 board of ~ characters
  void populateBoard(){
    for(int i = 0; i < 3;i++){
      for(int j = 0; j < 3; j++){
        board[i][j] = '~';
      }
    }
  }

//Prints the board
  void printBoard(){
    for(int i = 0; i < 3;i++){
      std::cout << std::endl;
      for(int j = 0; j < 3; j++){
        std::cout << board[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }

//Prints the scores associated with each square
  void printScores(){
    for(int i = 0; i < 3;i++){
      std::cout << std::endl;
      for(int j = 0; j < 3; j++){
        std::cout << scores[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }

//Prompts the player to make a valid move
  void playerMove(){
    int row;
    int column;
    bool move = true;
    while(move){
    std::cout << "Enter a Row: " << std::endl;
    std::cin >> row;
    std::cout << "Enter a Column: " << std::endl;
    std::cin >> column;
    if(row > 2 || row < 0 || column > 2 || column < 0){
      std::cout << "Invalid input, try again"<< std::endl;
    }
    else if(board[row][column] != '~'){
      std::cout << "The Grid Square [" << row << "][" << column << "] is already taken, try again" << std::endl;
    }

    else{
      move = false;
    }


  }
  board[row][column] = 'X';
}

//Computer picks the highest scored move
  void computerMove(){
    int scoreMax = -1;
    int bestCol;
    int bestRow;
    for(int i = 0;i < 3;i++){
      for(int j = 0; j < 3;j++){
        if(scores[i][j] > scoreMax && board[i][j] == '~'){
          bestRow = i;
          bestCol = j;
          scoreMax = scores[i][j];
        }
      }
    }
    board[bestRow][bestCol] = 'O';
}
//Checks if anyone won
void checkWin(int xCount, int cCount){
    if(xCount == 3){
      game = false;
      tie = false;
      std::cout << "Player has Won!" << std::endl;
    }
    else if(cCount == 3){
      game = false;
      tie = false;
      std::cout << "Computer has Won!" << std::endl;
        }
}
//Loops Through the rows, columns, and diagonals.  Assigns a score to each Square
//based on how good of a move it is.
  void calcScores(){
    int xCount;
    int cCount;
    int i;
    int j;
    int k;
    //check rows
    for(i = 0; i < 3; i++){
      xCount = 0;
      cCount = 0;
      for(j = 0;j < 3;j++){
        if(board[i][j] == 'O'){
          cCount++;
        }
        if(board[i][j] == 'X'){
          xCount++;
        }
        checkWin(xCount,cCount);
      }
      for(k = 0; k < 3;k++){
        if(cCount == 2){
        scores[i][k] = 10;
      }
      else if(xCount == 2){
        scores[i][k] = 9;
      }
      else if(xCount == 1 && cCount == 1 && scores[i][k] < 8){
        scores[i][k] = 0;
      }
      else{
        if(xCount + cCount > scores[i][k]){
        scores[i][k] = xCount + cCount;
      }
    }
  }
}

//check columns
    for(j = 0; j < 3; j++){
      xCount = 0;
      cCount = 0;
      for(i = 0;i < 3;i++){
        if(board[i][j] == 'O'){
          cCount++;
        }
        if(board[i][j] == 'X'){
          xCount++;
        }
        checkWin(xCount,cCount);
      }
      for(k = 0; k < 3;k++){
        if(cCount == 2){
        scores[k][j] = 10;
      }
      else if(xCount == 2){
        scores[k][j] = 9;
      }
      else if(xCount == 1 && cCount == 1 && scores[k][j] < 8){
        scores[k][j] = 0;
      }
      else{
        if(xCount + cCount > scores[k][j]){
          scores[k][j] = xCount + cCount;
      }
    }
  }
}

    //check diags
    xCount = 0;
    cCount = 0;
    for(i = 0; i < 3; i++){
      for(j = i;j <= i;j++){
        if(board[i][j] == 'O'){
          cCount++;
        }
        if(board[i][j] == 'X'){
          xCount++;
        }
        checkWin(xCount,cCount);
      }
      for(k = 0; k < 3;k++){
        if(cCount == 2){
        scores[k][k] = 10;
      }
      else if(xCount == 2){
        scores[k][k] = 9;
      }
      else if(xCount == 1 && cCount == 1 && scores[k][k] < 8){
        scores[k][k] = 0;
      }
      else{
        if(xCount + cCount > scores[k][k]){
        scores[k][k] = xCount + cCount;
      }
    }
  }
}

    xCount = 0;
    cCount = 0;
    for(i = 0; i < 3; i++){
      for(j = i;j <= i;j++){
        if(board[i][2-j] == 'O'){
          cCount++;
        }
        if(board[i][2-j] == 'X'){
          xCount++;
        }
      }
      for(k = 0; k < 3;k++){
        if(cCount == 2){
        scores[k][2-k] = 10;
      }
      else if(xCount == 2){
        scores[k][2-k] = 9;
      }
      else if(xCount == 1 && cCount == 1 && scores[k][2-k] < 8){
        scores[k][2-k] = 0;
      }
      else{
        if(xCount + cCount > scores[k][2-k]){
          scores[k][2-k] = xCount + cCount;
      }
    }
  }
}
checkWin(xCount,cCount);
}

//Play function
void play(){
   populateBoard();
  while(game && moveCount < 5){
    printBoard();
    playerMove();
    calcScores();
    if(moveCount < 4){
    computerMove();
    calcScores();
  }
    moveCount++;
  }
  if(tie && moveCount == 5){
    std::cout << "TIE!" << std::endl;
  }
}
};
