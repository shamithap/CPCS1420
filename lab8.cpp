//Shamitha Pichika
//lab8.cpp
//10/24/2022

#include <iostream>
#include <cctype>
using namespace std;

void welcome();
int input();
int summation(int val);
void goodbye();

const int MIN = 5;
const int MAX = 25;
const char YES = 'y';
char answer = YES;

int main()
{ 
  welcome();

  while(tolower(answer) == YES) {
    
    int num = input();
    int result = summation(num);
    cout << "\n";
    cout << result;
    cout << "\n\n";

    cout << "Want to play again(y/n): ";
    cin >> answer;
  }

  goodbye();
  
  return 0;

}

void welcome()
{
  cout << "\n\n";
  cout << "Welcome to lab 8!";
  cout << "\n\n";
}
int input()
{
  int val;
  cout << "\n";
  cout << "Enter a number in between " << MIN << " and " << MAX << ":";
  cin >> val;
  while(val < 5 || val > 25) {
    cout << "\n";
    cout << "Sorry, enter a number within the range:";
    cin >> val;
  }
  return val;
}
int summation(int val)
{
  int sum = 0;
  for(int i = 1; i <= val; i++) {
    sum = sum + i;
  }
  return sum;
}
void goodbye() {
  cout << "Thank you for tuning in! Goodbye!";
  cout << "\n\n";
}
