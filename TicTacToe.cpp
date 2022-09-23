#include <iostream>

using namespace std;
const int blank = 0;
const int xSpace = 1;
const int oSpace = 2;
const int xTurn = 0;
const int oTurn = 1;


void playGame(int board[3][3]);
void displayBoard(int board[3][3]);

int main() {
  int board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
  displayBoard(board);
  
  
  
  return 0;
}

void displayBoard(int board[3][3]) {
  cout << "\t1\t2\t3" << endl;
  for(int i = 0; i < 3; i++) {
    int character = 97 + i;
    char boardValues[3];
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == blank) {
	boardValues[j] = ' ';
      }
      else if(board[i][j] == xSpace) {
	boardValues[j] = 'X';
      }
      else if(board[i][j] == oSpace) {
	boardValues[j] = 'O';
      }
    }
    cout << (char)character << "\t" << boardValues[0] << "\t" << boardValues[1] << "\t" << boardValues[2] << endl;
  }
}

void playGame(int board[3][3]) {
  
  int turn = 0;
  int boardXPos = 0;
  int boardYPos = 0;
  while(turn != 9) {
    
    
    turn++;
  }
}
