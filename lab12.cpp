//Shamitha Pichika
//lab12.cpp
//11/09/2022

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const string F_NAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";
const int MAX = 50;

void printArray(const double numArray[], int nums); 

double total(const double numArray[], int nums);

int readFile(double numArray[]); 

int main() 
{
  ifstream infile;
  int counter;
  double list[MAX] = {0};
  cout << "\n" << "\n";
  counter = readFile(list);
  if(counter == 0) {
    cout << "File failure... exiting program... press enter";
    cin.get();
    return 0;
  }

  printArray(list, counter);
  cout << "\n";
  cout << "Sum of values: " << total(list, counter);
  cout << "\n\n";
  return 0;
  
}

void printArray(const double numArray[], int nums)
{
  const int INDEX_COL = 5;
  const int NUM_COL = 8;
  const int DIGITS = 3;
  
  cout << setw(INDEX_COL) << "Index:" << setw(NUM_COL) << " Value: \n";
  for(int i = 0; i < nums; i++) {
    cout << setw(INDEX_COL) << i << setw(NUM_COL) << fixed << showpoint
         << setprecision(DIGITS) << numArray[i] << "\n";
  }
}

double total(const double numArray[], int nums)
{
  double sum = 0;
  for(int i = 0; i < nums; i++)
    sum = sum + numArray[i];

  return sum;
}
    
int readFile(double numArray[])
{
  int num = 0;
  ifstream infile;
  infile.open(F_NAME);
  while(infile >> numArray[num]) {
    num++;
  }
  infile.close();
  return num;
}
