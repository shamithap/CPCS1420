//Shamitha Pichika
//lab14.cpp
//11/21/2022

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Person
{
  string name;
  int age;
  int coffee;
  
};

const string F_NAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";
const int MAX = 150;
const int AGE_FIELD = 4;
const int COFFEE_FIELD = 4;
const int RECORD_MAX = 150;
const int NAME_FIELD = 15;

void printOne(Person p);

double averageAge(const Person list[], int numElements);

int totalCoffee(const Person list[], int numElements);

int main()
{
  Person clients[MAX];
  int count = 0; //index
  ifstream infile;
  
  cout << "\n\n";
  
  infile.open(F_NAME);
  if(infile.fail()) {
    cout << "File failure... exiting program... press enter";
    cin.get();
    return 0;
  }
  
  while(infile >> clients[count].name) {
    infile >> clients[count].age >> clients[count].coffee;
    count++;
  }

  cout << "Name..........Age..Coffee...\n";
  for(int i = 0; i < count; i++) {
    printOne(clients[i]);
  }
  cout << "\n";
  cout << "Average age: " << averageAge(clients, count);
  cout << "\n\n";
  cout << "Total coffee: " << totalCoffee(clients, count) << " cups \n";
  cout << "\n\n";
  
  return 0;
  
}

void printOne(Person p)
{
  cout << left << setw(NAME_FIELD) << p.name << setw(AGE_FIELD) << p.age << setw(COFFEE_FIELD) << p.coffee;
  cout << "\n";
}


double averageAge(const Person list[], int numElements)
{
  double total = 0;

  for(int i = 0; i < numElements; i++) {
    total += list[i].age;
  }
  return (total/numElements);
}

int totalCoffee(const Person list[], int numElements)
{
  int total = 0;
  for(int i = 0; i < numElements; i++) {
    total += list[i].coffee;
  }
  return total;
}
