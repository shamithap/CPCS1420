//Shamitha Pichika
//lab11.cpp
//11/02/2022

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int ROWS = 5;
const int COLS = 8;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";
const int COL_WIDTH = 4;

int main() 
{
  ifstream infile;
  int numArray[ROWS][COLS];
  int sum = 0;

  infile.open(F_NAME);
  if(infile.fail()) {
    cout << "File failure... exiting program... press enter";
    cin.get();
    return 0;
  }
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      infile >> numArray[i][j]; 
    }
  }

  infile.close();
  cout << "\n\n";
  cout << "Table: \n\n";
  for(int a = 0; a < ROWS; a++ ) {
    sum = 0;
    for(int b = 0; b < COLS; b++) {
      cout << setw(COL_WIDTH) << numArray[a][b];
      sum += numArray[a][b];
    }
    cout << "  Row total: " << sum << "\n";
  }
  
  cout << "\n";
  cout << "Column total: \n";

  for(int c = 0; c < COLS; c++) {
    sum = 0;
    for(int d = 0; d < ROWS; d++) {
      sum += numArray[d][c];
    }
    cout << setw(COL_WIDTH) << sum;
  }

  cout << "\n\n";
  sum = 0;

  for(int e = 0; e < ROWS; e++) {
    for(int f = 0; f < COLS; f++) {
      sum += numArray[e][f];
    }
  }

  cout << "Sum of all values: " << sum << "\n";
  cout << "\n\n";
  
  return 0;
}

