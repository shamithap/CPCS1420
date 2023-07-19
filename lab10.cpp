///Shamitha Pichika
//lab10.cpp
//10/31/2022
//Happy Halloween

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
  ifstream infile;
  int num;
  const string F_NAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";
  const int SIZE = 30;
  const int COL_WIDTH = 5;
  int evenNum[SIZE] = {0};
  int oddNum[SIZE] = {0};
  int negNum[SIZE] = {0};
  int negCount = 0;
  int evenCount = 0;
  int oddCount = 0;


  infile.open(F_NAME);
  if(infile.fail()) {
    cout << "File failure... exiting program... press enter";
    cin.get();
    return 0;
  }
  while(infile >> num) {
    if ( num < 0) {
      negNum[negCount] = num;
      negCount++;
    } else if( num % 2 == 0 && num > 0) {
      evenNum[evenCount] = num;
      evenCount++;
    } else if (num % 2 != 0) {
      oddNum[oddCount] = num;
      oddCount++;
    }
  }

  cout << "\n\n";
  cout << "Negative numbers: \n";
  cout << "Index: Value: \n";
  for(int i = 0; i < negCount; i++) {
    cout << setw(COL_WIDTH) << i;
    cout << setw(COL_WIDTH) << negNum[i] << "\n";
  }
  cout << "\n";
  cout << "\n";
  cout << "Even numbers: \n";
  cout << "Index: Value: \n";
  for(int i = 0; i < evenCount; i++) {
    cout << setw(COL_WIDTH) << i;
    cout << setw(COL_WIDTH) << evenNum[i] << "\n";
  }
  cout << "\n";
  cout << "\n";
  cout << "Odd numbers: \n";
  cout << "Index: Value: \n";
  
  for(int i = 0; i < oddCount; i++) {
    cout << setw(COL_WIDTH) << i;
    cout << setw(COL_WIDTH) << oddNum[i] << "\n";
  }
  cout << "\n";
  infile.close();
  
  return 0;
}
