//Shamitha Pichika
//lab3.cpp
//10/03/2022

#include <iostream>
using namespace std;

int main()
{
  int int1, int2;

  cout << "\n";
  cout << "Welcome to the Making Decisions Lab!\n";
  cout << "I will decide if the first integer is a multiple of the second\n";
  cout << "\n";
  cout << "Please enter in the first integer: ";
  cin >> int1;
  cout << "\n";
  cout << "Please enter in the second integer: ";
  cin >> int2;
  cout << "\n";
  
  if(int1 % int2 == 0) {
    cout << "Yes, and the other factor is " << int1/int2 << ".\n";
    cout << "\n";
    cout << "Have a nice day!\n";
    cout << "\n";
    
  } else {
    
    cout << "No, the first integer is NOT a multiple of the second integer.\n";
    cout << "\n";
    cout << "Have a nice day!\n";
    cout << "\n";
  }

  return 0;
  
}

