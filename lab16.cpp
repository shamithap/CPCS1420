//Shamitha Pichika
//lab16.cpp
//11/30/2022

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


double averageAge(const Person list[], int numElements);

int totalCoffee(const Person list[], int numElements);

void printOne(Person p);

void selectionSort(Person list[], int num);

void swap(Person& num1, Person& num2);

Person leastCoffee(const Person list[], int numElements);

Person oldestPerson(const Person list[], int numElements);



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
  cout << "Least Coffee: ";
  printOne(leastCoffee(clients, count));
  cout << "\n\n";
  cout << "Oldest person: ";
  printOne(oldestPerson(clients, count));
  cout << "\n\n";
  cout << "In alphabetical order :";
  cout << "\n";
  
  selectionSort(clients, count);
  
  for(int i = 0; i < count; i++) {
    printOne(clients[i]);
    cout << "\n";
  }
  
  return 0;
  
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

void printOne(Person p)
{
  cout << setw(NAME_FIELD) << p.name << setw(AGE_FIELD) << 
    p.age << setw(COFFEE_FIELD) << p.coffee;
  cout << "\n";
}

void selectionSort(Person list[], int num)
{
  int count = 0;
  for(int i = 0; i < num; i++) {
    count = i;
    for(int j = (i + 1); j < num; j++) {
      if(list[j].name < list[count].name) {
        count = j;
      }
    }
    if(count != i) {
      swap(list[count], list[i]);
      cout << "swapped!" << endl;
    }
  }
}

void swap(Person& num1, Person& num2)
{
  Person temp = num1;
  num1 = num2;
  num2 = temp;
}

Person leastCoffee(const Person list[], int numElements)
{
  int counter = 0;
  for(int i = 0; i < numElements; i++) {
    if(list[i].coffee < list[counter].coffee) {
      counter = i;
    }
  }
  return list[counter];
}

Person oldestPerson(const Person list[], int numElements)
{
  int count = 0;
  for(int i = 0; i < numElements; i++) {
    if(list[i].age > list[count].age) {
      count = i;
    }
  }
  return list[count];
}

