//Shamitha Pichika
//lab9.cpp
//10/26/2022

#include <iostream>
using namespace std;

void input(string& str1, string& str2);
void swapStr(string& str1, string& str2);
void output(string str1, string str2);

int main()
{
  string str1, str2;
  
  cout << "\n\n";

  input(str1, str2);

  cout << "\n";

  output(str1, str2);

  cout << "\n";

  swapStr(str1, str2);

  cout << "\n\n";

  output(str1, str2);

  cout << "\n";

  return 0;

}

void input(string& str1, string& str2)
{
  cout << "\n\n";
  cout << "Enter two strings: ";
  cin >> str1 >> str2;
  cout << "\n"; 
}
void swapStr(string& str1, string& str2)
{
  string temp = str1;
  str1 = str2;
  str2 = temp;
}
void output(string str1, string str2)
{
  cout << "str1 is " << str1 << " and str2 is "<< str2 << ".";
  cout << "\n\n";
}

