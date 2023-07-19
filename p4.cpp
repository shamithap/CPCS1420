//Shamitha Pichika
//p4.cpp
//11/17/2022
//Purpose: this programs uses an array and functions to create an array
//Input: two files are used in which values are extracted to make the gameboard
//Process: The user will be asked to select a difficulty level and try to match
//the correct pairs of cards together
//Output: Tells user if they successfully matched, or did not match a pair
//Example: "You made a match!"...

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

const char YES = 'y'; //user chooses to play again
const char BEG = 'b'; //beginner option
const char EXP = 'e'; //expert option
const char SPACE = ' '; //space constant
const char UNDERSCORE = '_'; //underscore
const char CARD_CENTER = '*'; //center of cards
const int COL_WIDTH = 4; //column width
const int SCREEN_HEIGHT = 30; //30 blank lines
const int BEG_SECONDS = 4; // beginner time
const int EXP_SECONDS = 2; //expert time
const int ROWS = 4; //number of rows
const int COLS = 3; //number of columns
const int DEFAULT = -1; //starting of rows and columns values
const int WON_MATCHES = 6; //number of matches for winning
const string FILE_1 = "/home/fac/sreeder/class/cs1420/p4data1.dat"; //board one
const string FILE_2 = "/home/fac/sreeder/class/cs1420/p4data2.dat"; //board two

void welcome(); //display welcome message

void wait(int seconds); //wait function

int getLevel(); //lets user select if they want a beginner or expert level

bool readFile(char board[][COLS], bool changeBoard); //reads file and assigns gameboard

void displayScreen(char board[][COLS], int c2Row = -1, 
                   int c2Col = -1, int c1Row = -1, int c1Col = -1); //displays screen and gameboard

void getFirstCard(char board[][COLS], int& c1Row, int& c1Col); //gets first card

void getSecondCard(char board[][COLS], int c1Row, int c1Col, int& c2Row, 
                   int& c2Col); //gets second card

int checkMatch(char board[][COLS], int waitTime); //checks for mathc in the cards

void clearScreen(); //clears screen to 25 blank lines 

void goodbye(); //display good bye message (after user chooses not to play again)

int main() 
{
  char answer = YES;
  char game[ROWS][COLS];
  int turns = 0;
  int matches = 0;
  int waitTime;
  
  welcome();
  
  while(tolower(answer == YES)) {
    turns = 0; //reset turns to zero
    matches = 0; //reset matches to zero
    waitTime = getLevel(); //receives wait time based on level from getLevel
    while(WON_MATCHES != matches) {
      matches = matches + checkMatch(game, waitTime);
      turns++;
    }
    cout << "You matched everything!!! Winner! \n";
    if(turns == WON_MATCHES) {
      cout << "You got a perfect score! \n";
      cout << "Your score: " << turns << "\n";
      cout << "Do you want to play again? (y/n)";
      cin >> answer;
      cout << "\n\n";
      
    }
    goodbye();
    return 0;
  }
} //end main

void welcome()
{
  cout << "\n\n";
  cout << "Welcome to the amazing Memory Game! \n";
  cout << "You will choose between a beginner and expert \n";
  cout << "level and be shown a series of cards. You will must \n";
  cout << "try to match the cards correctly in the least number of \n";
  cout << "turns possible to get the best score. Good luck!";
  cout << "\n\n";
}

void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait){}
}

int getLevel()
{
  int time;
  char level = 'y';
  while(level != BEG && level != EXP) {
    cout << "Would you like to play as a beginner or expert? (b/e) \n";
    cin >> level;
  }
  if(tolower(level == BEG)) {
    time = BEG_SECONDS;
  } else {
    time = EXP_SECONDS;
  }
  return time;
}

bool readFile(char board[][COLS], bool changeBoard) 
{
  string currentBoard;
  ifstream infile;
  
  if(!changeBoard){
    currentBoard = FILE_1;
  } else {
    currentBoard = FILE_2;
  }
  infile.open(currentBoard);
  if(infile.fail()) {
    cout << "File failure... exiting program... press enter";
    cin.get();
    return false;
  }
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      infile >> board[i][j];
    }
  }
  infile.close();
  return true;
}

void displayScreen(char board[][COLS], int c2Row, int c2Col, int c1Row, int c1Col)
{
  
  for(int i = 0; i < COLS; i++) {
    cout << setw(COL_WIDTH) << i;
  }
  cout << "\n";
  for(int i = 0; i < ROWS; i++) {
    cout << i << SPACE;
    for(int j = 0; j < COLS; j++) {
      cout << ']';
      if(i == c1Row && j == c1Col) {
        cout << board[c1Row][c1Col];
      } else if(i == c2Row && j == c2Col) {
        cout << board[c2Row][c2Col];
      } else if(board[i][j] == UNDERSCORE) {
        cout << board[i][j];
      } else {
        cout << CARD_CENTER;
      }
      cout << ']' << SPACE;
    }
    cout << "\n";
  }
  cout << "\n";
}

void getFirstCard(char board[][COLS], int& c1Row, int& c1Col)
{
  int cRow = DEFAULT;
  int cCol = DEFAULT;
  while(cRow == DEFAULT && cCol == DEFAULT) {
    while(cRow < 0 || cRow > ROWS - 1) {
      cout << "(First card) Enter the row number: \n";
      cin >> cRow;
    }
    c1Row = cRow;
    while(cCol < 0 || cCol > COLS - 1) {
      cout << "(First card) Enter the column number: \n";
      cin >> cCol;
    }
    c1Col = cCol;
    if(board[c1Row][c1Col] == UNDERSCORE) {
      cout << "Out of bounds \n";
      cout << "Pick another card \n";
      cRow = DEFAULT;
      cCol = DEFAULT;
    }
  } 
}

void getSecondCard(char board[][COLS], int c1Row, int c1Col, int& c2Row, int& c2Col)
{
  int cRow = DEFAULT;
  int cCol = DEFAULT;
  while(cRow == DEFAULT && cCol == DEFAULT) {
    while(cRow < 0 || cRow > ROWS - 1) {
      cout << "(Second card) Enter the row number: \n";
      cin >> cRow;
    }
    c2Row = cRow;
    while(cCol < 0 || cCol > COLS - 1) {
      cout << "(Second card) Enter the column number: \n";
      cin >> cCol;
    }
    c2Col = cCol;
    if(board[c2Row][c2Col] == UNDERSCORE) {
      cout << "Out of bounds \n";
      cout << "Pick another card \n";
      cRow = DEFAULT;
      cCol = DEFAULT;
    } else if(cRow == c1Row && cCol == c1Col) {
      cout << "Card already selected \n";
      cout << "Pick another card \n";
      cRow = DEFAULT;
      cCol = DEFAULT;
    }
  }
}

int checkMatch(char board[][COLS], int waitTime)
{
  int match;
  int chosenC1R = DEFAULT;
  int chosenC1C = DEFAULT;
  int chosenC2R = DEFAULT;
  int chosenC2C = DEFAULT;
  clearScreen();
  displayScreen(board);
  getFirstCard(board, chosenC1R, chosenC1C);
  clearScreen();
  displayScreen(board, chosenC1R, chosenC1C);
  getSecondCard(board, chosenC1R, chosenC1C, chosenC2R, chosenC2C);
  if(board[chosenC1R][chosenC1C] == board[chosenC2R][chosenC2C]) {
    match = 1;
    board[chosenC1R][chosenC1C] = UNDERSCORE;
    board[chosenC2R][chosenC2C] = UNDERSCORE;
    clearScreen();
    displayScreen(board);
    cout << "Match! \n";
  } else {
    match = 0;
    clearScreen();
    displayScreen(board, chosenC1R, chosenC1C, chosenC2R, chosenC2C);
    cout << "Not a match \n";
    wait(waitTime);
  }
  return match; 
}

void clearScreen() 
{
  for(int i = 0; i < SCREEN_HEIGHT; i++) {
    cout << "\n";
  }
}

void goodbye()
{
  cout << "\n";
  cout << "Thank you for playing! Have a nice day! \n";
  cout << "Toodles! \n";
  cout << "\n\n";
}

