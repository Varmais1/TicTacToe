#include <iostream>
/* Name: Ishaan Varma
What this file does: Has everything to make the game of Tic-Tac-Toe functional
Date: 9/29/2022
*/
using namespace std;
//Constants for clarity
const int blank = 0;
const int xSpace = 1;
const int oSpace = 2;
const int xTurn = 0;
const int oTurn = 1;

//initialize functions
void playGame(int board[3][3], int& xWinsR, int& oWinsR);
void displayBoard(int board[3][3]);
bool checkwin(int board[3][3], int player, int& xWinsR, int& oWinsR);

//main, where game is started and run
int main() {
  //place to store whether the player wants to play
  bool play = true;
  char input = 'Y';
  //where number of wins are stored
  int xWins = 0;
  int oWins = 0;
  //while the player wants to play...
  while(play == true) {
    //clear the board
    int board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    //show the board
    displayBoard(board);
    //play the game
    playGame(board, xWins, oWins);
    //get if the user wants to play again, and store if they want to or not
    cout << "X Wins: " << xWins << "\tO Wins: " << oWins << endl;
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
  
  //end program
  return 0;
}

//for displaying the board
void displayBoard(int board[3][3]) {
  //print out 1 2 and 3
  cout << "\t1\t2\t3" << endl;
  //for printing out all of the spaces by looping through board
  for(int i = 0; i < 3; i++) {
    //display a, b, or c
    int character = 97 + i;
    char boardValues[3];
    //for each space, print nothing, X, or O based on the value of the space
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


//where the game functions are
void playGame(int board[3][3], int &xWins, int &oWins) {
  //variables that store their namesake
  int turn = 0;
  int move = 0;
  //where user input is kept, and whether the user entered a valid move is stored
  char movePos[2]; 
  bool validMove = false;
  //whether someone won or not
  bool win = false;
  //while its not a tie or a win
  while(turn != 9 && win == false) {
    //determine whose turn it is
    if(turn%2 == xTurn) {
      move = xSpace;
    }
    else {
      move = oSpace;
    }
    //does the turn
    do {
      //get the space to be filled
      cin >> movePos;
      //cout << "movePos[0]: " << movePos[0] << endl;
      //cout << "movePos[1]: " << movePos[1] << endl;
      //if the space is blank, do the move and invcrement the turn
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
    //display the board
    displayBoard(board);
    //check for wins
    win = checkwin(board, (move%2), xWins, oWins);
  }
  //if the game is a tie, output it is a tie
  if(turn == 9) {
    cout << "Its a tie!" << endl;
  }
}
//checks for wins
bool checkwin(int board[3][3], int player, int &xWins, int &oWins) {
  //gets the right player
  player++;
  if(player == 1) {
    player++;
  }
  else if(player == 2) {
    player--;
  }
  //cout << "player: " << player << endl;
  //all win conditions, output which player won, and increment their wins by 1
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
      xWins++;
    }
    else {
      cout << "O Wins!" << endl;
      oWins++;
    }
    return true;
  }
  else if(board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
      xWins++;
    }
    else {
      cout << "O wins!" << endl;
      oWins++;
    }

    return true;
  }
  else if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
      xWins++;
    }
    else {
      cout << "O wins!" << endl;
      oWins++;
    }

    return true;
  }
  else if(board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
      xWins++;
    }
    else {
      cout << "O wins!" << endl;
      oWins++;
    }

    return true;
  }
  else if(board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
      xWins++;
    }
    else {
      cout << "O wins!" << endl;
      oWins++;
    }

    return true;
  }
  else if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    if(player == xSpace) {
      cout << "X Wins!" << endl;
      xWins++;
    }
    else {
      cout << "O wins!" << endl;
      oWins++;
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
      xWins++;
    }
    else {
      cout << "O wins!" << endl;
      oWins++;
    }

    return true;
  }
  //returns false if no win condition is satisfied
  else {
    return false;
  }
}
