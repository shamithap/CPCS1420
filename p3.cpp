//Shamitha Pichika
//p3.cpp
//11/03/2022
//Purpose: To use functions to create a game that replicates Chutes and Ladders
//outputs a spin result based on a random number
//Input: player one name and player two name
//Process: Takes inputs (names) from the users and requests users 
//to spin and moves their position
//Output: Random spin number, new postion on board 
//Example: p1: Sam, spin result: 6 result: Sam moves 6 spaces...

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const int MAX_SPIN = 6; //max spin value
const int MIN_SPIN = 1; //min spin value 
const int WIN_SQUARE = 100; //winning square
const int START_SQUARE = 0; //starting position 
const char YES = 'y';

void welcome(); //welcome message

int spin(); //generate random spin number from 1 to 6

int takeTurn(int location, string player); //players take turn

int checkLocation(int location); //determines if player is on chute or ladder

void pPosition(string p1, string p2, int p1Location, int p2Location); 
//tracks postion 

void goodbye(); //goodbye message

int main() {
  srand(time(0)); //time
  char answer = YES; //for asking if players want to play again
  string p1, p2; //player names
  int p1Location, p2Location; //player locations
  bool p1turn = true; //alternates player turns
  
  welcome();
  
  while(tolower(answer) == YES) {
    p1Location = START_SQUARE;
    p2Location = START_SQUARE;
    
    cout << "Enter the name of player one: ";
    cin >> p1;
    cin.ignore();
    cout << "Enter the name of player two: ";
    cin >> p2;
    cin.ignore();
    
    while(p1Location < WIN_SQUARE && p2Location < WIN_SQUARE) {
      if(p1turn && p1Location != WIN_SQUARE && p2Location != WIN_SQUARE) {
        p1Location = takeTurn(p1Location, p1);
        p1turn = false;
      } else {
        p2Location = takeTurn(p2Location, p2);
        p1turn = true;
      }
    } 

    if(p1Location == WIN_SQUARE) {
      cout << p1 << " is on square 100 and has won!";
    } else if (p2Location == WIN_SQUARE) {
      cout << p2 << " is on square 100 and has won!";
    }

    cout << "\n";
    cout << "Do you want to play again (y/n)?";
    cin >> answer;
    cout << "\n\n";
  } 
  
  goodbye();
  return 0;

} //end main

void welcome() {
  cout << "\n\n";
  cout << "Welcome to Chutes and Ladders! \n";
  cout << "This is a two-player game where each player will spin for \n";
  cout << "their turn and try to get to the winning square of 100.\n";
  cout << "\n";
}

int spin() {
  return (rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN;
}

int takeTurn(int location, string p1) {
  int newSpin = location;
  int currentSquare = 0;
  cout << "\n";
  cout << p1 << " is currently on square " << location << "\n";
  cout << p1 << ", press enter to spin the wheel...";
  cin.get();
  
  newSpin = spin();
  
  if(location + newSpin <= WIN_SQUARE) {
    location = location + newSpin;
    cout << "You spun " << newSpin << "\n";
    cout << "You are now currently on square " << location << "\n";
  } else {
    cout << "You spun " << newSpin << "\n";
    cout << "You need a lower spin to move up." << "\n";
  }
  if(location < WIN_SQUARE) {
    cout << "Press enter to continue...";
    cin.get();
    currentSquare = checkLocation(location);
    location += currentSquare;
    if(currentSquare < 0){
      cout << "You have reached a chute. \n";
      cout << "You are currently now on space " << location << "\n";
    } else if (currentSquare > 0){
      cout << "You have reached a ladder. \n";
      if(location > WIN_SQUARE) {
        cout << "You have won the game! \n";
        location = WIN_SQUARE;
        return location;;
      }else{
        cout << "You are currently now on space " << location << "\n";
      }
    }else{
      cout << "You have landed or neither a chute nor a ladder. \n";
    }
  }
  
  return location;
}

int checkLocation(int location) {
  if(location == 1) {
    return 37;
  } else if(location == 4) {
    return 4;
  } else if(location == 9) {
    return 12;
  } else if(location == 23) {
    return 21;
  } else if(location == 28) {
    return 56;
  } else if(location == 36) {
    return 8;
  } else if(location == 51) {
    return 5;
  } else if(location == 71) {
    return 19; 
  } else if(location == 80) {
    return 20;
  } else if(location == 98) {
    return -20;
  } else if (location == 95){
    return -20;
  } else if(location == 93) {
    return -20;
  } else if (location == 87) { 
    return -63;
  } else if (location == 64) {
    return -4;
  } else if(location == 62) {
    return -43;
  } else if(location == 56) {
    return -3;
  } else if(location == 49) {
    return -38;
  } else if(location == 48) {
    return -22;
  } else if(location == 16) {
    return -10;
  } 
  return 0;
}

void pPosition(string p1, string p2, int p1Location, int p2Location) {
  cout << "\n";
  cout << p1 << " is currently at square " << p1Location << "\n";
  cout << p2 << " is currently at square " << p2Location << "\n";
  cout << "\n";
}

void goodbye() {
  cout << "\n";
  cout << "Thank you for playing! Have a nice day! \n";
  cout << "\n";
}
