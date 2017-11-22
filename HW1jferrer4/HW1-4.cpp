#include <iostream>
#include <stdlib.h>
#include "vector"

using namespace std;

class Team{
private:
  string teamName;
  unsigned int wins;
  unsigned int loses;

public:
  Team(string name, unsigned int w, unsigned int l){
    teamName = name;
    wins = w;
    loses = l;
  }

  string getTeamName(){
    return teamName;
  }

  void setTeamName(string name){
    teamName = name;
  }

  unsigned int getWins(){
    return wins;
  }

  void setWins(int w){
    wins = w;
  }

  unsigned int getLoses(){
    return loses;
  }

  void setLoses(int l){
    loses = l;
  }

  friend bool operator<=(const Team &t1, const Team &t2);

};

bool operator<=(const Team &t1, const Team &t2){
  double per1 = ((double)(t1.wins) / (double)(t1.wins + t1.loses));
  double per2 = ((double)(t2.wins) / (double)(t2.wins + t2.loses));

  //cout << per1 << " " << per2 << endl;
  //cout << (per1 <= per2) << endl;

  return per1 <= per2;
}

template <class T>
vector<T> merge(vector<T> left, vector<T> right){
  vector<T> retVect;
  while(!left.empty() && !right.empty()){
    if(left.front() <= right.front()){
      retVect.push_back(left.front());
      left.erase(left.begin());
    } else{
      retVect.push_back(right.front());
      right.erase(right.begin());
    }
  }

  while(!left.empty()){
    retVect.push_back(left.front());
    left.erase(left.begin());
  }
  while(!right.empty()){
    retVect.push_back(right.front());
    right.erase(right.begin());
  }

  return retVect;
}

template <class T>
vector<T> mergeSort(vector<T> sortVect){
  vector<T> leftHalf;
  vector<T> rightHalf;
  if(sortVect.size() == 0 || sortVect.size() == 1){
    return sortVect;
  }
  bool alter = true;
  for(typename vector<T>::iterator i = sortVect.begin(); i != sortVect.end(); i++){
    if(alter){
      //push left
      leftHalf.push_back(*i);
    } else{
      // push right
      rightHalf.push_back(*i);
    }
    //add one to the left and another one to the right
    alter = !alter;
  }

  leftHalf = mergeSort(leftHalf);
  rightHalf = mergeSort(rightHalf);
  return merge(leftHalf, rightHalf);
}

int main(int argc, char* argv[]){
  vector<Team> tmVect;

  tmVect.push_back(Team("Team Elite", 0, 9000));
  tmVect.push_back(Team("Team Smooth", 9000, 0));
  tmVect.push_back(Team("Team Lethal", 4500, 4500));
  tmVect.push_back(Team("Team Radiant", 100, 8900));
  tmVect.push_back(Team("Team Lovely", 8000, 1000));
  tmVect.push_back(Team("Team Steel", 4500, 4500));
  tmVect.push_back(Team("Team Sinverguenza", 8900, 100));

  tmVect = mergeSort(tmVect);

  vector<int> intVect;
  intVect.push_back(0);
  intVect.push_back(20);
  intVect.push_back(310);
  intVect.push_back(154);
  intVect.push_back(21);
  intVect.push_back(10);
  intVect.push_back(40);
  intVect.push_back(340);
  intVect.push_back(6537);
  intVect.push_back(468);
  intVect.push_back(12);
  intVect.push_back(2);
  intVect.push_back(64);
  intVect.push_back(8);
  intVect.push_back(982);

  intVect = mergeSort(intVect);


  for(vector<Team>::iterator i = tmVect.begin(); i != tmVect.end(); i++){
    cout << i->getTeamName() << " " << ((double)(i->getWins()) / (double)(i->getWins() + i->getLoses())) << endl;
  }


  for(vector<int>::iterator i = intVect.begin(); i != intVect.end(); i++){
    cout << *i << endl;
  }


  return 0;
}










////////////////
