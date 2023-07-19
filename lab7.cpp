//Shamitha Pichika
//lab7.cpp
//10/19/2022

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int num;
  const int MIN = 3;
  const int MAX = 9;
  const int COL_WIDTH = 3;
  const char SPACE = ' ';
  
  cout << "\n\n\n";
  cout << "Welcome to the Pretty Fors Program! \n";
  cout << "Enter a number (between " << MIN << " and " << MAX << "): ";
  cin >> num;

  while(num < MIN || num > MAX) {
    cout << "Enter a number (between " << MIN << " and " << MAX << "): ";
    cin >> num;
  }

  cout << "\n";
  cout << "Pattern #1: \n";
  cout << "\n";

  for(int i = 1; i <= num; i++) {
    cout << i;
  }

  cout << "\n";
  cout << "\n";
  cout << "\n";
  cout << "Pattern #2: \n";
  cout << "\n";

  for(int j = 1; j <= num; j++) {
    cout << j << "\n";
  }

  cout << "\n";
  cout << "\n";
  cout << "Pattern #3: \n";
  cout << "\n";


  for(int a = 1; a <= num; a++) {
    cout << setw(COL_WIDTH) << a;
  }
  cout << "\n";
  for(int b = 1; b <= num; b++) {
    cout << setw(COL_WIDTH) << b;
    for(int c = 1; c <= num; c++) {
      cout << setw(COL_WIDTH) <<  b * c;
    }
    
    cout << "\n";
  }

  cout << "\n";
  cout << "\n";
  cout << "Pattern #4: \n";
  cout << "\n";


  for(int i = 1; i <= num; i++) {
    for(int j = 1; j <= i; j++) {
      cout << j << SPACE;
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "\n";
  cout << "Pattern #5: \n";
  cout << "\n";


  for(int i = 1; i <= num; i++) {
    for(int j = 1; j < i; j++) {
      cout << SPACE;
    }
    cout << i << "\n";
  }  
  for(int i = (num-1); i >= 1; i--) {
    for(int j = 0; j < (i-1); j++) {
      cout << SPACE;
    }
    cout << i << "\n";
  }

  cout << "\n";
  cout << "\n";
  cout << "Pattern #6: \n";
  cout << "\n";

  for(int i = 1; i <= num; i++) {
    if(i == 1) {
      cout << setw(num) << i << "\n";
    } else {
      cout << setw(num - i + 1) << i << setw(2 * i - 2) << i << "\n";
    }
  }
  for(int i = (num-1); i >= 1; i--) {
    if(i == 1) {
      cout << setw(num) << i << "\n";
    } else {
      cout << setw(num - i + 1) << i << setw(2 * i - 2) << i << "\n";
    }

  }
  cout << "\n";
  cout << "Have a nice day!";
  cout << "\n\n\n";
  
  return 0;

}
