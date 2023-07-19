//Shamitha Pichika
//p2.cpp
//10/20/2022
//Purpose: The program asks the users for their names and 
//outputs a spin result based on a random number
//Input: player one name and player two name
//Process: Takes inputs (names) from the users and outputs the 
//value of the baskets based on a random number spinner
//Output: Users' names, spin result, and updated basket value
//Example: p1: Sam, p2: Sarah, result: The Dog stole two 
//cherries, p1 now has x cherries...

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  int spin1; //player one spin
  int spin2; //player two spin
  const int MIN = 1; //minimum rnadom num
  const int MAX = 7; //maximum random num
  const int ONE_CHERRY_REMOVE = 1; //when players spins one
  const int TWO_CHERRY_REMOVE = 2; //when players spins two
  const int BUCKET_SPILL = 3; //when players spins three
  const int FOUR_CHERRY_REMOVE = 4; //when players spins four
  const int DOG_STEAL = 5; //when players spins five
  const int THREE_CHERRY_REMOVE = 6; //when players spins six 
  const int BIRD_STEAL = 7; //when players spins seven
  const int CHERRIES_NEEDED = 10; //max cherries
  string p1; //player one name
  string p2; //player two name
  int treeCherries1; //player one cherries on trees
  int treeCherries2;//player two cherries on trees
  int basket1 = 0; //player one bucket
  int basket2 = 0;//player two bucket

  srand(time(0)); //random num generator
  
  cout << "\n\n\n";
  cout << "Welcome to Hi-Ho Cherry-O Game!\n"; //welcome statement
  cout << "This is a two-player game where each player will spin for their\n";
  cout << "turn\n";
  cout << "\n";
  cout << "Please enter player one's name: ";
  cin >> p1;
  cout << "\n";
  cout << "Please enter player two's name: ";
  cin >> p2;
  cout << "\n";

  while(basket1 < CHERRIES_NEEDED && basket2 < CHERRIES_NEEDED) {
    spin1 = (rand() % (MAX - MIN + 1))+ MIN;
    spin2 = (rand() % (MAX - MIN + 1))+ MIN;
    cout << "\n";

    for(int player = 1; player <= 2; player++) {
      if(player == 1) { //player one case
        cout << "\n";
        cout << p1 << ", press ENTER to spin the wheel...";
        cin.get();
        //cin.get(); //bottom cin.get();

        switch (spin1) {
        case ONE_CHERRY_REMOVE:
          treeCherries1--;
          basket1++;
          if(basket1 > CHERRIES_NEEDED){
            basket1 = CHERRIES_NEEDED;
          }
          cout << "One cherry was removed from " << p1 << "'s tree!\n";
          cout << p1 << " now has " << basket1 << " cherries in the basket!";
          break;
        case TWO_CHERRY_REMOVE:
          treeCherries1 -= 2;
          basket1 += 2;
          if(basket1 > CHERRIES_NEEDED){
            basket1 = CHERRIES_NEEDED;
          }
          cout << "Two cherries were removed from " << p1 << "'s tree!\n";
          cout << p1 << " now has " << basket1 << " cherries in the basket!";
          break;
        case BUCKET_SPILL:
          treeCherries1 = CHERRIES_NEEDED;
          basket1 = 0;
          cout << "Oh no! The basket was spilled!\n";
          cout << p1 << " now has 0 cherries in their basket.";
          break;
        case FOUR_CHERRY_REMOVE:
          treeCherries1 = treeCherries1 - 4;
          basket1 += 4;
          if(basket1 > CHERRIES_NEEDED){
            basket1 = CHERRIES_NEEDED;
          }
          cout << "Four cherries were removed from " << p1 << "'s tree!\n";
          cout << p1 << " now has " << basket1 << " cherries in the basket!";
          break;
        case DOG_STEAL:
          if(basket1 >= 2) {
            treeCherries1 += 2;
            basket1 -= 2;
            if(basket1 < 0) {
              basket1 = 0;
            }
            cout << "Oh no! The dog stole 2 cherries!\n";
            cout << p1 << " now has " << basket1 << " cherries in the basket!";
          } else if (basket1 == 1) {
            treeCherries1++;
            basket1--;
            treeCherries1 = CHERRIES_NEEDED;
            cout << "Oh no! The dog stole 1 cherry!\n";
            cout << p1 << " now has " << basket1 << " cherries in the basket!";
          } else {
            cout << "The dog tried to steal cherries but couldn't!\n";
            cout << p1 << " has 0 cherries in their basket.";
          }
          break;
        case THREE_CHERRY_REMOVE:
          treeCherries1 -= 3;
          basket1 += 3;
          if(basket1 > CHERRIES_NEEDED){
            basket1 = CHERRIES_NEEDED;
          }
          cout << "Three cherries were removed from " << p1 << "'s tree!\n";
          cout << p1 << " now has " << basket1 << " cherries in the basket!";
          break;
        case BIRD_STEAL:
          if(basket1 >= 2) {
            treeCherries1 += 2;
            basket1 -= 2;
            cout << "Oh no! The dog stole 2 cherries!\n";
            cout << p1 << " now has " << basket1 << " cherries in the basket!";
          } else if (basket1 == 1) {
            treeCherries1++;
            basket1--;
            cout << "Oh no! The dog stole 1 cherry!\n";
            cout << p1 << " now has " << basket1 << " cherries in the basket!";
          } else {
            cout << "The dog tried to steal cherries but couldn't!";
            cout << "\n";
            cout << p1 << " still has 0 cherries in their basket.";
          }
          break;
        }
        if(basket1 == CHERRIES_NEEDED) {
          cout << "\n";
          cout << p1 << " wins!";
        }

      } else { //player two case

        cout << "\n\n";
        cout << p2 << ", press ENTER to spin the wheel...";
        cin.get();

        switch (spin2) {
        case ONE_CHERRY_REMOVE:
          treeCherries2--;
          basket2++;
          if(basket2 > CHERRIES_NEEDED){
            basket2 = CHERRIES_NEEDED;
          }
          cout << "One cherry was removed from " << p2 << "'s tree!\n";
          cout << p2 << " now has " << basket2 << " cherries in the basket!";
          break;
        case TWO_CHERRY_REMOVE:
          treeCherries2 -= 2;
          basket2 += 2;
          if(basket2 > CHERRIES_NEEDED){
            basket2 = CHERRIES_NEEDED;
          }
          cout << "Two cherries were removed from " << p2 << "'s tree!\n";
          cout << p2 << " now has " << basket2 << " cherries in the basket!";
          break;
        case BUCKET_SPILL:
          basket2 = 0;
          cout << "Oh no! The basket was spilled!\n";
          cout << p2 << " now has 0 cherries in their basket.";
          break;
        case FOUR_CHERRY_REMOVE:
          treeCherries2 -= 4;
          basket2 += 4;
          if(basket2 > CHERRIES_NEEDED){
            basket2 = CHERRIES_NEEDED;
          }
          cout << "Oh no! The bucket was spilled!\n";
          cout << p2 << " now has " << basket2 << " cherries in the basket!";
          break;
        case DOG_STEAL:
          if(basket2 >= 2) {
            treeCherries2 += 2;
            basket2 -= 2;
            cout << "Oh no! The dog stole 2 cherries!\n";
            cout << p2 << " now has " << basket2 << " cherries in the basket!";
          } else if (basket2 == 1) {
            treeCherries2++;
            basket1--;
            cout << "Oh no! The dog stole 1 cherry!\n";
            cout << p2 << " now has " << basket2 << " cherries in the basket!";
          } else {
            cout << "The dog tried to steal cherries but couldn't!\n";
            cout << p2 << " has 0 cherries in their basket.";
          }
          break;
        case THREE_CHERRY_REMOVE:
          treeCherries2 -= 3;
          basket2 += 3;
          if(basket2 > CHERRIES_NEEDED){
            basket2 = CHERRIES_NEEDED;
          }
          cout << "Three cherries were removed from " << p2 << "'s tree!\n";
          cout << p2 << " now has " << basket2 << " cherries in the basket!";
          break;
        case BIRD_STEAL:
          if(basket2 >= 2) {
            treeCherries2 += 2;
            basket2 -= 2;
            cout << "Oh no! The dog stole 2 cherries!\n";
            cout << p2 << " now has " << basket2 << " cherries in the basket!";
          } else if (basket2 == 1) {
            treeCherries2++;
            basket2--;
            cout << "Oh no! The dog stole 1 cherry!\n";
            cout << p2 << " now has " << basket2 << " cherries in the basket!";
          } else {
            cout << "The dog tried to steal cherries but couldn't!";
            cout << "\n";
            cout << p2 << "has 0 cherries in their basket.";
          }
          break;
        }

        if(basket2 == CHERRIES_NEEDED) {
          cout << "\n";
          cout << p2 << " wins!";
        }
      }
    }
  }

  cout << "\n\n";
  cout << "Thank you for playing!"; //closing statement
  cout << "\n\n";

  return 0; 

}//end program

