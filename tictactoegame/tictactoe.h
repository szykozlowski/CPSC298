#include <iostream>

class Game{

public:
  char** board;
  int scores[3][3] = {{0,0,0},{0,2,0},{0,0,0}};
  bool game;
  bool tie;
  int moveCount;

  Game();
  ~Game();
  void populateBoard();
  void printBoard();
  void printScores();
  void playerMove();
  void computerMove();
  void checkWin(int xCount, int cCount);
  void calcScores();
  void play();




};
