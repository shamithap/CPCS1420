//Shamitha Pichika
//lab5.cpp
//10/12/2022

#include <iostream>
using namespace std;

int main()
{
  int int1, int2;
  const char YES = 'y';
  char answer = YES;

  cout << "\n\n";
  cout << "Welcome to the Repeating Decisions Lab!\n";
  cout << "I will decide if the larger integer is a multiple of \n";
  cout << "the smaller one. \n";

  while(answer == YES) {

    cout << "\n\n";
    cout << "Please enter in the first integer: ";
    cin >> int1;
    cout << "\n";
    cout << "Please enter in the second integer: ";
    cin >> int2;
    cout << "\n";

    if(int1 > int2) {
      if(int1 % int2 == 0) {
        cout << int1 << " is a multiple of " << int2 << " and the other \n";
        cout << "factor is " << int1/int2 << ".\n";
        cout << "\n";
      } else {
        cout << "No, " << int1 << " is not a multiple of " << int2 << ".\n";
        cout << "\n";
      }
    
    } else if(int2 % int1 == 0) {
      cout << int2 << " is a multiple of " << int1 << " and the other \n";
      cout << "factor is " << int2/int1 << ".\n";
      cout << "\n";
    } else {
      cout << "No, " << int2 << " is not a multiple of " << int1 << ".\n";
      cout << "\n";
    }

    cout << "Do you want to repeat the operation? (y/n): ";
    cin >> answer;
    cout << "\n";

  }

  cout << "\n";
  cout << "Have a nice day!\n";
  cout << "\n";

  return 0;
  
}

