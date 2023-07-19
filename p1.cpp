//Shamitha Pichika
//p1.cpp
//10/04/2022
//Purpose: The programs asks the user for basic information and
//outputs the words into places to create a story-like format
//Input: name, shape, integer, age, villain name, two friend names,
//and football team name
//Process: Takes input from user and outputs into a paragraph format
//Output: User information and prewritten paragraph outline
//Example: name: Shamitha, result: There once was a child named Shamitha...
 
#include <iostream>
using namespace std;

int main()
{
  string name, shape, ficVillain, adj, friend1, friend2, fbTeam;
  int age;

  cout << "\n\n\n";
  cout << "Welcome to the Harry Potter themed Crazy Words program! \n";
  cout << "This program is based off the song, \"Harry Potter in 99 \n";
  cout << "Seconds\" and will ask you a series of questions to generate \n";
  cout << "an interesting story. \n";
  cout << "\n";

  cout << "The magic begins here!\n";
  cout << "\n";
  cout << "Enter a name: ";
  cin >> name;
  cout << "\n";
  cout << "Enter a shape: ";
  cin >> shape;
  cout << "\n";
  cout << "Enter a fictional villain: ";
  cin >> ficVillain;
  cout << "\n";
  cout << "Enter an adjective: ";
  cin >> adj;
  cout << "\n";
  cout << "Enter an age: ";
  cin >> age;
  cout << "\n";
  cout << "Enter a name of a best friend: ";
  cin >> friend1;
  cout << "\n";
  cout << "Enter another best friend's name: ";
  cin >> friend2;
  cout << "\n";
  cout << "Enter the name of a football team (Do not include the \"the\"): ";
  cin >> fbTeam;
  cout << "\n";
  
  cout << "There once was a child named " << name << ", destined \n";
  cout << "to be a " << shape << ". Their parents were killed by \n";
  cout << ficVillain << ", who gave them a " << adj << " scar.\n";
  cout << name << " goes to Hogwarts at the age of " << age << " and \n";
  cout << "meets " << friend1 << " and " << friend2 << ". McGongall \n";
  cout << "requires that they play for the " << fbTeam << ".\n";
  cout << "They all live happily ever after! \n";
  cout << "\n";
  cout << "Thanks for playing!";
  cout << "\n\n\n";

  return 0;

}

  


  
