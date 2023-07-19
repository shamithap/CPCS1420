//Shamitha Pichika
//lab2.cpp
//09/28/2022

#include <iostream>
using namespace std;

int main()
  {
   string ans1;
   int int1, int2;
   double double1, double2;
   
   cout << "Welcome to the Input and Output Program!\n";
   cout << "\n";
   cout << "Please enter in a word: ";
   cin >> ans1;
   cout << "\n";
   cout << "Wonderful! You have entered: " << ans1 << "\n";
   cout << "\n";
   cout << "Now please give me an integer: ";
   cin >> int1;
   cout << "\n";
   cout << "Give me another integer: ";
   cin >> int2;
   cout << "\n";
   cout << "Beautiful! \n";
   cout << "\n";
   cout << "The quotient value of the integers is " << int1/int2 << "\n"
     "and the remainder value is " << int1 % int2 << "\n";
   cout << "\n";
   cout << "Enter in a decimal value: ";
   cin >> double1;
   cout << "\n";
   cout << "Enter in another decimal value: ";
   cin >> double2;
   cout << "\n";
   cout << "The quotient values of these two decimals is\n"
        << double1/double2 << "\n";
   cout << "\n";
   cout << "Thank you for tuning in! Have a nice day.\n";

   return 0;

  }

   
