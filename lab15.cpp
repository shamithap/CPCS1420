//Shamitha Pichika
//lab15.cpp
//11/28/2022

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 75;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";
const char YES = 'y';

int searchString(const string numArray[], int size, string word);

int main()
{
  ifstream infile;
  string list[MAX];
  char answer = YES;
  string searchWord;
  int counter = 0;
  int results = 0;

  infile.open(F_NAME);
  if(infile.fail()) {
    cout << "File failure... exiting program... press enter";
    cin.get();
    return 0;
  }
  while(counter < MAX && infile >> list[counter]) {
    counter++;
  }

  while(tolower(answer) == YES) {
    cout << "\n";
    cout << "Please enter the word you are searching for: \n";
    cin >> searchWord;
    cout << "\n";

    results = searchString(list, MAX, searchWord);

    if(results == -1) {
      cout << "Sorry, that word was not found";
    }
    else {
      cout << "Yes, that word was found at index " << (results - 2) << "\n";
    }
    cout << "\n";
    cout << "Do you want to repeat the program? (y/n) \n";
    cin >> answer;
    cout << "\n";
  }

  cout << "Have a nice day! Good bye!";
  cout << "\n\n";
  infile.close();

  return 0;
}


int searchString(const string numArray[], int size, string word)
{
  int i = 0;
  int position = -1;
  bool found = false;
  
  while(!found && i < size) {
    if(numArray[i] == word) {
      found = true;
      position = i;
    } 
    i++;
  }
  return position;
}
