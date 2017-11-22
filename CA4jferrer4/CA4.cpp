#include <iostream>
#include <stdlib.h>
#include "Dish.h"
#include "string"
#include "vector"

using namespace std;

int main(int argc, char* argv[]){
  //cout << "Starting up" << endl;
  Dish* myDish = new Dish();
  //cout << "before inserting" << endl;
  myDish->insert("A This is a string");
  myDish->insert("B this is a longer string");
  myDish->insert("C This is a even longer string");
  myDish->insert("D This is the longest string there is");
  myDish->insert("string");
  myDish->insert("Watagatapitusberry");
  myDish->insert("E What");
  myDish->insert("F Yo");
  myDish->insert("G Yaaaaaaaaassssssssssssss");
  myDish->insert("H Ju hurddd");
  myDish->insert("I What kind of string is this?");
  //cout << "after inserting" << endl;

  cout << "Find string: " << myDish->find("string") << endl;
  cout << "first string: " << myDish->getfirst() << endl;
  myDish->capitalize(myDish->find("string"));
  cout << "Capitalize string: " << myDish->find("String") << endl;
  myDish->allcaps(myDish->find("String"));
  cout << "Allcaps string: " << myDish->find("STRING") << endl;
  myDish->truncate(5, 8);
  cout << "Print Watagata location: " << myDish->find("Watagata") << endl;
  cout << "shortest string: " << myDish->getshortest() << endl;
  cout << "first string: " << myDish->getfirst() << endl;

  for(int i = 0; i < 11; i++){
    cout << myDish->getStringArr()[myDish->getLenArr()[i]] << endl;
  }
}
