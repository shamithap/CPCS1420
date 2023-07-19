//Shamitha Pichika
//p5.cpp
//12/01/2022
//Purpose: this programs uses arrays and structures to create a Monopoly
//based off a college campus 
//Input: a file is used to extract the location names, cost and rent amount and
//the players are asked for their names 
//Process: The user will spin their turn and move that many spaces on the 
//game board they will need to attempt to make the most money while 
//bankrupting another player to win
//Output: Tells user their spin result, any money gained, and it they want to 
//purchase the list property 
//Example: "You landed on Bannan! Would you like to purchase?...."

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;

const string F_NAME = "/home/fac/sreeder/class/cs1420/p5input.dat"; //file info
const string CHANCE = "Chance"; //constant for chance card
const string INCOME_TAX = "Income Tax"; //income tax
const string FEES = "Fees"; //fee charges
const string CHAPEL = "Chapel of St. Ignatius"; //for the chapel property
const int START_MONEY = 1500; //amount each player begins with 
const int START_SPACE = 0; //starting space on game board
const int MAX_PLAY = 6;  //max player number
const int MIN_PLAY = 2; //min player number
const int MAX_PLACES = 45; //max properties
const int MAX_SPIN = 6; //max die roll
const int MIN_SPIN = 1; //min die roll
const char YES = 'y'; //asks if user wants to play again 

struct Player {
  string name;
  int position;
  int balance;
};

struct Location {
  string name;
  int cost;
  int rent;
  int owner;
};

void welcome(); //print welcome message

bool checkMoney(Player players[], int numPlayers); 
//checks to see if the player has lost all their money 

int spin(); //generates random number for dice

void takeTurn(Player players[], int activePlayer,
              Location locations[], int numLocations);
              //take turn for each user

void checkLocation(Player players[], int activePlayer,
                   Location locations[], int numLocations);
                   //checks where player is on board

void goodbye(); //print goodbye message

int main()
{
  srand(time(0));
  char answer = YES;
  ifstream infile;
  Player players[MAX_PLAY];
  Location locations[MAX_PLACES];
  int activePlayer;
  int numPlayers;
  int locationsCount = 0;
  int winner;
  infile.open(F_NAME.c_str());
  if(infile.fail()){
    cout << "File error, exiting program..\n";
    cin.ignore();
    return 0;
  }
  
  while(locationsCount < MAX_PLACES && 
        getline(infile, locations[locationsCount].name)) {
    infile >> locations[locationsCount].owner;
    infile.ignore();
    infile >> locations[locationsCount].cost;
    infile.ignore();
    infile >> locations[locationsCount].rent;
    infile.ignore();
    locationsCount++;
  }
  welcome();
  cout << "\n";
  while(tolower(answer) == YES) {
    winner = 1;
    numPlayers = 0;
    activePlayer = 1;
    while(numPlayers < MIN_PLAY || numPlayers > MAX_PLAY - 1) {
      cout << "\n";
      cout << "How many players are there? (" << MIN_PLAY << " to " << MAX_PLAY << "):";
      cin >> numPlayers;
      cin.ignore();
    }
    for(int count = 1; count <= numPlayers; count++) {
      cout << "Enter the name of player " << count << " : ";
      cin >> players[count].name;
      cin.ignore();
      players[count].balance = START_MONEY;
      players[count].position = START_SPACE;
    }
    cout << "\n";
    
    while(!checkMoney(players, numPlayers)) {
      takeTurn(players, activePlayer, locations, locationsCount);
      activePlayer++;
      if(activePlayer > numPlayers) {
        activePlayer = 1;
      }
    }
    cout << "One person lost all their money! \n";
    cout << "Game over!"; 
    cout << "\n"; 
    
    for(int i = 2; i < numPlayers; i++){ 
      if(players[winner].balance < players[i].balance) {
        winner = i;
      }
    }
    cout << players[winner].name << " won the game! \n";
    cout << "They earned a total of " << players[winner].balance << "\n";
    cout << "\n";
    cout << "Would you like to play again?(y/n): ";
    cin >> answer;
  }
  
  goodbye();
  
  return 0;
} //end main

void welcome() 
{
  cout << "\n\n";
  cout << "Welcome to Monopoly at Seattle University! \n";
  cout << "You will compete with your opponents to earn the most most \n";
  cout << "Win the game by making another player go bankrupt \n";
  cout << "and by having the most money. Good luck! \n";
  cout << "\n";
} 


int spin() {
  return (rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN;
}

void takeTurn(Player players[], int activePlayer,
              Location locations[], int numLocations)
{
  int spin1 = spin();
  int spin2 = spin();
  string name = players[activePlayer].name;
  int position = players[activePlayer].position;
  int newPosition = position + spin1 + spin2;
  cout << "It is " << name << "'s turn.\n";
  cout << "They have $" << players[activePlayer].balance << " in the bank.\n";
  cout << name << " is on space " << position << ".\n";
  cout << name << " spins a " << spin1 << " and a " << spin2
       << " for a total of " << spin1 + spin2 << "\n";
  if(newPosition >= numLocations){
    newPosition = newPosition - numLocations;
    cout << name << " passed GO and collected $200!\n";
    players[activePlayer].balance += 200;
  }
  cout << name << " is now on space " << newPosition << ".\n";
  players[activePlayer].position = newPosition;
  checkLocation(players, activePlayer, locations, numLocations);
  cout << "This turn is now over.. \n";
  cout << "Press ENTER to continue..\n";
  cin.ignore();
  cout << "\n";
}



bool checkMoney(Player players[], int numPlayers)
{
  bool broke = false;
  for(int i = 1; i <= numPlayers; i++){
    if(players[i].balance <= 0){
      broke = true;
    }
  }
  return broke;
}

void checkLocation(Player players[], int activePlayer,
                   Location locations[], int numLocations)
{
  int position = players[activePlayer].position;
  cout << "The player is at " << locations[position].name << ".\n";
  if(locations[position].owner == -1){
    cout << "This location cannot be owned.\n";
    if(locations[position].name == INCOME_TAX ||
       locations[position].name == FEES){
      cout << "The player has " << locations[position].rent
           << " deducted from their balance.\n";
      players[activePlayer].balance -= locations[position].rent;
      cout << "Their new balance is $" << players[activePlayer].balance
           << ".\n";
    } else if(locations[position].name == CHANCE){
      int chance = spin();
      if(chance < 4){
        cout << "The player spinned a " << chance
             << " and had $50 added to their balance!\n";
        players[activePlayer].balance += 50;
      } else {
        cout << "The player spinned a " << chance
             << " and was sent to the Chapel!\n";
        for(int i = 0; i<numLocations; i++){
          if(locations[i].name == CHAPEL){
            players[activePlayer].position = i; 
          }
        }
      }
    }
  }else if(locations[position].owner == 0){
    char answer2;
    cout << "This space is unowned and can be bought by the player.\n";
    cout << "This space costs $" << locations[position].cost << "\n";
    cout << "The rent for this space is $" << locations[position].rent << "\n";
    cout << "Would the player like to purchase this space? (y/n): ";
    cin >> answer2;
    if(tolower(answer2) == YES){
      cout << "The player chose to buy the space!\n";
      players[activePlayer].balance -= locations[position].cost;
      locations[position].owner = activePlayer;
      cout << "The player's new balance is "
           << players[activePlayer].balance << "\n";
    }else{
      cout << "The location was not bought.. \n";
    }
  }else if(locations[position].owner != activePlayer){
    Player owner = players[locations[position].owner];
    cout << "This space is owned by " << owner.name << "\n";
    cout << "The rent for this space is $" << locations[position].rent << "\n";
    cout << "The player has the rent deducted from their balance\n";
    players[activePlayer].balance -= locations[position].rent;
    players[locations[position].owner].balance += locations[position].rent;
    cout << owner.name << " gains $" << locations[position].rent << "\n";
    cout << "Their new balance is " << players[activePlayer].balance << "\n";
  }else{
    cout << "This space is already owned \n";
  }
}

void goodbye() 
{
  cout << "\n\n";
  cout << "Thank you for playing! \n";
  cout << "Have a nice day! \n";
  cout << "\n\n";
}
