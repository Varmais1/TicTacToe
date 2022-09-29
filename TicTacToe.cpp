#include <iostream>

using namespace std;
const int blank = 0;
const int xSpace = 1;
const int oSpace = 2;
const int xTurn = 0;
const int oTurn = 1;


void playGame(int board[3][3]);
void displayBoard(int board[3][3]);
bool checkwin(int board[3][3], int player);

int main() {
  bool play = true;
  char input = 'Y';

  
  while(play == true) {
    int board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    displayBoard(board);
    playGame(board);
    cout << "Type Y to play again, type N to stop" << endl;
    cin >> input;
    if(input == 'Y') {
      play = true;
    }
    else if(input == 'y') {
      play = true;
    }
    else {
      play = false;
    }
  }
  
  
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
  int move = 0;
  char movePos[2]; 
  bool validMove = false;
  bool win = false;
  while(turn != 9 && win == false) {
    if(turn%2 == xTurn) {
      move = xSpace;
    }
    else {
      move = oSpace;
    }
    do {
      cin >> movePos;
      //cout << "movePos[0]: " << movePos[0] << endl;
      //cout << "movePos[1]: " << movePos[1] << endl;
      if(board[(int)movePos[1]-97][(int)movePos[0]-49] == blank) {
	board[(int)movePos[1]-97][(int)movePos[0]-49] = move;
	//cout << "board value: " << board[(int)movePos[0]-1][(int)movePos[1]-97] << endl;
	//cout << "board pos x index: " << (int)movePos[0] - 49 << endl;
	//cout << "board pos y index: " << (int) movePos[1] - 97 << endl;
	turn++;
      }
    }while(validMove = false);
    /*for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
	cout << "board[" << i << "][" << j <<"]: " << board[i][j] << endl;
      }
      }*/
    displayBoard(board);
    win = checkwin(board, (move%2));
  }
}

bool checkwin(int board[3][3], int player) {
  player++;
  if(player == 1) {
    player++;
  }
  else if(player == 2) {
    player--;
  }
  //cout << "player: " << player << endl;
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O Wins!" << endl;
    }
    return true;
  }
  else if(board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O wins!" << endl;
    }

    return true;
  }
  else if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O wins!" << endl;
    }

    return true;
  }
  else if(board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O wins!" << endl;
    }

    return true;
  }
  else if(board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O wins!" << endl;
    }

    return true;
  }
  else if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O wins!" << endl;
    }

    return true;
  }
  else if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O wins!" << endl;
    }

    return true;
  }
  else if(board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
    }
    else {
      cout << "O wins!" << endl;
    }

    return true;
  }
  //returns false if no win condition is satisfied
  else {
    return false;
  }
}
